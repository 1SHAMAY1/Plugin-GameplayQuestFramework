// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestTypes.h"
#include "GameplayQuestRecords.h"
#include "GameplayQuestSaveData.h"
#include "GameplayQuestManagerComponent.generated.h"

class UGameplayQuestDefinition;
class UGameplayObjectiveDefinition;

// Dynamic and Native C++ delegates (fired by server logic and client RepNotify/FastArray handlers)
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnQuestStatusChanged, const FGameplayTag&, QuestTag, const FGameplayTag&, NewStatusTag, const FGameplayTag&, OldStatusTag);
DECLARE_MULTICAST_DELEGATE_ThreeParams(FOnQuestStatusChangedNative, const FGameplayTag& /*QuestTag*/, const FGameplayTag& /*NewStatusTag*/, const FGameplayTag& /*OldStatusTag*/);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnObjectiveProgressChanged, const FGameplayTag&, QuestTag, const FGameplayTag&, ObjectiveTag, int32, CurrentProgress, int32, RequiredCount);
DECLARE_MULTICAST_DELEGATE_FourParams(FOnObjectiveProgressChangedNative, const FGameplayTag& /*QuestTag*/, const FGameplayTag& /*ObjectiveTag*/, int32 /*CurrentProgress*/, int32 /*RequiredCount*/);

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQuestListUpdated);
DECLARE_MULTICAST_DELEGATE(FOnQuestListUpdatedNative);

/**
 * Server-authoritative quest management component.
 * Can be attached to APlayerController, APlayerState, or AGameStateBase.
 *
 * Utilizes FFastArraySerializer for delta compressed replication.
 * Strict architectural rule: Zero NetMulticast RPCs. Local delegates fired via RepNotify.
 */
