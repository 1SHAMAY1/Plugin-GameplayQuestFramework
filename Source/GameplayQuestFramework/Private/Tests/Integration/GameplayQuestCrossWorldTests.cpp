// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "GameplayQuestDataSubsystem.h"
#include "GameplayQuestEventSubsystem.h"
#include "GameplayQuestTriggerVolume.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestTypes.h"
#include "Tests/GameplayQuestTestMocks.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Simulates cross-world level transition (World A -> World B), verifies active quest stash and full state hydration.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestCrossLevelTravelHydrationTest,
	"GameplayQuest.Integration.World.CrossLevelTravelHydration",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestCrossLevelTravelHydrationTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	// Create shared GameInstance simulating persistent game session across worlds
	UGameInstance* GameInstance = NewObject<UGameInstance>();
	TestNotNull(TEXT("GameInstance must be valid"), GameInstance);

	if (GameInstance)
	{
		UGameplayQuestDataSubsystem* DataSubsystem = NewObject<UGameplayQuestDataSubsystem>(GameInstance);
		TestNotNull(TEXT("GameplayQuestDataSubsystem must be valid"), DataSubsystem);

		// 1. In World A (e.g. Zone.Town), Player completes partial objective and initiates level transition
		const FGuid PlayerGuid = FGuid::NewGuid();
		const TArray<uint8> WorldAQuestBlob = { 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF };

		// Cache quest state into GameInstance bridge before Map Unload
		DataSubsystem->CachePlayerQuestsForTravel(PlayerGuid, WorldAQuestBlob);
		TestTrue(TEXT("Travel cache must hold player data"), DataSubsystem->HasTravelCacheForPlayer(PlayerGuid));

		// 2. Simulate World B loading and zone setup
		UWorld* WorldB = UWorld::CreateWorld(EWorldType::Game, false);
		TestNotNull(TEXT("WorldB must be created"), WorldB);

		if (WorldB)
		{
			UGameplayQuestEventSubsystem* EventSubsystemB = WorldB->GetSubsystem<UGameplayQuestEventSubsystem>();
			TestNotNull(TEXT("WorldB EventSubsystem must be valid"), EventSubsystemB);

			// Stamp World B as Dungeon zone
			EventSubsystemB->SetWorldZoneTag(TAG_Zone_Default.GetTag());
			TestTrue(TEXT("WorldB zone tag must match"), EventSubsystemB->GetWorldZoneTag() == TAG_Zone_Default.GetTag());

			// 3. Player arrives in World B and hydrates quest state from GameInstance cache
			TArray<uint8> RestoredBlob;
			const bool bHydrated = DataSubsystem->RestorePlayerQuestsFromTravel(PlayerGuid, RestoredBlob);
			TestTrue(TEXT("Hydration upon arrival in World B must succeed"), bHydrated);
			TestEqual(TEXT("Restored quest blob size must match exactly"), RestoredBlob.Num(), WorldAQuestBlob.Num());
			TestEqual(TEXT("First byte must match World A data"), RestoredBlob[0], (uint8)0xAA);
			TestEqual(TEXT("Last byte must match World A data"), RestoredBlob[5], (uint8)0xFF);

			// 4. Cache must be consumed so duplicate hydrations don't reapply stale state
			TestFalse(TEXT("Player travel cache should now be cleared"), DataSubsystem->HasTravelCacheForPlayer(PlayerGuid));

			WorldB->DestroyWorld(false);
		}
	}

	return true;
}

/**
 * Validates trigger volume detects overlapping actor and dispatches zone-stamped area event.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestTriggerVolumeAuthorityTest,
	"GameplayQuest.Integration.World.TriggerVolumeOverlapAuthority",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestTriggerVolumeAuthorityTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World must be created"), World);

	if (World)
	{
		UGameplayQuestEventSubsystem* EventSubsystem = World->GetSubsystem<UGameplayQuestEventSubsystem>();
		TestNotNull(TEXT("EventSubsystem must be valid"), EventSubsystem);

		AGameplayQuestTriggerVolume* Trigger = World->SpawnActor<AGameplayQuestTriggerVolume>();
		AActor* OverlappingPawn = World->SpawnActor<AActor>();
		TestNotNull(TEXT("Trigger must spawn"), Trigger);
		TestNotNull(TEXT("OverlappingPawn must spawn"), OverlappingPawn);

		// Configure trigger
		Trigger->AreaTag = TAG_Zone_Default.GetTag();
		Trigger->bTriggerOncePerActor = true;

		// First trigger should succeed
		const bool bFirstTrigger = Trigger->TriggerForActor(OverlappingPawn);
		TestTrue(TEXT("First trigger for actor should succeed"), bFirstTrigger);

		// Duplicate trigger for same actor when bTriggerOncePerActor is true should be rejected
		const bool bSecondTrigger = Trigger->TriggerForActor(OverlappingPawn);
		TestFalse(TEXT("Second trigger for same actor should be rejected"), bSecondTrigger);

		// After reset, trigger should be accepted again
		Trigger->ResetTriggerState();
		const bool bAfterResetTrigger = Trigger->TriggerForActor(OverlappingPawn);
		TestTrue(TEXT("Trigger after reset should succeed"), bAfterResetTrigger);

		Trigger->Destroy();
		OverlappingPawn->Destroy();
		World->DestroyWorld(false);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
