// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestDefinition.h"
#include "GameplayObjectiveDefinition.h"
#include "GameplayQuestEventSubsystem.h"
#include "GameplayQuestDataSubsystem.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestModule.h"
#include "GameplayQuestSettings.h"
#include "Net/UnrealNetwork.h"
#include "Serialization/MemoryWriter.h"
#include "Serialization/MemoryReader.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UGameplayQuestManagerComponent::UGameplayQuestManagerComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
	PrimaryComponentTick.bStartWithTickEnabled = false;
	SetIsReplicatedByDefault(true);

	ActiveQuestList.OwnerComponent = this;
}

void UGameplayQuestManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	ActiveQuestList.OwnerComponent = this;

	// On Server, register all existing active quest objectives to the world event subsystem
	if (GetOwner() && GetOwner()->HasAuthority())
	{
		for (const FGameplayQuestRecord& Record : ActiveQuestList.Items)
		{
			if (UGameplayQuestDefinition* QuestDef = ResolveQuestDefinition(Record.QuestTag))
			{
				RegisterObjectivesWithEventBus(Record, QuestDef);
			}
		}
	}
}

void UGameplayQuestManagerComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UWorld* World = GetWorld())
	{
		if (UGameplayQuestEventSubsystem* EventSubsystem = World->GetSubsystem<UGameplayQuestEventSubsystem>())
		{
			EventSubsystem->UnregisterAllForListener(this);
		}
	}

	Super::EndPlay(EndPlayReason);
}

void UGameplayQuestManagerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UGameplayQuestManagerComponent, ActiveQuestList);
	DOREPLIFETIME(UGameplayQuestManagerComponent, CompletedQuestTags);
	DOREPLIFETIME(UGameplayQuestManagerComponent, FailedQuestTags);
}

bool UGameplayQuestManagerComponent::AcceptQuest(UGameplayQuestDefinition* QuestDefinition)
{
	if (!QuestDefinition || !QuestDefinition->QuestTag.IsValid())
	{
		return false;
	}

	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return false;
	}

	const FGameplayTag& QuestTag = QuestDefinition->QuestTag;

	// Check if already active, completed, or failed
	if (IsQuestActive(QuestTag) || IsQuestCompleted(QuestTag) || IsQuestFailed(QuestTag))
	{
		return false;
	}

	// Max active quests limit check from settings
	const UGameplayQuestSettings* Settings = UGameplayQuestSettings::Get();
	if (Settings && ActiveQuestList.Items.Num() >= Settings->MaxActiveQuestsPerPlayer)
	{
		UE_LOG(LogGameplayQuest, Warning, TEXT("Cannot accept quest %s: Reached MaxActiveQuestsPerPlayer (%d)"),
			*QuestTag.ToString(), Settings->MaxActiveQuestsPerPlayer);
		return false;
	}

	// Add record to FastArray
	FGameplayQuestRecord* NewRecord = ActiveQuestList.AddQuestRecord(
		QuestTag,
		GameplayQuestTags::TAG_Quest_Status_Active_InProgress.GetTag(),
		0
	);

	if (!NewRecord)
	{
		return false;
	}

	RegisterRuntimeQuestDefinition(QuestDefinition);

	// Initialize Stage 0 objectives
	SetupStageObjectives(*NewRecord, QuestDefinition, 0);

	// Register with event subsystem
	RegisterObjectivesWithEventBus(*NewRecord, QuestDefinition);

	UE_LOG(LogGameplayQuest, Log, TEXT("Accepted Quest: %s on %s"), *QuestTag.ToString(), *GetOwner()->GetName());

	// Broadcast local delegates
	OnQuestStatusChanged.Broadcast(
		QuestTag,
		GameplayQuestTags::TAG_Quest_Status_Active_InProgress.GetTag(),
		GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag()
	);
	OnQuestStatusChangedNative.Broadcast(
		QuestTag,
		GameplayQuestTags::TAG_Quest_Status_Active_InProgress.GetTag(),
		GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag()
	);
	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();

	return true;
}

