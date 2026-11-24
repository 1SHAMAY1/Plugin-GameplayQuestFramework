// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestSaveData.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Validates JSON export and import roundtrip fidelity for cloud/MMORPG database storage.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestJsonDatabaseRoundtripTest,
	"GameplayQuest.Persistence.Json.DatabaseRoundtrip",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestJsonDatabaseRoundtripTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	FGameplayQuestSaveData OriginalData;
	OriginalData.SchemaVersion = 1;
	OriginalData.CharacterGuid = FGuid::NewGuid();

	// Populate Active Quests
	FGameplayQuestSaveRecord QuestRec;
	QuestRec.QuestTag = TAG_Quest_Objective_SampleA.GetTag();
	QuestRec.StatusTag = TAG_Quest_Status_Active_InProgress.GetTag();
	QuestRec.CurrentStageIndex = 1;

	FGameplayObjectiveSaveRecord ObjRec;
	ObjRec.ObjectiveTag = TAG_Target_Enemy_Goblin.GetTag();
	ObjRec.StatusTag = TAG_Quest_Objective_Status_Active.GetTag();
	ObjRec.CurrentProgress = 7;
	ObjRec.RequiredCount = 10;
	QuestRec.Objectives.Add(ObjRec);

	OriginalData.ActiveQuests.Add(QuestRec);
	OriginalData.CompletedQuests.AddTag(TAG_Quest_Objective_SampleB.GetTag());

	// Export to JSON
	FString JsonString;
	const bool bExportSuccess = OriginalData.ExportToJson(JsonString);
	TestTrue(TEXT("ExportToJson must succeed"), bExportSuccess);
	TestTrue(TEXT("JsonString must not be empty"), !JsonString.IsEmpty());
	TestTrue(TEXT("JsonString must contain quest tag"), JsonString.Contains(TEXT("Quest.Objective.SampleA")));

	// Import from JSON
	FGameplayQuestSaveData RestoredData;
	const bool bImportSuccess = RestoredData.ImportFromJson(JsonString);
	TestTrue(TEXT("ImportFromJson must succeed"), bImportSuccess);
	TestEqual(TEXT("Restored SchemaVersion must match"), RestoredData.SchemaVersion, OriginalData.SchemaVersion);
	TestEqual(TEXT("Restored CharacterGuid must match"), RestoredData.CharacterGuid, OriginalData.CharacterGuid);
	TestEqual(TEXT("Restored ActiveQuests count must be 1"), RestoredData.ActiveQuests.Num(), 1);

	if (RestoredData.ActiveQuests.Num() > 0)
	{
		const FGameplayQuestSaveRecord& RestoredQuest = RestoredData.ActiveQuests[0];
		TestEqual(TEXT("Restored QuestTag must match"), RestoredQuest.QuestTag, QuestRec.QuestTag);
		TestEqual(TEXT("Restored StageIndex must match"), RestoredQuest.CurrentStageIndex, 1);
		TestEqual(TEXT("Restored Objectives count must be 1"), RestoredQuest.Objectives.Num(), 1);

		if (RestoredQuest.Objectives.Num() > 0)
		{
			const FGameplayObjectiveSaveRecord& RestoredObj = RestoredQuest.Objectives[0];
			TestEqual(TEXT("Restored progress must equal 7"), RestoredObj.CurrentProgress, 7);
			TestEqual(TEXT("Restored required count must equal 10"), RestoredObj.RequiredCount, 10);
		}
	}

	TestTrue(TEXT("Restored CompletedQuests must contain SampleB"), RestoredData.CompletedQuests.HasTag(TAG_Quest_Objective_SampleB.GetTag()));

	return true;
}

/**
 * Validates that save data with schema versions beyond current engine version are rejected safely.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestJsonSchemaMigrationSafetyTest,
	"GameplayQuest.Persistence.Json.SchemaVersionMigrationSafety",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestJsonSchemaMigrationSafetyTest::RunTest(const FString& Parameters)
{
	// Suppress the expected error log so the automation test runner does not flag it as a test failure
	AddExpectedError(TEXT("ImportFromJson failed: Save schema version"), EAutomationExpectedErrorFlags::Contains, 1);

	FGameplayQuestSaveData FutureSaveData;
	FutureSaveData.SchemaVersion = 99999; // Corrupted / future incompatible schema

	FString JsonString;
	FutureSaveData.ExportToJson(JsonString);

	FGameplayQuestSaveData TargetData;
	const bool bImportSuccess = TargetData.ImportFromJson(JsonString);
	TestFalse(TEXT("ImportFromJson must reject future incompatible schema version"), bImportSuccess);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
