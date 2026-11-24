// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestSettings.h"
#include "GameplayQuestTags.h"

UGameplayQuestSettings::UGameplayQuestSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SaveSchemaVersion = 1;
	DefaultPartyShareRadius = 5000.0f;
	MaxActiveQuestsPerPlayer = 50;
	bEnableNetworkDeltaProfiling = false;
	DefaultZoneTag = GameplayQuestTags::TAG_Zone_Default;
}

const UGameplayQuestSettings* UGameplayQuestSettings::Get()
{
	return GetDefault<UGameplayQuestSettings>();
}

FName UGameplayQuestSettings::GetCategoryName() const
{
	return FName(TEXT("Game"));
}