bool UGameplayQuestManagerComponent::AdvanceObjectiveProgress(const FGameplayTag& QuestTag, const FGameplayTag& ObjectiveTag, int32 ProgressAmount)
{
	if (!QuestTag.IsValid() || !ObjectiveTag.IsValid() || ProgressAmount <= 0)
	{
		return false;
	}

	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return false;
	}

	FGameplayQuestRecord* QuestRecord = ActiveQuestList.FindQuestRecord(QuestTag);
	if (!QuestRecord)
	{
		return false;
	}

	FGameplayObjectiveRecord* ObjRecord = QuestRecord->FindObjectiveRecord(ObjectiveTag);
	if (!ObjRecord || ObjRecord->IsCompleted())
	{
		return false;
	}

	ObjRecord->CurrentProgress = FMath::Clamp(ObjRecord->CurrentProgress + ProgressAmount, 0, ObjRecord->RequiredCount);
	if (ObjRecord->IsCompleted())
	{
		ObjRecord->StatusTag = GameplayQuestTags::TAG_Quest_Objective_Status_Completed.GetTag();
	}

	ActiveQuestList.MarkQuestDirty(*QuestRecord);

	// Fire delegate
	OnObjectiveProgressChanged.Broadcast(QuestTag, ObjectiveTag, ObjRecord->CurrentProgress, ObjRecord->RequiredCount);
	OnObjectiveProgressChangedNative.Broadcast(QuestTag, ObjectiveTag, ObjRecord->CurrentProgress, ObjRecord->RequiredCount);

	// Check if all stage objectives are complete
	if (QuestRecord->AreStageObjectivesCompleted())
	{
		if (UGameplayQuestDefinition* QuestDef = ResolveQuestDefinition(QuestTag))
		{
			AdvanceQuestStage(*QuestRecord, QuestDef);
		}
	}

	return true;
}

void UGameplayQuestManagerComponent::AdvanceQuestStage(FGameplayQuestRecord& QuestRecord, UGameplayQuestDefinition* QuestDef)
{
	if (!QuestDef)
	{
		return;
	}

	const int32 NextStageIndex = QuestRecord.CurrentStageIndex + 1;
	if (QuestDef->Stages.IsValidIndex(NextStageIndex))
	{
		// Unregister old objectives
		UnregisterObjectivesFromEventBus(QuestRecord, QuestDef);

		// Advance stage
		QuestRecord.CurrentStageIndex = NextStageIndex;
		SetupStageObjectives(QuestRecord, QuestDef, NextStageIndex);

		// Register new objectives
		RegisterObjectivesWithEventBus(QuestRecord, QuestDef);

		ActiveQuestList.MarkQuestDirty(QuestRecord);

		UE_LOG(LogGameplayQuest, Log, TEXT("Quest %s advanced to Stage %d"), *QuestRecord.QuestTag.ToString(), NextStageIndex);
		OnQuestListUpdated.Broadcast();
	}
	else
	{
		// All stages completed -> Ready to Turn In or auto-complete
		CompleteQuest(QuestRecord.QuestTag);
	}
}

bool UGameplayQuestManagerComponent::CompleteQuest(const FGameplayTag& QuestTag)
{
	if (!QuestTag.IsValid())
	{
		return false;
	}

	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return false;
	}

	FGameplayQuestRecord* QuestRecord = ActiveQuestList.FindQuestRecord(QuestTag);
	if (!QuestRecord)
	{
		return false;
	}

	UGameplayQuestDefinition* QuestDef = ResolveQuestDefinition(QuestTag);
	if (QuestDef)
	{
		UnregisterObjectivesFromEventBus(*QuestRecord, QuestDef);

		// Grant rewards
		for (const TObjectPtr<UGameplayQuestReward>& Reward : QuestDef->CompletionRewards)
		{
			if (Reward)
			{
				Reward->GrantReward(GetOwner());
			}
		}
	}

	const FGameplayTag OldStatus = QuestRecord->StatusTag;
	ActiveQuestList.RemoveQuestRecord(QuestTag);
	CompletedQuestTags.AddTag(QuestTag);

	UE_LOG(LogGameplayQuest, Log, TEXT("Completed Quest: %s on %s"), *QuestTag.ToString(), *GetOwner()->GetName());

	OnQuestStatusChanged.Broadcast(QuestTag, GameplayQuestTags::TAG_Quest_Status_Completed.GetTag(), OldStatus);
	OnQuestStatusChangedNative.Broadcast(QuestTag, GameplayQuestTags::TAG_Quest_Status_Completed.GetTag(), OldStatus);
	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();

	return true;
}

