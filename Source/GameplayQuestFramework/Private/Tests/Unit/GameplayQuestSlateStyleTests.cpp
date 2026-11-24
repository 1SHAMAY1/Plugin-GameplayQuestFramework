// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GameplayQuestModule.h"

#if WITH_EDITOR
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#endif

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestSlateStyleRegistrationTest,
	"GameplayQuest.Unit.Resources.SlateStyleRegistration",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestSlateStyleRegistrationTest::RunTest(const FString& Parameters)
{
#if WITH_EDITOR
	TSharedPtr<FSlateStyleSet> StyleSet = FGameplayQuestFrameworkModule::GetStyleSet();
	TestTrue(TEXT("StyleSet should be initialized in editor builds"), StyleSet.IsValid());

	if (StyleSet.IsValid())
	{
		TestEqual(TEXT("StyleSetName should match GameplayQuestFrameworkStyle"), StyleSet->GetStyleSetName(), FName("GameplayQuestFrameworkStyle"));

		// Verify brushes registered for each core type
		const TCHAR* StyleNames[] = {
			TEXT("ClassIcon.GameplayQuestManagerComponent"),
			TEXT("ClassThumbnail.GameplayQuestManagerComponent"),
			TEXT("ClassIcon.GameplayQuestGiverComponent"),
			TEXT("ClassThumbnail.GameplayQuestGiverComponent"),
			TEXT("ClassIcon.GameplayQuestDefinition"),
			TEXT("ClassThumbnail.GameplayQuestDefinition"),
			TEXT("ClassIcon.GameplayObjectiveDefinition"),
			TEXT("ClassThumbnail.GameplayObjectiveDefinition"),
			TEXT("ClassIcon.GameplayQuestTriggerVolume"),
			TEXT("ClassThumbnail.GameplayQuestTriggerVolume")
		};

		for (const TCHAR* StyleName : StyleNames)
		{
			const FSlateBrush* Brush = StyleSet->GetBrush(FName(StyleName));
			TestNotNull(FString::Printf(TEXT("Brush for %s must be registered"), StyleName), Brush);
		}
	}
#endif

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
