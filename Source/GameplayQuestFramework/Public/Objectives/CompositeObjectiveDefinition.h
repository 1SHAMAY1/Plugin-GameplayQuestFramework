// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayObjectiveDefinition.h"
#include "CompositeObjectiveDefinition.generated.h"

/** Logical operation for combining child objectives. */
UENUM(BlueprintType)
enum class EGameplayQuestCompositeOperation : uint8
{
	/** All child objectives must be completed (AND). */
	AllRequired,
	/** At least Any count child objectives must be completed (OR). */
	AnyRequired
};

/**
 * Composite objective combining multiple child sub-objectives in AND/OR logical branches.
 * Enables designers to author nested requirement trees without custom code.
 */
UCLASS(BlueprintType, meta = (DisplayName = "Composite Objective"))
class GAMEPLAYQUESTFRAMEWORK_API UCompositeObjectiveDefinition : public UGameplayObjectiveDefinition
{
	GENERATED_BODY()

public:
	UCompositeObjectiveDefinition(const FObjectInitializer& ObjectInitializer);

	/** Composite evaluation rule: AllRequired (AND) or AnyRequired (OR). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Composite")
	EGameplayQuestCompositeOperation CompositeOperation = EGameplayQuestCompositeOperation::AllRequired;

	/** Number of children required when CompositeOperation is AnyRequired. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Composite", meta = (ClampMin = "1", EditCondition = "CompositeOperation == EGameplayQuestCompositeOperation::AnyRequired"))
	int32 RequiredCompletedCount = 1;

	/** Child sub-objectives evaluated under this composite node. */
	UPROPERTY(EditDefaultsOnly, Instanced, BlueprintReadOnly, Category = "Composite")
	TArray<TObjectPtr<UGameplayObjectiveDefinition>> SubObjectives;

	virtual FGameplayTag GetEventChannelTag_Implementation() const override;
	virtual bool MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const override;
	virtual int32 EvaluateProgressYield_Implementation(const FGameplayQuestEventPayload& Payload) const override;

	/** Evaluates if composite condition is satisfied based on an external completed tags lookup. */
	UFUNCTION(BlueprintCallable, Category = "Composite")
	bool EvaluateCompleted(const TSet<FGameplayTag>& CompletedObjectiveTags) const;
};
