#include "QuestAsyncRegister.h"
#include "GameplayQuestSubsystem.h"
#include "GameplayQuestBase.h"
#include "GameplayQuestSystem.h"
#include "Engine/AssetManager.h"

UQuestAsyncRegister* UQuestAsyncRegister::RegisterQuest(FGameplayTag QuestTag, TSoftClassPtr<UGameplayQuestBase> QuestClass, AActor* Source)
{
	UQuestAsyncRegister* Node = NewObject<UQuestAsyncRegister>();
	Node->PendingQuestTag = QuestTag;
	Node->PendingQuestClass = QuestClass;
	Node->Source = Source;

	QUEST_LOG_GENERAL(TEXT("Queued quest registration for tag [%s] with class [%s]."),
		*QuestTag.ToString(),
		QuestClass.IsValid() ? *QuestClass->GetName() : *QuestClass.ToString());

	return Node;
}

void UQuestAsyncRegister::Activate()
{
	if (!PendingQuestClass.IsNull() && !PendingQuestClass.ToSoftObjectPath().IsValid())
	{
		// Truly invalid: not even a valid asset path
		QUEST_LOG_FAILED(TEXT("Quest registration failed: PendingQuestClass has invalid path for [%s]."), *PendingQuestTag.ToString());
		OnRegisterFail.Broadcast(nullptr, this);
		SetReadyToDestroy();
		return;
	}

	QUEST_LOG_GENERAL(TEXT("Loading quest class asset for [%s]..."), *PendingQuestTag.ToString());

	FStreamableManager& Streamable = UAssetManager::GetStreamableManager();
	PendingHandle = Streamable.RequestAsyncLoad(
		PendingQuestClass.ToSoftObjectPath(),
		FStreamableDelegate::CreateUObject(this, &UQuestAsyncRegister::HandleQuestClassLoaded)
	);

	if (!PendingHandle.IsValid())
	{
		QUEST_LOG_FAILED(TEXT("Quest registration failed: Could not request async load for [%s]."), *PendingQuestTag.ToString());
		OnRegisterFail.Broadcast(nullptr, this);
		SetReadyToDestroy();
	}
}

void UQuestAsyncRegister::HandleQuestClassLoaded()
{
	if (PendingQuestClass.IsNull())
	{
		QUEST_LOG_FAILED(TEXT("Quest registration failed: PendingQuestClass became invalid for [%s]."), *PendingQuestTag.ToString());
		OnRegisterFail.Broadcast(nullptr, this);
		SetReadyToDestroy();
		return;
	}

	UClass* LoadedClass = PendingQuestClass.Get();
	if (!LoadedClass) 
	{
		QUEST_LOG_FAILED(TEXT("Quest registration failed: LoadedClass is null for [%s]."), *PendingQuestTag.ToString());
		OnRegisterFail.Broadcast(nullptr, this);
		SetReadyToDestroy();
		return;
	}

	UGameplayQuestBase* QuestInstance = NewObject<UGameplayQuestBase>(Source , LoadedClass);
	if (!QuestInstance)
	{
		QUEST_LOG_FAILED(TEXT("Quest registration failed: Could not create instance of [%s] for quest [%s]."),
			*LoadedClass->GetName(), *PendingQuestTag.ToString());
		OnRegisterFail.Broadcast(nullptr, this);
		SetReadyToDestroy();
		return;
	}

	QUEST_LOG_GENERAL(TEXT("Quest instance [%s] created for tag [%s]."), *QuestInstance->GetName(), *PendingQuestTag.ToString());

	if (UGameplayQuestSubsystem* Subsystem = GetQuestSubsystem())
	{
		Subsystem->RegisterQuest_Internal(PendingQuestTag, QuestInstance, Source);
		QUEST_LOG_STARTED(TEXT("Quest [%s] registered successfully."), *PendingQuestTag.ToString());
		OnRegisterSuccess.Broadcast(QuestInstance, this);
		SetReadyToDestroy();
		return;
	}

	QUEST_LOG_FAILED(TEXT("Quest registration failed: Could not get GameplayQuestSubsystem for [%s]."), *PendingQuestTag.ToString());
	OnRegisterFail.Broadcast(nullptr, this);
	SetReadyToDestroy();
}
