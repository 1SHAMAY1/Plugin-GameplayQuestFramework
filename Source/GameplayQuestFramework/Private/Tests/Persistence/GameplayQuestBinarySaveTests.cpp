// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestDefinition.h"
#include "Objectives/KillObjectiveDefinition.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestSaveData.h"
#include "Tests/GameplayQuestTestMocks.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Validates binary export and import roundtrip fidelity on active quests and objectives.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestBinarySaveRoundtripTest,
	"GameplayQuest.Persistence.Binary.RoundtripIntegrity",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestBinarySaveRoundtripTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World must be created"), World);

	if (World)
	{
		AMockQuestOwnerActor* Owner = World->SpawnActor<AMockQuestOwnerActor>();
		TestNotNull(TEXT("Owner actor must spawn"), Owner);

		UGameplayQuestManagerComponent* Manager = Owner->MockManagerComponent;
		TestNotNull(TEXT("Manager must be valid"), Manager);

		// Setup Quest Definition
		UGameplayQuestDefinition* QuestDef = NewObject<UGameplayQuestDefinition>(Owner);
		const FGameplayTag SampleQuestTag = TAG_Quest_Objective_SampleA.GetTag();
		QuestDef->QuestTag = SampleQuestTag;

		FGameplayQuestStage Stage0;
		UKillObjectiveDefinition* KillObj = NewObject<UKillObjectiveDefinition>(QuestDef);
		KillObj->ObjectiveTag = TAG_Target_Enemy_Goblin.GetTag();
		KillObj->RequiredCount = 5;
		Stage0.Objectives.Add(KillObj);
		QuestDef->Stages.Add(Stage0);

		// Accept quest and advance progress
		Manager->AcceptQuest(QuestDef);
		Manager->AdvanceObjectiveProgress(SampleQuestTag, KillObj->ObjectiveTag, 3);

		// Export to binary
		const FGuid CharacterGuid = FGuid::NewGuid();
		FGameplayQuestSaveData SaveData = Manager->ExportSaveData(CharacterGuid);
		TestEqual(TEXT("Exported active quests count should be 1"), SaveData.ActiveQuests.Num(), 1);

		TArray<uint8> BinaryBuffer;
		SaveData.ExportToBinary(BinaryBuffer);
		TestTrue(TEXT("Binary buffer size should be greater than 0"), BinaryBuffer.Num() > 0);

		// Import into a fresh manager
		AMockQuestOwnerActor* NewOwner = World->SpawnActor<AMockQuestOwnerActor>();
		UGameplayQuestManagerComponent* NewManager = NewOwner->MockManagerComponent;
		NewManager->RegisterRuntimeQuestDefinition(QuestDef);

		FGameplayQuestSaveData RestoredSaveData;
		const bool bBinaryImported = RestoredSaveData.ImportFromBinary(BinaryBuffer);
		TestTrue(TEXT("ImportFromBinary should succeed"), bBinaryImported);
		TestEqual(TEXT("Restored character GUID should match"), RestoredSaveData.CharacterGuid, CharacterGuid);

		const bool bManagerImported = NewManager->ImportSaveData(RestoredSaveData);
		TestTrue(TEXT("ImportSaveData should succeed"), bManagerImported);
		TestTrue(TEXT("Quest should be active in new manager"), NewManager->IsQuestActive(SampleQuestTag));

		const FGameplayQuestRecord* RestoredRecord = NewManager->GetActiveQuestRecord(SampleQuestTag);
		TestNotNull(TEXT("Restored quest record must exist"), RestoredRecord);
		if (RestoredRecord)
		{
			const FGameplayObjectiveRecord* RestoredObj = RestoredRecord->FindObjectiveRecord(KillObj->ObjectiveTag);
			TestNotNull(TEXT("Restored objective record must exist"), RestoredObj);
			if (RestoredObj)
			{
				TestEqual(TEXT("Restored progress must equal 3"), RestoredObj->CurrentProgress, 3);
				TestEqual(TEXT("Restored required count must equal 5"), RestoredObj->RequiredCount, 5);
			}
		}

		Owner->Destroy();
		NewOwner->Destroy();
		World->DestroyWorld(false);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
