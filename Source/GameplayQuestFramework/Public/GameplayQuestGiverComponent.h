// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "Interfaces/IGameplayQuestGiverInterface.h"
#include "GameplayQuestGiverComponent.generated.h"

class UGameplayQuestDefinition;

/**
 * Component attached to world NPCs, quest boards, and terminals.
 * Implements quest giver state machine and dialogue queries.
 */
UCLASS(ClassGroup = (QuestFramework), BlueprintType, Blueprintable, meta = (BlueprintSpawnableComponent))
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestGiverComponent : public UActorComponent, public IGameplayQuestGiverInterface
{
	GENERATED_BODY()

public:
	UGameplayQuestGiverComponent(const FObjectInitializer& ObjectInitializer);

	/** List of quest definitions offered by this quest giver (hard references). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest Giver")
	TArray<TObjectPtr<UGameplayQuestDefinition>> OfferedQuests;

	/**
	 * Optional soft-referenced quest definitions for on-demand memory loading.
	 * Allows open worlds and large quest hubs to avoid keeping quest assets resident in RAM.
	 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest Giver", meta = (DisplayName = "Soft Offered Quests"))
	TArray<TSoftObjectPtr<UGameplayQuestDefinition>> SoftOfferedQuests;

	/** Fallback state tag when no quests are active. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest Giver", meta = (Categories = "Quest.Giver.State"))
	FGameplayTag DefaultGiverState;

	// IGameplayQuestGiverInterface implementation
	virtual void GetOfferedQuests_Implementation(const AActor* Interactor, TArray<FGameplayTag>& OutQuests) const override;
	virtual FGameplayTag GetQuestGiverStateTag_Implementation(const AActor* Interactor) const override;
};
