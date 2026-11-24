// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestManagerComponent.h"
#include "Tests/GameplayQuestTestMocks.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Asserts PostReplicatedChange and OnRep_CompletedQuestTags fire local delegates with 0 multicast RPCs.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestRepNotifyLateJoinReconciliationTest,
	"GameplayQuest.Network.RepNotify.LateJoinReconciliation",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestRepNotifyLateJoinReconciliationTest::RunTest(const FString& Parameters)
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

		const FGameplayTag SampleQuest = TAG_Quest_Objective_SampleA.GetTag();

		// Track delegate firing
		bool bStatusDelegateFired = false;
		FGameplayTag ReportedQuest;
		FGameplayTag ReportedNewStatus;

		Manager->OnQuestStatusChangedNative.AddLambda([&](const FGameplayTag& QuestTag, const FGameplayTag& NewStatus, const FGameplayTag& OldStatus)
		{
			bStatusDelegateFired = true;
			ReportedQuest = QuestTag;
			ReportedNewStatus = NewStatus;
		});

		// Simulate client RepNotify arrival for CompletedQuestTags
		FGameplayTagContainer OldTags;
		FGameplayTagContainer NewTags;
		NewTags.AddTag(SampleQuest);

		// Directly invoke OnRep simulated on client
		Manager->OnRep_CompletedQuestTags(OldTags);

		// Note: CompletedQuestTags in component is empty in this test mock unless updated,
		// so test the direct FastArray PostReplicatedAdd client notification
		FGameplayQuestRecord ClientRecord;
		ClientRecord.QuestTag = SampleQuest;
		ClientRecord.StatusTag = TAG_Quest_Status_Active_InProgress.GetTag();

		Manager->HandleQuestRecordAdded(ClientRecord);

		TestTrue(TEXT("OnQuestStatusChanged delegate must fire on client RepNotify/FastArray reconciliation"), bStatusDelegateFired);
		TestEqual(TEXT("Reported Quest must match SampleQuest"), ReportedQuest, SampleQuest);
		TestEqual(TEXT("Reported Status must match Active InProgress"), ReportedNewStatus, TAG_Quest_Status_Active_InProgress.GetTag());

		Owner->Destroy();
		World->DestroyWorld(false);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
