// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestTypes.generated.h"

class AActor;

/**
 * Unique identifier for a quest objective within a quest definition.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayObjectiveId
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	FGameplayTag ObjectiveTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	int32 StageIndex = 0;

	FGameplayObjectiveId() = default;

	FGameplayObjectiveId(const FGameplayTag& InTag, int32 InStageIndex = 0)
		: ObjectiveTag(InTag), StageIndex(InStageIndex)
	{
	}

	bool operator==(const FGameplayObjectiveId& Other) const
	{
		return ObjectiveTag == Other.ObjectiveTag && StageIndex == Other.StageIndex;
	}

	bool operator!=(const FGameplayObjectiveId& Other) const
	{
		return !(*this == Other);
	}

	friend uint32 GetTypeHash(const FGameplayObjectiveId& Item)
	{
		return HashCombine(GetTypeHash(Item.ObjectiveTag), GetTypeHash(Item.StageIndex));
	}
};

/**
 * Generic, decoupled event payload transmitted across the zero-tick quest event bus.
 * Extensible for any game system without altering framework headers.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayQuestEventPayload
{
	GENERATED_BODY()

	/** Primary event channel or category tag (e.g. Quest.Event.Kill, Quest.Event.Collect). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	FGameplayTag EventTag;

	/** The actor that performed or caused the event (e.g. player pawn, weapon instigator). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	TObjectPtr<AActor> Instigator = nullptr;

	/** The secondary or target actor involved in the event (e.g. killed monster, interacted chest). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	TObjectPtr<AActor> TargetActor = nullptr;

	/** Integer quantity, count, or progress increment for this event. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	int32 Quantity = 1;

	/** The world or zone where this event took place (used for zone scoping). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	FGameplayTag ZoneTag;

	/** Arbitrary context tags (e.g. weapon type, faction tag, damage tags, item tags). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	FGameplayTagContainer ContextTags;

	/** Extensible numeric parameters (e.g. damage dealt, distance, time elapsed, currency). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	TMap<FGameplayTag, float> NumericParameters;

	FGameplayQuestEventPayload() = default;

	FGameplayQuestEventPayload(const FGameplayTag& InEventTag, AActor* InInstigator = nullptr, int32 InQuantity = 1)
		: EventTag(InEventTag), Instigator(InInstigator), Quantity(InQuantity)
	{
	}

	/** Returns true if the payload carries the exact tag or any parent tag. */
	bool HasContextTag(const FGameplayTag& Tag) const
	{
		return ContextTags.HasTag(Tag);
	}

	/** Returns true if the payload matches the given tag query. */
	bool MatchesTagQuery(const FGameplayTagQuery& Query) const
	{
		return Query.Matches(ContextTags);
	}

	/** Retrieve a numeric parameter by tag, or DefaultValue if not found. */
	float GetNumericParameter(const FGameplayTag& ParamTag, float DefaultValue = 0.0f) const
	{
		if (const float* FoundVal = NumericParameters.Find(ParamTag))
		{
			return *FoundVal;
		}
		return DefaultValue;
	}

	/** Set or update a numeric parameter by tag. */
	void SetNumericParameter(const FGameplayTag& ParamTag, float Value)
	{
		NumericParameters.FindOrAdd(ParamTag) = Value;
	}
};

/**
 * Lightweight serialized record for cross-world travel persistence.
 * Stashed into UGameplayQuestDataSubsystem before map unload, hydrated in new world.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayQuestTravelCache
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, Category = "Quest Framework")
	FGuid PlayerGuid;

	UPROPERTY(BlueprintReadWrite, Category = "Quest Framework")
	TArray<uint8> SerializedQuestBuffer;

	UPROPERTY(BlueprintReadWrite, Category = "Quest Framework")
	double CachedTimestamp = 0.0;

	bool IsValid() const
	{
		return PlayerGuid.IsValid() && SerializedQuestBuffer.Num() > 0;
	}
};
