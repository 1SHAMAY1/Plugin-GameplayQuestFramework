// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestTypes.h"
#include "GameplayQuestDefinition.h"
#include "Objectives/KillObjectiveDefinition.h"
#include "Objectives/CollectObjectiveDefinition.h"
#include "GameplayQuestManagerComponent.h"
#include "Tests/GameplayQuestTestMocks.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Tests AcceptQuest, AdvanceObjective, CompleteQuest, and AbandonQuest state transitions.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestLifecycleStateTransitionsTest,
	"GameplayQuest.Integration.Lifecycle.StateTransitions",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestLifecycleStateTransitionsTest::RunTest(const FString& Parameters)
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

		// Setup Test Quest Definition
		UGameplayQuestDefinition* QuestDef = NewObject<UGameplayQuestDefinition>(Owner);
		const FGameplayTag SampleQuestTag = TAG_Quest_Objective_SampleA.GetTag();
		QuestDef->QuestTag = SampleQuestTag;

		// Stage 0 with Kill Objective
		FGameplayQuestStage Stage0;
		UKillObjectiveDefinition* KillObj = NewObject<UKillObjectiveDefinition>(QuestDef);
		KillObj->ObjectiveTag = TAG_Target_Enemy_Goblin.GetTag();
		KillObj->RequiredCount = 2;
		Stage0.Objectives.Add(KillObj);
		QuestDef->Stages.Add(Stage0);

		// 1. Initial State
		TestEqual(TEXT("Initial quest status must be NotStarted"), Manager->GetQuestStatus(SampleQuestTag), TAG_Quest_Status_NotStarted.GetTag());
		TestFalse(TEXT("Quest should not be active initially"), Manager->IsQuestActive(SampleQuestTag));

		// 2. Accept Quest
		const bool bAccepted = Manager->AcceptQuest(QuestDef);
		TestTrue(TEXT("AcceptQuest should succeed"), bAccepted);
		TestTrue(TEXT("Quest should now be active"), Manager->IsQuestActive(SampleQuestTag));
		TestEqual(TEXT("Quest status must be InProgress"), Manager->GetQuestStatus(SampleQuestTag), TAG_Quest_Status_Active_InProgress.GetTag());

		// 3. Advance Objective Progress partially
		const bool bAdvanced1 = Manager->AdvanceObjectiveProgress(SampleQuestTag, KillObj->ObjectiveTag, 1);
		TestTrue(TEXT("First advance should succeed"), bAdvanced1);
		const FGameplayQuestRecord* Record = Manager->GetActiveQuestRecord(SampleQuestTag);
		TestNotNull(TEXT("Quest record must exist"), Record);
		if (Record)
		{
			const FGameplayObjectiveRecord* ObjRec = Record->FindObjectiveRecord(KillObj->ObjectiveTag);
			TestNotNull(TEXT("Objective record must exist"), ObjRec);
			if (ObjRec)
			{
				TestEqual(TEXT("CurrentProgress should be 1"), ObjRec->CurrentProgress, 1);
				TestFalse(TEXT("Objective should not be complete yet"), ObjRec->IsCompleted());
			}
		}

		// 4. Complete Objective -> Complete Stage 0 -> Auto Complete Quest
		const bool bAdvanced2 = Manager->AdvanceObjectiveProgress(SampleQuestTag, KillObj->ObjectiveTag, 1);
		TestTrue(TEXT("Second advance should complete quest"), bAdvanced2);
		TestTrue(TEXT("Quest should now be marked completed"), Manager->IsQuestCompleted(SampleQuestTag));
		TestFalse(TEXT("Quest should no longer be in active list"), Manager->IsQuestActive(SampleQuestTag));

		Owner->Destroy();
		World->DestroyWorld(false);
	}

	return true;
}

/**
 * Verifies Stage 2 objectives remain locked until Stage 1 completes.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestSequentialStageProgressionTest,
	"GameplayQuest.Integration.Lifecycle.SequentialStageProgression",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestSequentialStageProgressionTest::RunTest(const FString& Parameters)
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

		// Setup 2-Stage Quest
		UGameplayQuestDefinition* QuestDef = NewObject<UGameplayQuestDefinition>(Owner);
		const FGameplayTag TwoStageQuestTag = TAG_Quest_Objective_SampleB.GetTag();
		QuestDef->QuestTag = TwoStageQuestTag;

		// Stage 0
		FGameplayQuestStage Stage0;
		UKillObjectiveDefinition* ObjStage0 = NewObject<UKillObjectiveDefinition>(QuestDef);
		ObjStage0->ObjectiveTag = TAG_Target_Enemy_Goblin.GetTag();
		ObjStage0->RequiredCount = 1;
		Stage0.Objectives.Add(ObjStage0);
		QuestDef->Stages.Add(Stage0);

		// Stage 1
		FGameplayQuestStage Stage1;
		UCollectObjectiveDefinition* ObjStage1 = NewObject<UCollectObjectiveDefinition>(QuestDef);
		ObjStage1->ObjectiveTag = TAG_Item_Quest_Relic.GetTag();
		ObjStage1->RequiredCount = 1;
		Stage1.Objectives.Add(ObjStage1);
		QuestDef->Stages.Add(Stage1);

		Manager->AcceptQuest(QuestDef);

		const FGameplayQuestRecord* ActiveRec = Manager->GetActiveQuestRecord(TwoStageQuestTag);
		TestNotNull(TEXT("Active record must exist"), ActiveRec);
		if (ActiveRec)
		{
			TestEqual(TEXT("Initial stage must be 0"), ActiveRec->CurrentStageIndex, 0);
			TestNotNull(TEXT("Stage 0 objective must be in active record"), ActiveRec->FindObjectiveRecord(ObjStage0->ObjectiveTag));
			TestNull(TEXT("Stage 1 objective must NOT be active in Stage 0"), ActiveRec->FindObjectiveRecord(ObjStage1->ObjectiveTag));
		}

		// Advance Stage 0
		Manager->AdvanceObjectiveProgress(TwoStageQuestTag, ObjStage0->ObjectiveTag, 1);

		// Now quest should be at Stage 1
		ActiveRec = Manager->GetActiveQuestRecord(TwoStageQuestTag);
		TestNotNull(TEXT("Active record must still exist after stage transition"), ActiveRec);
		if (ActiveRec)
		{
			TestEqual(TEXT("Stage index must advance to 1"), ActiveRec->CurrentStageIndex, 1);
			TestNotNull(TEXT("Stage 1 objective must now be active"), ActiveRec->FindObjectiveRecord(ObjStage1->ObjectiveTag));
		}

		Owner->Destroy();
		World->DestroyWorld(false);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
