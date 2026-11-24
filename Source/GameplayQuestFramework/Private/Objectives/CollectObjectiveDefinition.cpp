// Copyright Epic Games, Inc. All Rights Reserved.

#include "Objectives/CollectObjectiveDefinition.h"
#include "GameplayQuestTags.h"

UCollectObjectiveDefinition::UCollectObjectiveDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bConsumeOnComplete = true;
}

FGameplayTag UCollectObjectiveDefinition::GetEventChannelTag_Implementation() const
{
	return GameplayQuestTags::TAG_Quest_Event_Collect.GetTag();
}

bool UCollectObjectiveDefinition::MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const
{
	if (!Super::MatchesEvent_Implementation(Payload))
	{
		return false;
	}

	if (ItemTag.IsValid())
	{
		return Payload.HasContextTag(ItemTag);
	}

	return true;
}
