// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "GameplayObjectiveDefinition.h"
#include "GameplayQuestReward.h"
#include "GameplayQuestDefinition.generated.h"

/**
 * A discrete phase or step within a multi-stage quest.
 * Objectives in a stage must be completed before advancing to the next stage.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayQuestStage
{
	GENERATED_BODY()

	/** Display name or summary of this stage. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Quest Stage")
	FText StageDescription;

	/** Instanced objectives required to advance through this stage. */
	UPROPERTY(EditDefaultsOnly, Instanced, BlueprintReadOnly, Category = "Quest Stage")
	TArray<TObjectPtr<UGameplayObjectiveDefinition>> Objectives;
};

/**
 * Designer-first PrimaryDataAsset defining an entire Quest.
 *
 * Configures stages, inline objectives, tag queries, prerequisites, and rewards.
 * Built-in native editor data validation via IsDataValid ensures design integrity.
 */
UCLASS(BlueprintType, meta = (DisplayName = "Gameplay Quest Definition"))
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UGameplayQuestDefinition(const FObjectInitializer& ObjectInitializer);

	/** Unique identifier tag for this quest (e.g. Quest.Main.DefeatTheDragon). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity", meta = (Categories = "Quest"))
	FGameplayTag QuestTag;

	/** User-facing Quest Title. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
	FText QuestTitle;

	/** User-facing Quest Narrative/Description. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity")
	FText QuestDescription;

	/** Category tag for journal organization (e.g. Quest.Category.Main, Side, Bounty). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Identity", meta = (Categories = "Quest.Category"))
	FGameplayTag CategoryTag;

	/** Progression flow: Sequential (stage by stage) or Concurrent. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Progression", meta = (Categories = "Quest.Progression"))
	FGameplayTag ProgressionFlowTag;

	/** Tag query defining prerequisites (e.g. player must possess completed quest tags or level tags). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Prerequisites")
	FGameplayTagQuery PrerequisiteQuery;

	/** Multi-stage quest progression pipeline. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Stages")
	TArray<FGameplayQuestStage> Stages;

	/** Rewards granted upon successful quest completion. */
	UPROPERTY(EditDefaultsOnly, Instanced, BlueprintReadOnly, Category = "Rewards")
	TArray<TObjectPtr<UGameplayQuestReward>> CompletionRewards;

	/** Checks whether a player carrying a set of tags meets the prerequisite query to accept this quest. */
	UFUNCTION(BlueprintCallable, Category = "Quest Definition|Query")
	bool CanAcceptQuest(const FGameplayTagContainer& PlayerContextTags) const;

	/** Retrieves the active objectives for a given stage index. */
	UFUNCTION(BlueprintCallable, Category = "Quest Definition|Query")
	void GetObjectivesForStage(int32 StageIndex, TArray<UGameplayObjectiveDefinition*>& OutObjectives) const;

	/** Native Asset Type for Asset Manager discovery. */
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const override;
#endif
};
