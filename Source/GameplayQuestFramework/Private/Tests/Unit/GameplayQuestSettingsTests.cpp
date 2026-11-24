// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GameplayQuestSettings.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestSettingsTests,
	"GameplayQuest.Unit.Settings.DefaultsAndValidation",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestSettingsTests::RunTest(const FString& Parameters)
{
	const UGameplayQuestSettings* Settings = UGameplayQuestSettings::Get();
	TestNotNull(TEXT("GameplayQuestSettings singleton must be valid and loaded"), Settings);
	if (!Settings)
	{
		return false;
	}

	TestTrue(TEXT("SaveSchemaVersion must be >= 1 for versioned persistence"), Settings->SaveSchemaVersion >= 1);
	TestTrue(TEXT("DefaultPartyShareRadius must be positive (> 0.0f)"), Settings->DefaultPartyShareRadius > 0.0f);
	TestTrue(TEXT("MaxActiveQuestsPerPlayer must be >= 1"), Settings->MaxActiveQuestsPerPlayer >= 1);
	TestTrue(TEXT("DefaultZoneTag must be a valid tag"), Settings->DefaultZoneTag.IsValid());
	TestEqual(TEXT("Settings category name must be 'Game'"), Settings->GetCategoryName(), FName(TEXT("Game")));

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
