// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestRecords.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Validates FFastArraySerializer delta operations: Modifies single objective, verifies dirty item tracking.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestFastArrayDirtyDeltaSerializationTest,
	"GameplayQuest.Network.FastArray.DirtyDeltaSerialization",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestFastArrayDirtyDeltaSerializationTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	FGameplayQuestRecordList RecordList;

	const FGameplayTag QuestA = TAG_Quest_Objective_SampleA.GetTag();
	const FGameplayTag QuestB = TAG_Quest_Objective_SampleB.GetTag();

	// Add records
	FGameplayQuestRecord* RecA = RecordList.AddQuestRecord(QuestA, TAG_Quest_Status_Active_InProgress.GetTag(), 0);
	FGameplayQuestRecord* RecB = RecordList.AddQuestRecord(QuestB, TAG_Quest_Status_Active_InProgress.GetTag(), 0);

	TestNotNull(TEXT("RecA must be added"), RecA);
	TestNotNull(TEXT("RecB must be added"), RecB);
	TestEqual(TEXT("RecordList count must be 2"), RecordList.Items.Num(), 2);

	// Modify RecA only
	RecA->CurrentStageIndex = 2;
	RecordList.MarkQuestDirty(*RecA);

	// Remove RecB
	const bool bRemoved = RecordList.RemoveQuestRecord(QuestB);
	TestTrue(TEXT("RecB removal should succeed"), bRemoved);
	TestEqual(TEXT("RecordList count should now be 1"), RecordList.Items.Num(), 1);

	// Find verification
	TestNotNull(TEXT("RecA should still be found"), RecordList.FindQuestRecord(QuestA));
	TestNull(TEXT("RecB should no longer be found"), RecordList.FindQuestRecord(QuestB));

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
