// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "GameplayObjectiveDefinition.h"
#include "KillObjectiveDefinition.generated.h"

/**
 * Objective requiring defeat or elimination of specific target actors.
 * Matches targets by TargetTag (e.g. Target.Enemy.Goblin) or Actor Class filter.
 */
UCLASS(BlueprintType, meta = (DisplayName = "Kill Target Objective"))
class GAMEPLAYQUESTFRAMEWORK_API UKillObjectiveDefinition : public UGameplayObjectiveDefinition
{
	GENERATED_BODY()

public:
	UKillObjectiveDefinition(const FObjectInitializer& ObjectInitializer);

	/** Required target tag on the defeated entity (e.g. Target.Enemy.Undead.Skeleton). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Kill Objective", meta = (Categories = "Target"))
	FGameplayTag TargetTag;

	/** Optional actor class filter for the target. If null, any actor carrying TargetTag matches. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Kill Objective")
	TSubclassOf<AActor> TargetActorClass;

	/** Optional context query (e.g. killed with headshot, specific weapon, or damage type). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Kill Objective")
	FGameplayTagQuery ContextQuery;

	virtual FGameplayTag GetEventChannelTag_Implementation() const override;
	virtual bool MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const override;
};
