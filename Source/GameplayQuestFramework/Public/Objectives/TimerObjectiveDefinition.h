// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayObjectiveDefinition.h"
#include "TimerObjectiveDefinition.generated.h"

/**
 * Event-driven, zero-tick countdown timer objective.
 *
 * Utilizes FTimerManager (not Tick) to signal expiration or failure.
 * When the duration expires, dispatches an event via the quest event bus.
 */
UCLASS(BlueprintType, meta = (DisplayName = "Timer Objective"))
class GAMEPLAYQUESTFRAMEWORK_API UTimerObjectiveDefinition : public UGameplayObjectiveDefinition
{
	GENERATED_BODY()

public:
	UTimerObjectiveDefinition(const FObjectInitializer& ObjectInitializer);

	/** Duration of the timer in seconds. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Timer Objective", meta = (ClampMin = "0.1", Units = "s"))
	float DurationSeconds = 60.0f;

	/** If true, the objective fails when the timer runs out. If false, surviving the duration completes the objective. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Timer Objective")
	bool bFailOnTimeout = true;

	virtual FGameplayTag GetEventChannelTag_Implementation() const override;
	virtual bool MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const override;
};