bool UGameplayQuestManagerComponent::FailQuest(const FGameplayTag& QuestTag, const FGameplayTag& FailureReasonTag)
{
	if (!QuestTag.IsValid())
	{
		return false;
	}

	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return false;
	}

	FGameplayQuestRecord* QuestRecord = ActiveQuestList.FindQuestRecord(QuestTag);
	if (!QuestRecord)
	{
		return false;
	}

	if (UGameplayQuestDefinition* QuestDef = ResolveQuestDefinition(QuestTag))
	{
		UnregisterObjectivesFromEventBus(*QuestRecord, QuestDef);
	}

	const FGameplayTag OldStatus = QuestRecord->StatusTag;
	ActiveQuestList.RemoveQuestRecord(QuestTag);
	FailedQuestTags.AddTag(QuestTag);

	const FGameplayTag FailStatus = FailureReasonTag.IsValid() ? FailureReasonTag : GameplayQuestTags::TAG_Quest_Status_Failed.GetTag();
	UE_LOG(LogGameplayQuest, Log, TEXT("Failed Quest: %s on %s (Reason: %s)"),
		*QuestTag.ToString(), *GetOwner()->GetName(), *FailStatus.ToString());

	OnQuestStatusChanged.Broadcast(QuestTag, FailStatus, OldStatus);
	OnQuestStatusChangedNative.Broadcast(QuestTag, FailStatus, OldStatus);
	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();

	return true;
}

bool UGameplayQuestManagerComponent::AbandonQuest(const FGameplayTag& QuestTag)
{
	if (!QuestTag.IsValid())
	{
		return false;
	}

	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return false;
	}

	FGameplayQuestRecord* QuestRecord = ActiveQuestList.FindQuestRecord(QuestTag);
	if (!QuestRecord)
	{
		return false;
	}

	if (UGameplayQuestDefinition* QuestDef = ResolveQuestDefinition(QuestTag))
	{
		UnregisterObjectivesFromEventBus(*QuestRecord, QuestDef);
	}

	const FGameplayTag OldStatus = QuestRecord->StatusTag;
	ActiveQuestList.RemoveQuestRecord(QuestTag);

	UE_LOG(LogGameplayQuest, Log, TEXT("Abandoned Quest: %s on %s"), *QuestTag.ToString(), *GetOwner()->GetName());

	OnQuestStatusChanged.Broadcast(QuestTag, GameplayQuestTags::TAG_Quest_Status_Abandoned.GetTag(), OldStatus);
	OnQuestStatusChangedNative.Broadcast(QuestTag, GameplayQuestTags::TAG_Quest_Status_Abandoned.GetTag(), OldStatus);
	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();

	return true;
}

void UGameplayQuestManagerComponent::ProcessQuestEvent(const FGameplayQuestEventPayload& Payload)
{
	if (!Payload.EventTag.IsValid())
	{
		return;
	}

	// Check all active quests for objectives that match this event
	for (FGameplayQuestRecord& Record : ActiveQuestList.Items)
	{
		UGameplayQuestDefinition* QuestDef = ResolveQuestDefinition(Record.QuestTag);
		if (!QuestDef || !QuestDef->Stages.IsValidIndex(Record.CurrentStageIndex))
		{
			continue;
		}

		const FGameplayQuestStage& Stage = QuestDef->Stages[Record.CurrentStageIndex];
		for (const TObjectPtr<UGameplayObjectiveDefinition>& ObjDef : Stage.Objectives)
		{
			if (!ObjDef || !ObjDef->ObjectiveTag.IsValid())
			{
				continue;
			}

			FGameplayObjectiveRecord* ObjRecord = Record.FindObjectiveRecord(ObjDef->ObjectiveTag);
			if (ObjRecord && !ObjRecord->IsCompleted())
			{
				if (ObjDef->MatchesEvent(Payload))
				{
					const int32 Yield = ObjDef->EvaluateProgressYield(Payload);
					AdvanceObjectiveProgress(Record.QuestTag, ObjDef->ObjectiveTag, Yield);
				}
			}
		}
	}
}