UCLASS(ClassGroup = (QuestFramework), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UGameplayQuestManagerComponent(const FObjectInitializer& ObjectInitializer);

	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	// -------------------------------------------------------------------------
	// Quest Lifecycle State Machine (Server Authoritative)
	// -------------------------------------------------------------------------

	/** Server-authoritative request to accept a quest. */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Quest Framework|Lifecycle")
	bool AcceptQuest(UGameplayQuestDefinition* QuestDefinition);

	/** Server-authoritative request to advance objective progress directly. */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Quest Framework|Lifecycle")
	bool AdvanceObjectiveProgress(const FGameplayTag& QuestTag, const FGameplayTag& ObjectiveTag, int32 ProgressAmount);

	/** Server-authoritative request to complete an active quest and grant rewards. */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Quest Framework|Lifecycle")
	bool CompleteQuest(const FGameplayTag& QuestTag);

	/** Server-authoritative request to fail an active quest. */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Quest Framework|Lifecycle")
	bool FailQuest(const FGameplayTag& QuestTag, const FGameplayTag& FailureReasonTag);

	/** Server-authoritative request to abandon an active quest. */
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Quest Framework|Lifecycle")
	bool AbandonQuest(const FGameplayTag& QuestTag);

	// -------------------------------------------------------------------------
	// Event Bus Processing
	// -------------------------------------------------------------------------

	/** Dispatch a quest event to this manager for objective evaluation. */
	virtual void ProcessQuestEvent(const FGameplayQuestEventPayload& Payload);

	// -------------------------------------------------------------------------
	// Queries
	// -------------------------------------------------------------------------

	/** Returns current lifecycle status tag of a given quest (e.g. Quest.Status.Active, Completed, NotStarted). */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quest Framework|Query")
	virtual FGameplayTag GetQuestStatus(const FGameplayTag& QuestTag) const;

	/** Checks whether the quest currently matches a specific status tag or parent status tag. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quest Framework|Query")
	virtual bool HasQuestStatus(const FGameplayTag& QuestTag, const FGameplayTag& StatusTag) const;

	/** Returns true if the quest has completed. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quest Framework|Query")
	bool IsQuestCompleted(const FGameplayTag& QuestTag) const;

	/** Returns true if the quest has failed. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quest Framework|Query")
	bool IsQuestFailed(const FGameplayTag& QuestTag) const;

	/** Returns true if the quest is actively in progress. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quest Framework|Query")
	bool IsQuestActive(const FGameplayTag& QuestTag) const;

	/** Retrieves the active quest record for a given quest tag. */
	const FGameplayQuestRecord* GetActiveQuestRecord(const FGameplayTag& QuestTag) const;

	/** Const access to the active quest list. */
	const FGameplayQuestRecordList& GetActiveQuestList() const { return ActiveQuestList; }

	// -------------------------------------------------------------------------
	// FastArray & RepNotify Callbacks (Client Reconciliations)
	// -------------------------------------------------------------------------

	void HandleQuestRecordAdded(const FGameplayQuestRecord& Record);
	void HandleQuestRecordChanged(const FGameplayQuestRecord& Record);
	void HandleQuestRecordRemoved(const FGameplayQuestRecord& Record);

	UFUNCTION()
	virtual void OnRep_CompletedQuestTags(const FGameplayTagContainer& OldTags);

	UFUNCTION()
	virtual void OnRep_FailedQuestTags(const FGameplayTagContainer& OldTags);

	// -------------------------------------------------------------------------
	// Delegates (Local Client & Server Observers)
	// -------------------------------------------------------------------------

	UPROPERTY(BlueprintAssignable, Category = "Quest Framework|Delegates")
	FOnQuestStatusChanged OnQuestStatusChanged;
	FOnQuestStatusChangedNative OnQuestStatusChangedNative;

	UPROPERTY(BlueprintAssignable, Category = "Quest Framework|Delegates")
	FOnObjectiveProgressChanged OnObjectiveProgressChanged;
	FOnObjectiveProgressChangedNative OnObjectiveProgressChangedNative;

	UPROPERTY(BlueprintAssignable, Category = "Quest Framework|Delegates")
	FOnQuestListUpdated OnQuestListUpdated;
	FOnQuestListUpdatedNative OnQuestListUpdatedNative;

	// -------------------------------------------------------------------------
	// Cross-World Level Travel Bridge
	// -------------------------------------------------------------------------

	/** Prepares and caches active quest data into GameInstance data subsystem before level travel. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Travel")
	void PrepareForTravel(const FGuid& PlayerGuid);

	/** Hydrates active quest data from GameInstance data subsystem upon arriving in new world. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Travel")
	bool HydrateFromTravelCache(const FGuid& PlayerGuid);

	// -------------------------------------------------------------------------
	// Dual Persistence (Local Binary & Cloud Database JSON)
	// -------------------------------------------------------------------------

	/** Exports all active, completed, and failed quests into a POD save data struct. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quest Framework|Persistence")
	FGameplayQuestSaveData ExportSaveData(const FGuid& CharacterGuid) const;

	/** Hydrates the entire quest manager from a POD save data struct. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Persistence")
	bool ImportSaveData(const FGameplayQuestSaveData& InSaveData);

	/** Registers an active in-memory quest definition (used by runtime systems or tests). */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Query")
	void RegisterRuntimeQuestDefinition(UGameplayQuestDefinition* QuestDef);

protected:
	/** Replicated list of active quests using FFastArraySerializer. */
	UPROPERTY(Replicated)
	FGameplayQuestRecordList ActiveQuestList;

	/** Set of completed quest tags (ReplicatedUsing for client delegate notifications). */
	UPROPERTY(ReplicatedUsing = OnRep_CompletedQuestTags)
	FGameplayTagContainer CompletedQuestTags;

	/** Set of failed quest tags (ReplicatedUsing for client delegate notifications). */
	UPROPERTY(ReplicatedUsing = OnRep_FailedQuestTags)
	FGameplayTagContainer FailedQuestTags;

	/** Local in-memory runtime cache of active quest definitions. */
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UGameplayQuestDefinition>> RuntimeQuestDefinitions;

	/** Resolves quest definition asset from tag via DataSubsystem or local runtime registry. */
	UGameplayQuestDefinition* ResolveQuestDefinition(const FGameplayTag& QuestTag) const;

	/** Advances the quest to the next stage or marks ready to turn in / completes. */
	void AdvanceQuestStage(FGameplayQuestRecord& QuestRecord, UGameplayQuestDefinition* QuestDef);

	/** Initializes objective records and registers subscriptions on the event bus for the active stage. */
	void SetupStageObjectives(FGameplayQuestRecord& QuestRecord, UGameplayQuestDefinition* QuestDef, int32 StageIndex);

	/** Subscribes all active objectives of a quest to the world event subsystem. */
	void RegisterObjectivesWithEventBus(const FGameplayQuestRecord& QuestRecord, UGameplayQuestDefinition* QuestDef);

	/** Unsubscribes objectives of a quest from the world event subsystem. */
	void UnregisterObjectivesFromEventBus(const FGameplayQuestRecord& QuestRecord, UGameplayQuestDefinition* QuestDef);
};
