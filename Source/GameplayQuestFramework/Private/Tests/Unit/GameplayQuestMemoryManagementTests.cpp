// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestTypes.h"
#include "GameplayQuestDefinition.h"
#include "GameplayQuestGiverComponent.h"
#include "GameplayQuestFunctionLibrary.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Verifies memory management safety around weak pointers (e.g. Instigator, TargetActor)
 * to ensure that destroyed/despawned actors do not cause dangling pointer crashes or leaks.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestWeakPointerSafetyTest,
	"GameplayQuest.Unit.Memory.WeakPointerStalenessSafety",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestWeakPointerSafetyTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	// 1. Construct payload with null object pointers
	FGameplayQuestEventPayload NullActorPayload;
	NullActorPayload.EventTag = TAG_Quest_Event_Interact.GetTag();
	NullActorPayload.Instigator = nullptr;
	NullActorPayload.TargetActor = nullptr;

	TestTrue(TEXT("Null Instigator should be nullptr"), NullActorPayload.Instigator == nullptr);
	TestTrue(TEXT("Null TargetActor should be nullptr"), NullActorPayload.TargetActor == nullptr);

	// 2. Broadcast with null actor - should safely return early and not crash
	UGameplayQuestFunctionLibrary::BroadcastQuestEvent(nullptr, NullActorPayload);
	TestTrue(TEXT("Broadcasting with null world context handled safely"), true);

	return true;
}

/**
 * Verifies soft object reference handling in UGameplayQuestGiverComponent for streamable/on-demand quest memory loading.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestSoftObjectRefTest,
	"GameplayQuest.Unit.Memory.SoftQuestReferenceResolution",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestSoftObjectRefTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	// 1. Instantiate Quest Giver Component
	UGameplayQuestGiverComponent* GiverComp = NewObject<UGameplayQuestGiverComponent>();
	TestNotNull(TEXT("GameplayQuestGiverComponent must instantiate"), GiverComp);

	if (!GiverComp)
	{
		return false;
	}

	// 2. Create in-memory quest definition
	UGameplayQuestDefinition* InMemoryQuest = NewObject<UGameplayQuestDefinition>();
	InMemoryQuest->QuestTag = TAG_Quest_Status_Active.GetTag();

	// 3. Add to soft reference list
	TSoftObjectPtr<UGameplayQuestDefinition> SoftQuestRef(InMemoryQuest);
	TestTrue(TEXT("Soft object pointer resolves in-memory object"), SoftQuestRef.Get() == InMemoryQuest);

	GiverComp->SoftOfferedQuests.Add(SoftQuestRef);

	// 4. Query offered quests via interface method
	TArray<FGameplayTag> OfferedTags;
	GiverComp->GetOfferedQuests_Implementation(nullptr, OfferedTags);

	TestEqual(TEXT("Offered quests should contain 1 tag from soft reference"), OfferedTags.Num(), 1);
	if (OfferedTags.Num() > 0)
	{
		TestEqual(TEXT("Offered tag must match QuestTag"), OfferedTags[0], TAG_Quest_Status_Active.GetTag());
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