FGameplayTag UGameplayQuestManagerComponent::GetQuestStatus(const FGameplayTag& QuestTag) const
{
	if (!QuestTag.IsValid())
	{
		return GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag();
	}

	if (CompletedQuestTags.HasTag(QuestTag))
	{
		return GameplayQuestTags::TAG_Quest_Status_Completed.GetTag();
	}

	if (FailedQuestTags.HasTag(QuestTag))
	{
		return GameplayQuestTags::TAG_Quest_Status_Failed.GetTag();
	}

	if (const FGameplayQuestRecord* Record = ActiveQuestList.FindQuestRecord(QuestTag))
	{
		return Record->StatusTag;
	}

	return GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag();
}

bool UGameplayQuestManagerComponent::HasQuestStatus(const FGameplayTag& QuestTag, const FGameplayTag& StatusTag) const
{
	const FGameplayTag CurrentStatus = GetQuestStatus(QuestTag);
	return CurrentStatus.MatchesTag(StatusTag);
}

bool UGameplayQuestManagerComponent::IsQuestCompleted(const FGameplayTag& QuestTag) const
{
	return CompletedQuestTags.HasTag(QuestTag);
}

bool UGameplayQuestManagerComponent::IsQuestFailed(const FGameplayTag& QuestTag) const
{
	return FailedQuestTags.HasTag(QuestTag);
}

bool UGameplayQuestManagerComponent::IsQuestActive(const FGameplayTag& QuestTag) const
{
	return ActiveQuestList.FindQuestRecord(QuestTag) != nullptr;
}

const FGameplayQuestRecord* UGameplayQuestManagerComponent::GetActiveQuestRecord(const FGameplayTag& QuestTag) const
{
	return ActiveQuestList.FindQuestRecord(QuestTag);
}

void UGameplayQuestManagerComponent::SetupStageObjectives(FGameplayQuestRecord& QuestRecord, UGameplayQuestDefinition* QuestDef, int32 StageIndex)
{
	QuestRecord.ObjectiveRecords.Reset();

	if (!QuestDef || !QuestDef->Stages.IsValidIndex(StageIndex))
	{
		return;
	}

	const FGameplayQuestStage& Stage = QuestDef->Stages[StageIndex];
	for (const TObjectPtr<UGameplayObjectiveDefinition>& ObjDef : Stage.Objectives)
	{
		if (ObjDef && ObjDef->ObjectiveTag.IsValid())
		{
			FGameplayObjectiveRecord& ObjRec = QuestRecord.ObjectiveRecords.AddDefaulted_GetRef();
			ObjRec.ObjectiveTag = ObjDef->ObjectiveTag;
			ObjRec.StatusTag = GameplayQuestTags::TAG_Quest_Objective_Status_Active.GetTag();
			ObjRec.CurrentProgress = 0;
			ObjRec.RequiredCount = FMath::Max(1, ObjDef->RequiredCount);
		}
	}
}

void UGameplayQuestManagerComponent::RegisterObjectivesWithEventBus(const FGameplayQuestRecord& QuestRecord, UGameplayQuestDefinition* QuestDef)
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	UGameplayQuestEventSubsystem* EventSubsystem = World->GetSubsystem<UGameplayQuestEventSubsystem>();
	if (!EventSubsystem || !QuestDef || !QuestDef->Stages.IsValidIndex(QuestRecord.CurrentStageIndex))
	{
		return;
	}

	const FGameplayQuestStage& Stage = QuestDef->Stages[QuestRecord.CurrentStageIndex];
	for (const TObjectPtr<UGameplayObjectiveDefinition>& ObjDef : Stage.Objectives)
	{
		if (ObjDef)
		{
			const FGameplayTag Channel = ObjDef->GetEventChannelTag();
			if (Channel.IsValid())
			{
				EventSubsystem->RegisterEventListener(Channel, this);
			}
		}
	}
}

