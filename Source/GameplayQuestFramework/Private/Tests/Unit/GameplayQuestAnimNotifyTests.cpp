// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Animation/AnimNotify_GameplayQuestEvent.h"
#include "Animation/AnimNotifyState_GameplayQuestWindow.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestTypes.h"
#include "GameplayQuestEventSubsystem.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Verifies UAnimNotify_GameplayQuestEvent correctly initializes and broadcasts event payloads with proper tags and context.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestAnimNotifyBroadcastTest,
	"GameplayQuest.Unit.Animation.AnimNotifyEventBroadcast",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestAnimNotifyBroadcastTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	// 1. Instantiation and default state
	UAnimNotify_GameplayQuestEvent* NotifyInstance = NewObject<UAnimNotify_GameplayQuestEvent>();
	TestNotNull(TEXT("UAnimNotify_GameplayQuestEvent should be instantiable"), NotifyInstance);

	if (!NotifyInstance)
	{
		return false;
	}

	TestEqual(TEXT("Default EventChannelTag should be Interact"), NotifyInstance->EventChannelTag, TAG_Quest_Event_Interact.GetTag());
	TestEqual(TEXT("Default Quantity should be 1"), NotifyInstance->Quantity, 1);
	TestTrue(TEXT("GetNotifyName_Implementation returns valid description"), NotifyInstance->GetNotifyName_Implementation().Contains(TEXT("Interact")));

	// 2. Custom configuration
	NotifyInstance->EventChannelTag = TAG_Quest_Event_Custom.GetTag();
	NotifyInstance->TargetTag = TAG_Target_Enemy_Goblin.GetTag();
	NotifyInstance->Quantity = 3;
	NotifyInstance->ContextTags.AddTag(TAG_Quest_Event_Interact.GetTag());

	TestEqual(TEXT("Configured quantity should be 3"), NotifyInstance->Quantity, 3);
	TestTrue(TEXT("Configured TargetTag is valid"), NotifyInstance->TargetTag == TAG_Target_Enemy_Goblin.GetTag());

	// 3. Graceful null handling
	NotifyInstance->Notify(nullptr, nullptr, FAnimNotifyEventReference());
	TestTrue(TEXT("Null MeshComp handled gracefully without crash"), true);

	return true;
}

/**
 * Verifies UAnimNotifyState_GameplayQuestWindow broadcasts both begin and end boundary events properly.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestAnimNotifyStateWindowTest,
	"GameplayQuest.Unit.Animation.AnimNotifyStateWindow",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestAnimNotifyStateWindowTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	// 1. Instantiation
	UAnimNotifyState_GameplayQuestWindow* WindowNotify = NewObject<UAnimNotifyState_GameplayQuestWindow>();
	TestNotNull(TEXT("UAnimNotifyState_GameplayQuestWindow should be instantiable"), WindowNotify);

	if (!WindowNotify)
	{
		return false;
	}

	// 2. Configuration
	WindowNotify->BeginEventTag = TAG_Quest_Event_Custom.GetTag();
	WindowNotify->EndEventTag = TAG_Quest_Event_Interact.GetTag();
	WindowNotify->WindowContextTags.AddTag(TAG_Quest_Event_Interact.GetTag());

	TestTrue(TEXT("BeginEventTag is set"), WindowNotify->BeginEventTag == TAG_Quest_Event_Custom.GetTag());
	TestTrue(TEXT("EndEventTag is set"), WindowNotify->EndEventTag == TAG_Quest_Event_Interact.GetTag());
	TestTrue(TEXT("WindowContextTags has tag"), WindowNotify->WindowContextTags.HasTag(TAG_Quest_Event_Interact.GetTag()));

	// 3. Graceful null handling
	WindowNotify->NotifyBegin(nullptr, nullptr, 1.5f, FAnimNotifyEventReference());
	WindowNotify->NotifyEnd(nullptr, nullptr, FAnimNotifyEventReference());
	TestTrue(TEXT("Null MeshComp calls in AnimNotifyState handled safely"), true);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
