// Copyright Epic Games, Inc. All Rights Reserved.

#include "Objectives/CompositeObjectiveDefinition.h"
#include "GameplayQuestTags.h"

UCompositeObjectiveDefinition::UCompositeObjectiveDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CompositeOperation = EGameplayQuestCompositeOperation::AllRequired;
	RequiredCompletedCount = 1;
	RequiredCount = 1;
}

FGameplayTag UCompositeObjectiveDefinition::GetEventChannelTag_Implementation() const
{
	return GameplayQuestTags::TAG_Quest_Event_Custom.GetTag();
}

bool UCompositeObjectiveDefinition::MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const
{
	if (!Super::MatchesEvent_Implementation(Payload))
	{
		return false;
	}

	for (const TObjectPtr<UGameplayObjectiveDefinition>& SubObj : SubObjectives)
	{
		if (SubObj && SubObj->MatchesEvent(Payload))
		{
			return true;
		}
	}

	return false;
}

int32 UCompositeObjectiveDefinition::EvaluateProgressYield_Implementation(const FGameplayQuestEventPayload& Payload) const
{
	int32 TotalYield = 0;
	for (const TObjectPtr<UGameplayObjectiveDefinition>& SubObj : SubObjectives)
	{
		if (SubObj && SubObj->MatchesEvent(Payload))
		{
			TotalYield += SubObj->EvaluateProgressYield(Payload);
		}
	}
	return FMath::Max(1, TotalYield);
}

bool UCompositeObjectiveDefinition::EvaluateCompleted(const TSet<FGameplayTag>& CompletedObjectiveTags) const
{
	if (SubObjectives.Num() == 0)
	{
		return true;
	}

	int32 CompletedCount = 0;
	for (const TObjectPtr<UGameplayObjectiveDefinition>& SubObj : SubObjectives)
	{
		if (SubObj && CompletedObjectiveTags.Contains(SubObj->ObjectiveTag))
		{
			++CompletedCount;
		}
	}

	if (CompositeOperation == EGameplayQuestCompositeOperation::AllRequired)
	{
		return CompletedCount >= SubObjectives.Num();
	}
	else
	{
		return CompletedCount >= RequiredCompletedCount;
	}
}