void UGameplayQuestManagerComponent::UnregisterObjectivesFromEventBus(const FGameplayQuestRecord& QuestRecord, UGameplayQuestDefinition* QuestDef)
{
	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	UGameplayQuestEventSubsystem* EventSubsystem = World->GetSubsystem<UGameplayQuestEventSubsystem>();
	if (!EventSubsystem || !QuestDef || !QuestDef->Stages.IsValidIndex(QuestRecord.CurrentStageIndex))
	{
		return;
	}

	const FGameplayQuestStage& Stage = QuestDef->Stages[QuestRecord.CurrentStageIndex];
	for (const TObjectPtr<UGameplayObjectiveDefinition>& ObjDef : Stage.Objectives)
	{
		if (ObjDef)
		{
			const FGameplayTag Channel = ObjDef->GetEventChannelTag();
			if (Channel.IsValid())
			{
				EventSubsystem->UnregisterEventListener(Channel, this);
			}
		}
	}
}

void UGameplayQuestManagerComponent::RegisterRuntimeQuestDefinition(UGameplayQuestDefinition* QuestDef)
{
	if (QuestDef && QuestDef->QuestTag.IsValid())
	{
		RuntimeQuestDefinitions.FindOrAdd(QuestDef->QuestTag) = QuestDef;
	}
}

UGameplayQuestDefinition* UGameplayQuestManagerComponent::ResolveQuestDefinition(const FGameplayTag& QuestTag) const
{
	if (!QuestTag.IsValid())
	{
		return nullptr;
	}

	if (const TObjectPtr<UGameplayQuestDefinition>* Found = RuntimeQuestDefinitions.Find(QuestTag))
	{
		if (Found->Get())
		{
			return Found->Get();
		}
	}

	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			if (const UGameplayQuestDataSubsystem* DataSubsystem = GI->GetSubsystem<UGameplayQuestDataSubsystem>())
			{
				return DataSubsystem->GetQuestDefinition(QuestTag);
			}
		}
	}

	return nullptr;
}

// ----------------------------------------------------------------------------
// Client Reconciliations & RepNotify
// ----------------------------------------------------------------------------

void UGameplayQuestManagerComponent::HandleQuestRecordAdded(const FGameplayQuestRecord& Record)
{
	OnQuestStatusChanged.Broadcast(Record.QuestTag, Record.StatusTag, GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag());
	OnQuestStatusChangedNative.Broadcast(Record.QuestTag, Record.StatusTag, GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag());
	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();
}

void UGameplayQuestManagerComponent::HandleQuestRecordChanged(const FGameplayQuestRecord& Record)
{
	for (const FGameplayObjectiveRecord& ObjRec : Record.ObjectiveRecords)
	{
		OnObjectiveProgressChanged.Broadcast(Record.QuestTag, ObjRec.ObjectiveTag, ObjRec.CurrentProgress, ObjRec.RequiredCount);
		OnObjectiveProgressChangedNative.Broadcast(Record.QuestTag, ObjRec.ObjectiveTag, ObjRec.CurrentProgress, ObjRec.RequiredCount);
	}
	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();
}

void UGameplayQuestManagerComponent::HandleQuestRecordRemoved(const FGameplayQuestRecord& Record)
{
	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();
}

void UGameplayQuestManagerComponent::OnRep_CompletedQuestTags(const FGameplayTagContainer& OldTags)
{
	for (auto It = CompletedQuestTags.CreateConstIterator(); It; ++It)
	{
		if (!OldTags.HasTagExact(*It))
		{
			OnQuestStatusChanged.Broadcast(*It, GameplayQuestTags::TAG_Quest_Status_Completed.GetTag(), GameplayQuestTags::TAG_Quest_Status_Active.GetTag());
			OnQuestStatusChangedNative.Broadcast(*It, GameplayQuestTags::TAG_Quest_Status_Completed.GetTag(), GameplayQuestTags::TAG_Quest_Status_Active.GetTag());
		}
	}
	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();
}

