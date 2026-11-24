// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayObjectiveDefinition.h"
#include "ReachAreaObjectiveDefinition.generated.h"

/**
 * Objective requiring reaching, exploring, or entering a designated area or trigger volume.
 * Dispatched automatically by AGameplayQuestTriggerVolume.
 */
UCLASS(BlueprintType, meta = (DisplayName = "Reach Area Objective"))
class GAMEPLAYQUESTFRAMEWORK_API UReachAreaObjectiveDefinition : public UGameplayObjectiveDefinition
{
	GENERATED_BODY()

public:
	UReachAreaObjectiveDefinition(const FObjectInitializer& ObjectInitializer);

	/** Identifier of the target area (e.g. Zone.Dungeon.BossRoom). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Reach Area Objective", meta = (Categories = "Zone"))
	FGameplayTag TargetAreaTag;

	virtual FGameplayTag GetEventChannelTag_Implementation() const override;
	virtual bool MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const override;
};
