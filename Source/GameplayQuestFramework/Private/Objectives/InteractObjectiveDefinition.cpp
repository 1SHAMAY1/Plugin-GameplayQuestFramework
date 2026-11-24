// Copyright Epic Games, Inc. All Rights Reserved.

#include "Objectives/InteractObjectiveDefinition.h"
#include "GameplayQuestTags.h"

UInteractObjectiveDefinition::UInteractObjectiveDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	RequiredCount = 1;
}

FGameplayTag UInteractObjectiveDefinition::GetEventChannelTag_Implementation() const
{
	return GameplayQuestTags::TAG_Quest_Event_Interact.GetTag();
}

bool UInteractObjectiveDefinition::MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const
{
	if (!Super::MatchesEvent_Implementation(Payload))
	{
		return false;
	}

	if (InteractableTag.IsValid())
	{
		return Payload.HasContextTag(InteractableTag);
	}

	return true;
}
