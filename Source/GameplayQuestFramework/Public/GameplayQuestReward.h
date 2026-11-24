// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestReward.generated.h"

class AActor;

/**
 * Designer-extensible base class for quest completion rewards.
 * Instanced inline within UGameplayQuestDefinition.
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestReward : public UObject
{
	GENERATED_BODY()

public:
	UGameplayQuestReward(const FObjectInitializer& ObjectInitializer);

	/** User-facing reward description (e.g. "500 XP", "Legendary Chest Key"). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Reward")
	FText RewardDescription;

	/** Grants the reward to the recipient actor (PlayerState/Pawn/Controller). */
	UFUNCTION(BlueprintNativeEvent, Category = "Reward")
	void GrantReward(AActor* Recipient);
	virtual void GrantReward_Implementation(AActor* Recipient);
};

/** Reward that grants numeric Experience Points or Currency. */
UCLASS(BlueprintType, meta = (DisplayName = "Numeric XP / Currency Reward"))
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestNumericReward : public UGameplayQuestReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Reward", meta = (Categories = "Reward.Type"))
	FGameplayTag RewardTypeTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Reward", meta = (ClampMin = "1"))
	int32 Amount = 100;

	virtual void GrantReward_Implementation(AActor* Recipient) override;
};

/** Reward that grants an inventory item or equipment token by tag. */
UCLASS(BlueprintType, meta = (DisplayName = "Item Grant Reward"))
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestItemReward : public UGameplayQuestReward
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Reward", meta = (Categories = "Item"))
	FGameplayTag ItemTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Reward", meta = (ClampMin = "1"))
	int32 Quantity = 1;

	virtual void GrantReward_Implementation(AActor* Recipient) override;
};
