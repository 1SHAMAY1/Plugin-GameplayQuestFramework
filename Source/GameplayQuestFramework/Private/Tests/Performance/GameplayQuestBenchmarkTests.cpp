// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "GameplayQuestEventSubsystem.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestTypes.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestSaveData.h"
#include "HAL/PlatformTime.h"
#include "Tests/GameplayQuestTestMocks.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Benchmark test measuring raw event dispatch throughput across the inverted tag interest table.
 * Simulates high-density MMO / massive open world scale.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestEventDispatchBenchmarkTest,
	"GameplayQuest.Benchmark.EventDispatch.HighDensityThroughput",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestEventDispatchBenchmarkTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World must be created"), World);
	if (!World)
	{
		return false;
	}

	UGameplayQuestEventSubsystem* EventSubsystem = World->GetSubsystem<UGameplayQuestEventSubsystem>();
	TestNotNull(TEXT("EventSubsystem must be instantiated"), EventSubsystem);

	const int32 ListenerCount = 1000;
	const int32 EventDispatchCount = 10000;

	TArray<FGameplayTag> TestChannels;
	TestChannels.Add(TAG_Quest_Event_Kill.GetTag());
	TestChannels.Add(TAG_Quest_Event_Collect.GetTag());
	TestChannels.Add(TAG_Quest_Event_Interact.GetTag());
	TestChannels.Add(TAG_Quest_Event_ReachArea.GetTag());

	TArray<AMockQuestOwnerActor*> SpawnedActors;
	SpawnedActors.Reserve(ListenerCount);

	// Register 1,000 listeners distributed across channels
	for (int32 i = 0; i < ListenerCount; ++i)
	{
		AMockQuestOwnerActor* Actor = World->SpawnActor<AMockQuestOwnerActor>();
		SpawnedActors.Add(Actor);

		const FGameplayTag Channel = TestChannels[i % TestChannels.Num()];
		EventSubsystem->RegisterEventListener(Channel, Actor->MockManagerComponent);
	}

	FGameplayQuestEventPayload SamplePayload;
	SamplePayload.EventTag = TAG_Quest_Event_Kill.GetTag();
	SamplePayload.ContextTags.AddTag(TAG_Target_Enemy_Goblin.GetTag());
	SamplePayload.Quantity = 1;

	// Warmup
	EventSubsystem->BroadcastQuestEvent(SamplePayload);

	// Benchmark: 10,000 dispatches
	const double StartTime = FPlatformTime::Seconds();

	for (int32 i = 0; i < EventDispatchCount; ++i)
	{
		EventSubsystem->BroadcastQuestEvent(SamplePayload);
	}

	const double EndTime = FPlatformTime::Seconds();
	const double ElapsedSeconds = EndTime - StartTime;
	const double MicrosecondsPerDispatch = (ElapsedSeconds / (double)EventDispatchCount) * 1000000.0;

	UE_LOG(LogTemp, Display, TEXT("[Benchmark] Broadcast %d events across %d listeners in %.4f seconds (%.2f us/dispatch)"),
		EventDispatchCount, ListenerCount, ElapsedSeconds, MicrosecondsPerDispatch);

	// Performance SLA: Must execute 10,000 dispatches across 1,000 listeners in less than 500 ms (0.5s)
	TestTrue(TEXT("10,000 event dispatches across 1000 registered listeners must complete within 500ms"), ElapsedSeconds < 0.5);

	// Cleanup
	for (AMockQuestOwnerActor* Actor : SpawnedActors)
	{
		if (Actor)
		{
			Actor->Destroy();
		}
	}
	World->DestroyWorld(false);

	return true;
}

/**
 * Benchmark test measuring binary vs JSON serialization throughput for large save state bundles.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestPersistenceBenchmarkTest,
	"GameplayQuest.Benchmark.Persistence.SaveLoadThroughput",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestPersistenceBenchmarkTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	FGameplayQuestSaveData SaveData;
	SaveData.CharacterGuid = FGuid::NewGuid();
	SaveData.SchemaVersion = 1;

	// Populate 500 active quests with objectives
	for (int32 q = 0; q < 500; ++q)
	{
		FGameplayQuestSaveRecord QuestRec;
		QuestRec.QuestTag = TAG_Quest_Progression_Sequential.GetTag();
		QuestRec.StatusTag = TAG_Quest_Status_Active.GetTag();
		QuestRec.CurrentStageIndex = 2;

		for (int32 obj = 0; obj < 4; ++obj)
		{
			FGameplayObjectiveSaveRecord ObjRec;
			ObjRec.ObjectiveTag = (obj % 2 == 0) ? TAG_Quest_Objective_SampleA.GetTag() : TAG_Quest_Objective_SampleB.GetTag();
			ObjRec.StatusTag = TAG_Quest_Objective_Status_Active.GetTag();
			ObjRec.CurrentProgress = 15;
			ObjRec.RequiredCount = 20;
			QuestRec.Objectives.Add(ObjRec);
		}

		SaveData.ActiveQuests.Add(QuestRec);
	}

	// 1. Binary Benchmark
	const double BinaryStart = FPlatformTime::Seconds();
	TArray<uint8> BinaryBuffer;
	SaveData.ExportToBinary(BinaryBuffer);
	TestTrue(TEXT("Binary buffer must not be empty"), BinaryBuffer.Num() > 0);

	FGameplayQuestSaveData LoadedBinaryData;
	const bool bBinImport = LoadedBinaryData.ImportFromBinary(BinaryBuffer);
	TestTrue(TEXT("Binary import must succeed"), bBinImport);
	const double BinaryEnd = FPlatformTime::Seconds();
	const double BinaryElapsedMs = (BinaryEnd - BinaryStart) * 1000.0;

	TestEqual(TEXT("Binary loaded count must match"), LoadedBinaryData.ActiveQuests.Num(), 500);

	// 2. JSON Benchmark
	const double JsonStart = FPlatformTime::Seconds();
	FString JsonString;
	const bool bJsonExport = SaveData.ExportToJson(JsonString);
	TestTrue(TEXT("JSON export must succeed"), bJsonExport);

	FGameplayQuestSaveData LoadedJsonData;
	const bool bJsonImport = LoadedJsonData.ImportFromJson(JsonString);
	TestTrue(TEXT("JSON import must succeed"), bJsonImport);
	const double JsonEnd = FPlatformTime::Seconds();
	const double JsonElapsedMs = (JsonEnd - JsonStart) * 1000.0;

	TestEqual(TEXT("JSON loaded count must match"), LoadedJsonData.ActiveQuests.Num(), 500);

	UE_LOG(LogTemp, Display, TEXT("[Benchmark] 500 Quests (2000 Objectives) -> Binary: %.2f ms (%d bytes), JSON: %.2f ms (%d bytes)"),
		BinaryElapsedMs, BinaryBuffer.Num(), JsonElapsedMs, JsonString.Len());

	// Binary should be under 50ms for 500 full quest states
	TestTrue(TEXT("Binary roundtrip for 500 quests must be < 50ms"), BinaryElapsedMs < 50.0);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
