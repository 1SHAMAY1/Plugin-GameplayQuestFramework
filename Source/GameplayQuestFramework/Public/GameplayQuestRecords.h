// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestRecords.generated.h"

class UGameplayQuestManagerComponent;

/**
 * Replicated state record for an individual quest objective.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayObjectiveRecord
{
	GENERATED_BODY()

	/** Unique tag identifying this objective within the quest definition. */
	UPROPERTY(BlueprintReadOnly, Category = "Quest Objective")
	FGameplayTag ObjectiveTag;

	/** Current lifecycle status of this objective (e.g. Quest.Objective.Status.Active, Completed). */
	UPROPERTY(BlueprintReadOnly, Category = "Quest Objective")
	FGameplayTag StatusTag;

	/** Current numerical progress towards RequiredCount. */
	UPROPERTY(BlueprintReadOnly, Category = "Quest Objective")
	int32 CurrentProgress = 0;

	/** Target count needed to complete this objective. */
	UPROPERTY(BlueprintReadOnly, Category = "Quest Objective")
	int32 RequiredCount = 1;

	bool IsCompleted() const
	{
		return CurrentProgress >= RequiredCount;
	}
};

/**
 * Replicated quest item managed within an FFastArraySerializer list.
 * Inherits from FFastArraySerializerItem for network delta compression.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayQuestRecord : public FFastArraySerializerItem
{
	GENERATED_BODY()

	FGameplayQuestRecord();

	/** Primary tag identifying the quest definition asset. */
	UPROPERTY(BlueprintReadOnly, Category = "Quest Record")
	FGameplayTag QuestTag;

	/** Current status tag (e.g. Quest.Status.Active.InProgress, ReadyToTurnIn, Completed). */
	UPROPERTY(BlueprintReadOnly, Category = "Quest Record")
	FGameplayTag StatusTag;

	/** Current active stage index in multi-stage quest progression. */
	UPROPERTY(BlueprintReadOnly, Category = "Quest Record")
	int32 CurrentStageIndex = 0;

	/** Progress records for all objectives in the active stage. */
	UPROPERTY(BlueprintReadOnly, Category = "Quest Record")
	TArray<FGameplayObjectiveRecord> ObjectiveRecords;

	// FFastArraySerializer callbacks
	void PostReplicatedAdd(const struct FGameplayQuestRecordList& InArraySerializer);
	void PostReplicatedChange(const struct FGameplayQuestRecordList& InArraySerializer);
	void PreReplicatedRemove(const struct FGameplayQuestRecordList& InArraySerializer);

	/** Finds an objective record by tag. */
	FGameplayObjectiveRecord* FindObjectiveRecord(const FGameplayTag& InObjectiveTag);
	const FGameplayObjectiveRecord* FindObjectiveRecord(const FGameplayTag& InObjectiveTag) const;

	/** Returns true if all required objectives in the active stage are completed. */
	bool AreStageObjectivesCompleted() const;
};

/**
 * Replicated container for active player quests using Unreal Engine's FFastArraySerializer.
 * Efficiently replicates only modified (dirty) quest records instead of whole arrays.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayQuestRecordList : public FFastArraySerializer
{
	GENERATED_BODY()

	FGameplayQuestRecordList();

	UPROPERTY()
	TArray<FGameplayQuestRecord> Items;

	UPROPERTY(NotReplicated)
	TObjectPtr<UGameplayQuestManagerComponent> OwnerComponent = nullptr;

	bool NetDeltaSerialize(FNetDeltaSerializeInfo& DeltaParms)
	{
		return FFastArraySerializer::FastArrayDeltaSerialize<FGameplayQuestRecord, FGameplayQuestRecordList>(Items, DeltaParms, *this);
	}

	FGameplayQuestRecord* AddQuestRecord(const FGameplayTag& QuestTag, const FGameplayTag& InitialStatusTag, int32 StageIndex);
	bool RemoveQuestRecord(const FGameplayTag& QuestTag);
	FGameplayQuestRecord* FindQuestRecord(const FGameplayTag& QuestTag);
	const FGameplayQuestRecord* FindQuestRecord(const FGameplayTag& QuestTag) const;
	void MarkQuestDirty(FGameplayQuestRecord& Record);
};

template<>
struct TStructOpsTypeTraits<FGameplayQuestRecordList> : public TStructOpsTypeTraitsBase2<FGameplayQuestRecordList>
{
	enum
	{
		WithNetDeltaSerializer = true,
	};
};
