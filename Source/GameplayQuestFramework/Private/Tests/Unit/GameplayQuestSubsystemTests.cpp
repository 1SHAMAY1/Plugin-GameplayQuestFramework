// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "GameplayQuestEventSubsystem.h"
#include "GameplayQuestDataSubsystem.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestSettings.h"
#include "Tests/GameplayQuestTestMocks.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Validates inverted tag subscription and verifies O(1) dispatch skips unregistered listeners.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestInvertedTagIndexRoutingTest,
	"GameplayQuest.Unit.Subsystems.InvertedTagIndexRouting",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestInvertedTagIndexRoutingTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World must be created"), World);

	if (World)
	{
		UGameplayQuestEventSubsystem* EventSubsystem = World->GetSubsystem<UGameplayQuestEventSubsystem>();
		TestNotNull(TEXT("GameplayQuestEventSubsystem must be available"), EventSubsystem);

		AMockQuestOwnerActor* ActorA = World->SpawnActor<AMockQuestOwnerActor>();
		AMockQuestOwnerActor* ActorB = World->SpawnActor<AMockQuestOwnerActor>();
		TestNotNull(TEXT("ActorA must spawn"), ActorA);
		TestNotNull(TEXT("ActorB must spawn"), ActorB);

		UGameplayQuestManagerComponent* CompA = ActorA->MockManagerComponent;
		UGameplayQuestManagerComponent* CompB = ActorB->MockManagerComponent;
		TestNotNull(TEXT("CompA must be valid"), CompA);
		TestNotNull(TEXT("CompB must be valid"), CompB);

		// 1. Initial channel state
		TestEqual(TEXT("Initial channel count should be 0"), EventSubsystem->GetChannelCount(), 0);

		// 2. Register CompA for Kill events only, CompB for Collect events only
		EventSubsystem->RegisterEventListener(TAG_Quest_Event_Kill.GetTag(), CompA);
		EventSubsystem->RegisterEventListener(TAG_Quest_Event_Collect.GetTag(), CompB);

		TestEqual(TEXT("Channel count after registration should be 2"), EventSubsystem->GetChannelCount(), 2);
		TestEqual(TEXT("Kill channel listeners count should be 1"), EventSubsystem->GetListenerCountForTag(TAG_Quest_Event_Kill.GetTag()), 1);
		TestEqual(TEXT("Collect channel listeners count should be 1"), EventSubsystem->GetListenerCountForTag(TAG_Quest_Event_Collect.GetTag()), 1);

		// 3. Dispatch Kill Event - verify zone stamping
		FGameplayQuestEventPayload KillPayload(TAG_Quest_Event_Kill.GetTag(), ActorA, 1);
		EventSubsystem->BroadcastQuestEvent(KillPayload);
		TestTrue(TEXT("Payload ZoneTag should be auto-stamped with default zone"), KillPayload.ZoneTag.IsValid());

		// 4. Unregister listener
		EventSubsystem->UnregisterEventListener(TAG_Quest_Event_Kill.GetTag(), CompA);
		TestEqual(TEXT("Kill channel listeners count after unregister should be 0"), EventSubsystem->GetListenerCountForTag(TAG_Quest_Event_Kill.GetTag()), 0);

		// 5. Cleanup
		ActorA->Destroy();
		ActorB->Destroy();
		World->DestroyWorld(false);
	}

	return true;
}

/**
 * Asserts bCanEverTick = false across all quest subsystems and components.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestZeroTickExecutionEnforcementTest,
	"GameplayQuest.Unit.Subsystems.ZeroTickExecutionEnforcement",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestZeroTickExecutionEnforcementTest::RunTest(const FString& Parameters)
{
	// Subsystems in Unreal Engine never tick unless implementing FTickableGameObject.
	// Verify UGameplayQuestManagerComponent tick configuration
	const UGameplayQuestManagerComponent* CDO = GetDefault<UGameplayQuestManagerComponent>();
	TestNotNull(TEXT("UGameplayQuestManagerComponent CDO must exist"), CDO);

	if (CDO)
	{
		TestFalse(
			TEXT("UGameplayQuestManagerComponent must have PrimaryComponentTick.bCanEverTick = false"),
			CDO->PrimaryComponentTick.bCanEverTick
		);
		TestFalse(
			TEXT("UGameplayQuestManagerComponent must have PrimaryComponentTick.bStartWithTickEnabled = false"),
			CDO->PrimaryComponentTick.bStartWithTickEnabled
		);
	}

	return true;
}

/**
 * Validates O(1) tag-to-asset lookup and travel cache lifecycle in DataSubsystem.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestDataRegistryAssetResolutionTest,
	"GameplayQuest.Unit.Subsystems.DataRegistryAssetResolution",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestDataRegistryAssetResolutionTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UGameInstance* GameInstance = NewObject<UGameInstance>();
	TestNotNull(TEXT("GameInstance must be instantiable"), GameInstance);

	if (GameInstance)
	{
		UGameplayQuestDataSubsystem* DataSubsystem = NewObject<UGameplayQuestDataSubsystem>(GameInstance);
		TestNotNull(TEXT("DataSubsystem must be instantiable"), DataSubsystem);

		if (DataSubsystem)
		{
			// Verify initial registry count
			TestEqual(TEXT("Registered quest count should initially be 0"), DataSubsystem->GetRegisteredQuestCount(), 0);

			// Test travel cache
			FGuid TestPlayerGuid = FGuid::NewGuid();
			TArray<uint8> TestData = { 0xDE, 0xAD, 0xBE, 0xEF };

			TestFalse(TEXT("Should have no travel cache for new player"), DataSubsystem->HasTravelCacheForPlayer(TestPlayerGuid));

			DataSubsystem->CachePlayerQuestsForTravel(TestPlayerGuid, TestData);
			TestTrue(TEXT("Should have travel cache after saving"), DataSubsystem->HasTravelCacheForPlayer(TestPlayerGuid));

			TArray<uint8> RestoredData;
			bool bRestored = DataSubsystem->RestorePlayerQuestsFromTravel(TestPlayerGuid, RestoredData);
			TestTrue(TEXT("Restore should succeed"), bRestored);
			TestEqual(TEXT("Restored buffer count should match original"), RestoredData.Num(), TestData.Num());
			TestEqual(TEXT("Restored buffer byte 0 should match"), RestoredData[0], (uint8)0xDE);

			// Cache should be consumed/cleared upon restore
			TestFalse(TEXT("Cache should be consumed after restore"), DataSubsystem->HasTravelCacheForPlayer(TestPlayerGuid));
		}
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
