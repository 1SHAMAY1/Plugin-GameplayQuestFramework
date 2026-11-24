// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayObjectiveDefinition.h"
#include "GameplayQuestTags.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

UGameplayObjectiveDefinition::UGameplayObjectiveDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SharingPolicyTag = GameplayQuestTags::TAG_Quest_Policy_Sharing_SoloOnly.GetTag();
}

FGameplayTag UGameplayObjectiveDefinition::GetEventChannelTag_Implementation() const
{
	return GameplayQuestTags::TAG_Quest_Event_Custom.GetTag();
}

bool UGameplayObjectiveDefinition::MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const
{
	// 1. Zone Scope Filtering: If this objective requires a specific zone, reject events from other zones
	if (ZoneScopeTag.IsValid())
	{
		if (!Payload.ZoneTag.IsValid() || !Payload.ZoneTag.MatchesTag(ZoneScopeTag))
		{
			return false;
		}
	}

	// 2. Channel match
	const FGameplayTag Channel = GetEventChannelTag();
	if (Channel.IsValid() && !Payload.EventTag.MatchesTag(Channel))
	{
		return false;
	}

	return true;
}

int32 UGameplayObjectiveDefinition::EvaluateProgressYield_Implementation(const FGameplayQuestEventPayload& Payload) const
{
	return FMath::Max(1, Payload.Quantity);
}

#if WITH_EDITOR
EDataValidationResult UGameplayObjectiveDefinition::IsDataValid(FDataValidationContext& Context) const
{
	EDataValidationResult Result = EDataValidationResult::Valid;

	if (!ObjectiveTag.IsValid())
	{
		Context.AddError(FText::FromString(TEXT("ObjectiveTag must be valid.")));
		Result = EDataValidationResult::Invalid;
	}

	if (RequiredCount <= 0)
	{
		Context.AddError(FText::FromString(TEXT("RequiredCount must be greater than zero.")));
		Result = EDataValidationResult::Invalid;
	}

	return Result;
}
#endif
