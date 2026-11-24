// Copyright Epic Games, Inc. All Rights Reserved.

#include "Objectives/KillObjectiveDefinition.h"
#include "GameplayQuestTags.h"

UKillObjectiveDefinition::UKillObjectiveDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

FGameplayTag UKillObjectiveDefinition::GetEventChannelTag_Implementation() const
{
	return GameplayQuestTags::TAG_Quest_Event_Kill.GetTag();
}

bool UKillObjectiveDefinition::MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const
{
	if (!Super::MatchesEvent_Implementation(Payload))
	{
		return false;
	}

	// 1. Target Tag match (either in ContextTags or on TargetActor)
	if (TargetTag.IsValid())
	{
		bool bFoundTag = Payload.HasContextTag(TargetTag);
		if (!bFoundTag && Payload.TargetActor)
		{
			bFoundTag = Payload.TargetActor->ActorHasTag(TargetTag.GetTagName());
		}

		if (!bFoundTag)
		{
			return false;
		}
	}

	// 2. Target Actor Class filter
	if (TargetActorClass && Payload.TargetActor)
	{
		if (!Payload.TargetActor->IsA(TargetActorClass))
		{
			return false;
		}
	}

	// 3. Context Query match (weapon, precision, damage type)
	if (!ContextQuery.IsEmpty() && !Payload.MatchesTagQuery(ContextQuery))
	{
		return false;
	}

	return true;
}
