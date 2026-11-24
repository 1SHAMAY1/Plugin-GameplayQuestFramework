// Copyright Epic Games, Inc. All Rights Reserved.

#include "Objectives/ReachAreaObjectiveDefinition.h"
#include "GameplayQuestTags.h"

UReachAreaObjectiveDefinition::UReachAreaObjectiveDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	RequiredCount = 1;
}

FGameplayTag UReachAreaObjectiveDefinition::GetEventChannelTag_Implementation() const
{
	return GameplayQuestTags::TAG_Quest_Event_ReachArea.GetTag();
}

bool UReachAreaObjectiveDefinition::MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const
{
	if (!Super::MatchesEvent_Implementation(Payload))
	{
		return false;
	}

	if (TargetAreaTag.IsValid())
	{
		return Payload.HasContextTag(TargetAreaTag) || Payload.ZoneTag.MatchesTag(TargetAreaTag);
	}

	return true;
}