void UGameplayQuestManagerComponent::OnRep_FailedQuestTags(const FGameplayTagContainer& OldTags)
{
	for (auto It = FailedQuestTags.CreateConstIterator(); It; ++It)
	{
		if (!OldTags.HasTagExact(*It))
		{
			OnQuestStatusChanged.Broadcast(*It, GameplayQuestTags::TAG_Quest_Status_Failed.GetTag(), GameplayQuestTags::TAG_Quest_Status_Active.GetTag());
			OnQuestStatusChangedNative.Broadcast(*It, GameplayQuestTags::TAG_Quest_Status_Failed.GetTag(), GameplayQuestTags::TAG_Quest_Status_Active.GetTag());
		}
	}
	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();
}

// ----------------------------------------------------------------------------
// Cross-World Travel
// ----------------------------------------------------------------------------

void UGameplayQuestManagerComponent::PrepareForTravel(const FGuid& PlayerGuid)
{
	if (!PlayerGuid.IsValid())
	{
		return;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		return;
	}

	UGameInstance* GI = World->GetGameInstance();
	if (!GI)
	{
		return;
	}

	UGameplayQuestDataSubsystem* DataSubsystem = GI->GetSubsystem<UGameplayQuestDataSubsystem>();
	if (!DataSubsystem)
	{
		return;
	}

	// Serialize ActiveQuestList into byte buffer
	TArray<uint8> Buffer;
	FMemoryWriter MemoryWriter(Buffer, true);
	int32 QuestCount = ActiveQuestList.Items.Num();
	MemoryWriter << QuestCount;

	for (FGameplayQuestRecord& Item : ActiveQuestList.Items)
	{
		FString QuestTagString = Item.QuestTag.ToString();
		MemoryWriter << QuestTagString;
		MemoryWriter << Item.CurrentStageIndex;

		int32 ObjCount = Item.ObjectiveRecords.Num();
		MemoryWriter << ObjCount;
		for (FGameplayObjectiveRecord& Obj : Item.ObjectiveRecords)
		{
			FString ObjTagString = Obj.ObjectiveTag.ToString();
			MemoryWriter << ObjTagString;
			MemoryWriter << Obj.CurrentProgress;
			MemoryWriter << Obj.RequiredCount;
		}
	}

	DataSubsystem->CachePlayerQuestsForTravel(PlayerGuid, Buffer);
}

bool UGameplayQuestManagerComponent::HydrateFromTravelCache(const FGuid& PlayerGuid)
{
	if (!PlayerGuid.IsValid())
	{
		return false;
	}

	UWorld* World = GetWorld();
	if (!World)
	{
		return false;
	}

	UGameInstance* GI = World->GetGameInstance();
	if (!GI)
	{
		return false;
	}

	UGameplayQuestDataSubsystem* DataSubsystem = GI->GetSubsystem<UGameplayQuestDataSubsystem>();
	if (!DataSubsystem || !DataSubsystem->HasTravelCacheForPlayer(PlayerGuid))
	{
		return false;
	}

	TArray<uint8> Buffer;
	if (!DataSubsystem->RestorePlayerQuestsFromTravel(PlayerGuid, Buffer) || Buffer.Num() == 0)
	{
		return false;
	}

	FMemoryReader MemoryReader(Buffer, true);
	int32 QuestCount = 0;
	MemoryReader << QuestCount;

	ActiveQuestList.Items.Empty();

	for (int32 i = 0; i < QuestCount; ++i)
	{
		FString QuestTagString;
		int32 StageIndex = 0;
		MemoryReader << QuestTagString;
		MemoryReader << StageIndex;

		FGameplayTag QuestTag = FGameplayTag::RequestGameplayTag(FName(*QuestTagString), false);
		FGameplayQuestRecord* Record = ActiveQuestList.AddQuestRecord(
			QuestTag,
			GameplayQuestTags::TAG_Quest_Status_Active_InProgress.GetTag(),
			StageIndex
		);

		if (Record)
		{
			int32 ObjCount = 0;
			MemoryReader << ObjCount;
			for (int32 j = 0; j < ObjCount; ++j)
			{
				FString ObjTagString;
				int32 Progress = 0;
				int32 ReqCount = 1;
				MemoryReader << ObjTagString;
				MemoryReader << Progress;
				MemoryReader << ReqCount;

				FGameplayObjectiveRecord ObjRec;
				ObjRec.ObjectiveTag = FGameplayTag::RequestGameplayTag(FName(*ObjTagString), false);
				ObjRec.CurrentProgress = Progress;
				ObjRec.RequiredCount = ReqCount;
				ObjRec.StatusTag = (Progress >= ReqCount) ?
					GameplayQuestTags::TAG_Quest_Objective_Status_Completed.GetTag() :
					GameplayQuestTags::TAG_Quest_Objective_Status_Active.GetTag();

				Record->ObjectiveRecords.Add(ObjRec);
			}

			if (UGameplayQuestDefinition* QuestDef = ResolveQuestDefinition(QuestTag))
			{
				RegisterObjectivesWithEventBus(*Record, QuestDef);
			}
		}
	}

	OnQuestListUpdated.Broadcast();
	return true;
}

