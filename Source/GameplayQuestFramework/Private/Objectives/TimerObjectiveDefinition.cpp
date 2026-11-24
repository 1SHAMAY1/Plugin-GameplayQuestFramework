// Copyright Epic Games, Inc. All Rights Reserved.

#include "Objectives/TimerObjectiveDefinition.h"
#include "GameplayQuestTags.h"

UTimerObjectiveDefinition::UTimerObjectiveDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	DurationSeconds = 60.0f;
	bFailOnTimeout = true;
	RequiredCount = 1;
}

FGameplayTag UTimerObjectiveDefinition::GetEventChannelTag_Implementation() const
{
	return GameplayQuestTags::TAG_Quest_Event_Timer.GetTag();
}

bool UTimerObjectiveDefinition::MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const
{
	if (!Super::MatchesEvent_Implementation(Payload))
	{
		return false;
	}

	if (ObjectiveTag.IsValid())
	{
		return Payload.HasContextTag(ObjectiveTag);
	}

	return true;
}
