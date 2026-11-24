// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayObjectiveDefinition.h"
#include "CollectObjectiveDefinition.generated.h"

/**
 * Objective requiring acquisition, harvesting, or looting of items.
 * Driven entirely by ItemTag and count. Supports optional consumption on turn-in.
 */
UCLASS(BlueprintType, meta = (DisplayName = "Collect Item Objective"))
class GAMEPLAYQUESTFRAMEWORK_API UCollectObjectiveDefinition : public UGameplayObjectiveDefinition
{
	GENERATED_BODY()

public:
	UCollectObjectiveDefinition(const FObjectInitializer& ObjectInitializer);

	/** Item tag identifying the inventory item or resource (e.g. Item.Quest.AncientRelic). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collect Objective", meta = (Categories = "Item"))
	FGameplayTag ItemTag;

	/** If true, the collected items should be consumed/removed from inventory upon quest completion. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Collect Objective")
	bool bConsumeOnComplete = true;

	virtual FGameplayTag GetEventChannelTag_Implementation() const override;
	virtual bool MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const override;
};