// ----------------------------------------------------------------------------
// Dual Persistence Layer (Local Binary & Cloud Database JSON)
// ----------------------------------------------------------------------------

FGameplayQuestSaveData UGameplayQuestManagerComponent::ExportSaveData(const FGuid& CharacterGuid) const
{
	FGameplayQuestSaveData OutData;
	OutData.CharacterGuid = CharacterGuid;
	OutData.CompletedQuests = CompletedQuestTags;
	OutData.FailedQuests = FailedQuestTags;

	for (const FGameplayQuestRecord& Record : ActiveQuestList.Items)
	{
		FGameplayQuestSaveRecord QuestSave;
		QuestSave.QuestTag = Record.QuestTag;
		QuestSave.StatusTag = Record.StatusTag;
		QuestSave.CurrentStageIndex = Record.CurrentStageIndex;

		for (const FGameplayObjectiveRecord& ObjRec : Record.ObjectiveRecords)
		{
			FGameplayObjectiveSaveRecord ObjSave;
			ObjSave.ObjectiveTag = ObjRec.ObjectiveTag;
			ObjSave.StatusTag = ObjRec.StatusTag;
			ObjSave.CurrentProgress = ObjRec.CurrentProgress;
			ObjSave.RequiredCount = ObjRec.RequiredCount;

			QuestSave.Objectives.Add(ObjSave);
		}

		OutData.ActiveQuests.Add(QuestSave);
	}

	return OutData;
}

bool UGameplayQuestManagerComponent::ImportSaveData(const FGameplayQuestSaveData& InSaveData)
{
	if (!GetOwner() || !GetOwner()->HasAuthority())
	{
		return false;
	}

	// 1. Restore completed and failed quests
	CompletedQuestTags = InSaveData.CompletedQuests;
	FailedQuestTags = InSaveData.FailedQuests;

	// 2. Clear current active quests
	ActiveQuestList.Items.Empty();

	// 3. Hydrate active quests
	for (const FGameplayQuestSaveRecord& QuestSave : InSaveData.ActiveQuests)
	{
		if (!QuestSave.QuestTag.IsValid())
		{
			continue;
		}

		FGameplayQuestRecord* Record = ActiveQuestList.AddQuestRecord(
			QuestSave.QuestTag,
			QuestSave.StatusTag,
			QuestSave.CurrentStageIndex
		);

		if (Record)
		{
			for (const FGameplayObjectiveSaveRecord& ObjSave : QuestSave.Objectives)
			{
				FGameplayObjectiveRecord ObjRec;
				ObjRec.ObjectiveTag = ObjSave.ObjectiveTag;
				ObjRec.StatusTag = ObjSave.StatusTag;
				ObjRec.CurrentProgress = ObjSave.CurrentProgress;
				ObjRec.RequiredCount = ObjSave.RequiredCount;

				Record->ObjectiveRecords.Add(ObjRec);
			}

			// Re-register with event subsystem
			if (UGameplayQuestDefinition* QuestDef = ResolveQuestDefinition(QuestSave.QuestTag))
			{
				RegisterObjectivesWithEventBus(*Record, QuestDef);
			}
		}
	}

	OnQuestListUpdated.Broadcast();
	OnQuestListUpdatedNative.Broadcast();
	return true;
}
