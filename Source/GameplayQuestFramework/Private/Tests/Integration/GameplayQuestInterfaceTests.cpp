// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "GameplayQuestFunctionLibrary.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestTags.h"
#include "Tests/GameplayQuestTestMocks.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestManagerResolutionTest,
	"GameplayQuest.Integration.Interfaces.ManagerResolutionContract",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestManagerResolutionTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World must be created"), World);

	if (World)
	{
		// 1. Direct Interface resolution
		AMockQuestOwnerActor* OwnerActor = World->SpawnActor<AMockQuestOwnerActor>();
		TestNotNull(TEXT("OwnerActor must spawn"), OwnerActor);

		UGameplayQuestManagerComponent* ResolvedComp = UGameplayQuestFunctionLibrary::GetQuestManager(OwnerActor);
		TestNotNull(TEXT("GetQuestManager must resolve via IGameplayQuestManagerInterface"), ResolvedComp);
		TestEqual(TEXT("Resolved component must match MockManagerComponent"), ResolvedComp, OwnerActor->MockManagerComponent.Get());

		// 2. Direct component fallback resolution on a plain actor
		AActor* PlainActor = World->SpawnActor<AActor>();
		TestNotNull(TEXT("PlainActor must spawn"), PlainActor);
		UGameplayQuestManagerComponent* DirectComp = NewObject<UGameplayQuestManagerComponent>(PlainActor);
		DirectComp->RegisterComponent();

		UGameplayQuestManagerComponent* FallbackResolved = UGameplayQuestFunctionLibrary::GetQuestManager(PlainActor);
		TestNotNull(TEXT("GetQuestManager must fallback to FindComponentByClass"), FallbackResolved);
		TestEqual(TEXT("Fallback component must match DirectComp"), FallbackResolved, DirectComp);

		// 3. Null actor query
		TestNull(TEXT("Null actor must return null manager"), UGameplayQuestFunctionLibrary::GetQuestManager(nullptr));

		OwnerActor->Destroy();
		PlainActor->Destroy();
		World->DestroyWorld(false);
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestInteractableContractTest,
	"GameplayQuest.Integration.Interfaces.InteractableContract",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestInteractableContractTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World must be created"), World);

	if (World)
	{
		AMockInteractableActor* ChestActor = World->SpawnActor<AMockInteractableActor>();
		AActor* InteractorActor = World->SpawnActor<AActor>();
		TestNotNull(TEXT("ChestActor must spawn"), ChestActor);
		TestNotNull(TEXT("InteractorActor must spawn"), InteractorActor);

		ChestActor->InteractTag = GameplayQuestTags::TAG_Quest_Event_Interact.GetTag();
		ChestActor->bAllowInteract = true;

		IGameplayQuestInteractable* Interactable = Cast<IGameplayQuestInteractable>(ChestActor);
		TestNotNull(TEXT("ChestActor must implement IGameplayQuestInteractable"), Interactable);

		if (Interactable)
		{
			// Tag contract
			FGameplayTag Tag = IGameplayQuestInteractable::Execute_GetInteractableTag(ChestActor);
			if (!Tag.IsValid())
			{
				Tag = Interactable->GetInteractableTag_Implementation();
			}
			TestTrue(TEXT("Interactable must return valid tag"), Tag.IsValid());

			// CanInteract contract
			bool bCan = IGameplayQuestInteractable::Execute_CanInteract(ChestActor, InteractorActor);
			if (!bCan)
			{
				bCan = Interactable->CanInteract_Implementation(InteractorActor);
			}
			TestTrue(TEXT("Default interaction must be allowed"), bCan);

			ChestActor->bAllowInteract = false;
			bool bCanGated = IGameplayQuestInteractable::Execute_CanInteract(ChestActor, InteractorActor);
			if (bCanGated)
			{
				bCanGated = Interactable->CanInteract_Implementation(InteractorActor);
			}
			TestFalse(TEXT("Gated interaction must be denied"), bCanGated);

			// OnQuestInteraction contract
			TestFalse(TEXT("Should not be interacted with initially"), ChestActor->bWasInteractedWith);
			Interactable->OnQuestInteraction_Implementation(InteractorActor);
			TestTrue(TEXT("OnQuestInteraction should flag bWasInteractedWith"), ChestActor->bWasInteractedWith);
		}

		ChestActor->Destroy();
		InteractorActor->Destroy();
		World->DestroyWorld(false);
	}

	return true;
}

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestFunctionLibraryNullSafetyTest,
	"GameplayQuest.Integration.Interfaces.FunctionLibraryNullSafety",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestFunctionLibraryNullSafetyTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	// Broadcast calls with null WorldContextObject must not crash
	UGameplayQuestFunctionLibrary::BroadcastKillEvent(nullptr, nullptr, nullptr, TAG_Quest_Event_Kill.GetTag());
	UGameplayQuestFunctionLibrary::BroadcastCollectEvent(nullptr, nullptr, TAG_Quest_Event_Collect.GetTag(), 1);
	UGameplayQuestFunctionLibrary::BroadcastInteractEvent(nullptr, nullptr, nullptr, TAG_Quest_Event_Interact.GetTag());
	UGameplayQuestFunctionLibrary::BroadcastAreaReachedEvent(nullptr, nullptr, TAG_Quest_Event_ReachArea.GetTag());

	FGameplayQuestEventPayload EmptyPayload;
	UGameplayQuestFunctionLibrary::BroadcastQuestEvent(nullptr, EmptyPayload);

	// Status query on null actor must return NotStarted without crashing
	FGameplayTag Status = UGameplayQuestFunctionLibrary::GetQuestStatus(nullptr, TAG_Quest_Status_Active.GetTag());
	TestTrue(TEXT("Null actor must return NotStarted status"), Status == TAG_Quest_Status_NotStarted.GetTag());

	TestTrue(
		TEXT("HasQuestStatus on null actor should return true for NotStarted"),
		UGameplayQuestFunctionLibrary::HasQuestStatus(nullptr, TAG_Quest_Status_Active.GetTag(), TAG_Quest_Status_NotStarted.GetTag())
	);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
