// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestTypes.h"
#include "GameplayObjectiveDefinition.h"
#include "GameplayQuestDefinition.h"
#include "Objectives/KillObjectiveDefinition.h"
#include "Objectives/CollectObjectiveDefinition.h"
#include "Objectives/InteractObjectiveDefinition.h"
#include "Objectives/ReachAreaObjectiveDefinition.h"
#include "Objectives/TimerObjectiveDefinition.h"
#include "Objectives/CompositeObjectiveDefinition.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Tests KillObjectiveDefinition target tag matching, context query, and yield calculation.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestKillConditionEvaluationTest,
	"GameplayQuest.Unit.Objectives.KillConditionEvaluation",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestKillConditionEvaluationTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UKillObjectiveDefinition* KillObj = NewObject<UKillObjectiveDefinition>();
	TestNotNull(TEXT("KillObjectiveDefinition must be instantiable"), KillObj);

	if (KillObj)
	{
		const FGameplayTag TargetGoblin = TAG_Target_Enemy_Goblin.GetTag();
		const FGameplayTag TargetOrc = TAG_Target_Enemy_Orc.GetTag();

		KillObj->ObjectiveTag = TAG_Quest_Objective_Status_Active.GetTag();
		KillObj->TargetTag = TargetGoblin;
		KillObj->RequiredCount = 5;

		// 1. Matching payload with TargetGoblin in context
		FGameplayQuestEventPayload MatchingPayload(TAG_Quest_Event_Kill.GetTag(), nullptr, 1);
		MatchingPayload.ContextTags.AddTag(TargetGoblin);

		TestTrue(TEXT("Matching target payload should be accepted"), KillObj->MatchesEvent(MatchingPayload));
		TestEqual(TEXT("Progress yield should equal 1"), KillObj->EvaluateProgressYield(MatchingPayload), 1);

		// 2. Non-matching target
		FGameplayQuestEventPayload NonMatchingPayload(TAG_Quest_Event_Kill.GetTag(), nullptr, 1);
		NonMatchingPayload.ContextTags.AddTag(TargetOrc);

		TestFalse(TEXT("Non-matching target payload should be rejected"), KillObj->MatchesEvent(NonMatchingPayload));

		// 3. Wrong channel payload
		FGameplayQuestEventPayload WrongChannelPayload(TAG_Quest_Event_Collect.GetTag(), nullptr, 1);
		WrongChannelPayload.ContextTags.AddTag(TargetGoblin);

		TestFalse(TEXT("Wrong event channel payload should be rejected"), KillObj->MatchesEvent(WrongChannelPayload));
	}

	return true;
}

/**
 * Verifies that an objective scoped to Zone.Dungeon rejects events stamped with Zone.Hub and accepts events stamped with Zone.Dungeon.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestZoneScopeFilteringTest,
	"GameplayQuest.Unit.Objectives.ZoneScopeFiltering",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestZoneScopeFilteringTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UKillObjectiveDefinition* KillObj = NewObject<UKillObjectiveDefinition>();
	TestNotNull(TEXT("KillObjectiveDefinition must be instantiable"), KillObj);

	if (KillObj)
	{
		const FGameplayTag ZoneDungeon = TAG_Zone_Dungeon_Depths.GetTag();
		const FGameplayTag ZoneHub = TAG_Zone_City_Hub.GetTag();

		KillObj->ObjectiveTag = TAG_Quest_Objective_Status_Active.GetTag();
		KillObj->ZoneScopeTag = ZoneDungeon;

		// 1. Event from Dungeon zone should match
		FGameplayQuestEventPayload DungeonPayload(TAG_Quest_Event_Kill.GetTag(), nullptr, 1);
		DungeonPayload.ZoneTag = ZoneDungeon;
		TestTrue(TEXT("Dungeon-stamped event should match Dungeon-scoped objective"), KillObj->MatchesEvent(DungeonPayload));

		// 2. Event from Hub zone should be rejected
		FGameplayQuestEventPayload HubPayload(TAG_Quest_Event_Kill.GetTag(), nullptr, 1);
		HubPayload.ZoneTag = ZoneHub;
		TestFalse(TEXT("Hub-stamped event should be rejected by Dungeon-scoped objective"), KillObj->MatchesEvent(HubPayload));

		// 3. Clear zone scope: objective accepts events from any zone
		KillObj->ZoneScopeTag = FGameplayTag();
		TestTrue(TEXT("Unscoped objective should accept Hub events"), KillObj->MatchesEvent(HubPayload));
		TestTrue(TEXT("Unscoped objective should accept Dungeon events"), KillObj->MatchesEvent(DungeonPayload));
	}

	return true;
}

/**
 * Tests CollectObjectiveDefinition item tag matching, quantity yield, and consumption flag.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestCollectConditionEvaluationTest,
	"GameplayQuest.Unit.Objectives.CollectConditionEvaluation",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestCollectConditionEvaluationTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UCollectObjectiveDefinition* CollectObj = NewObject<UCollectObjectiveDefinition>();
	TestNotNull(TEXT("CollectObjectiveDefinition must be instantiable"), CollectObj);

	if (CollectObj)
	{
		const FGameplayTag RelicTag = TAG_Item_Quest_Relic.GetTag();
		const FGameplayTag PotionTag = TAG_Item_Consumable_Potion.GetTag();

		CollectObj->ObjectiveTag = TAG_Quest_Objective_Status_Active.GetTag();
		CollectObj->ItemTag = RelicTag;
		CollectObj->RequiredCount = 3;
		CollectObj->bConsumeOnComplete = true;

		TestTrue(TEXT("bConsumeOnComplete should be true"), CollectObj->bConsumeOnComplete);

		// Event matching relic
		FGameplayQuestEventPayload CollectPayload(TAG_Quest_Event_Collect.GetTag(), nullptr, 2);
		CollectPayload.ContextTags.AddTag(RelicTag);

		TestTrue(TEXT("Relic collect event should match"), CollectObj->MatchesEvent(CollectPayload));
		TestEqual(TEXT("Progress yield should equal 2"), CollectObj->EvaluateProgressYield(CollectPayload), 2);

		// Event matching potion
		FGameplayQuestEventPayload PotionPayload(TAG_Quest_Event_Collect.GetTag(), nullptr, 1);
		PotionPayload.ContextTags.AddTag(PotionTag);

		TestFalse(TEXT("Potion collect event should be rejected"), CollectObj->MatchesEvent(PotionPayload));
	}

	return true;
}

/**
 * Tests TimerObjectiveDefinition duration parameters and event matching.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestZeroTickTimerExpirationTest,
	"GameplayQuest.Unit.Objectives.ZeroTickTimerExpiration",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestZeroTickTimerExpirationTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UTimerObjectiveDefinition* TimerObj = NewObject<UTimerObjectiveDefinition>();
	TestNotNull(TEXT("TimerObjectiveDefinition must be instantiable"), TimerObj);

	if (TimerObj)
	{
		TimerObj->ObjectiveTag = TAG_Quest_Objective_Status_Active.GetTag();
		TimerObj->DurationSeconds = 120.0f;
		TimerObj->bFailOnTimeout = true;

		TestEqual(TEXT("DurationSeconds should be 120"), TimerObj->DurationSeconds, 120.0f);
		TestTrue(TEXT("bFailOnTimeout should be true"), TimerObj->bFailOnTimeout);
		TestEqual(TEXT("Event channel should be TAG_Quest_Event_Timer"), TimerObj->GetEventChannelTag(), TAG_Quest_Event_Timer.GetTag());

		// Matching event
		FGameplayQuestEventPayload TimerPayload(TAG_Quest_Event_Timer.GetTag(), nullptr, 1);
		TimerPayload.ContextTags.AddTag(TAG_Quest_Objective_Status_Active.GetTag());

		TestTrue(TEXT("Timer event payload should match"), TimerObj->MatchesEvent(TimerPayload));
	}

	return true;
}

/**
 * Tests CompositeObjectiveDefinition AND / OR branching logic.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestCompositeConditionEvaluationTest,
	"GameplayQuest.Unit.Objectives.CompositeConditionEvaluation",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestCompositeConditionEvaluationTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UCompositeObjectiveDefinition* CompositeObj = NewObject<UCompositeObjectiveDefinition>();
	TestNotNull(TEXT("CompositeObjectiveDefinition must be instantiable"), CompositeObj);

	if (CompositeObj)
	{
		UKillObjectiveDefinition* ChildA = NewObject<UKillObjectiveDefinition>(CompositeObj);
		UCollectObjectiveDefinition* ChildB = NewObject<UCollectObjectiveDefinition>(CompositeObj);

		const FGameplayTag TagA = TAG_Quest_Objective_SampleA.GetTag();
		const FGameplayTag TagB = TAG_Quest_Objective_SampleB.GetTag();

		ChildA->ObjectiveTag = TagA;
		ChildB->ObjectiveTag = TagB;

		CompositeObj->SubObjectives.Add(ChildA);
		CompositeObj->SubObjectives.Add(ChildB);

		// 1. AllRequired (AND) mode
		CompositeObj->CompositeOperation = EGameplayQuestCompositeOperation::AllRequired;

		TSet<FGameplayTag> CompletedTags;
		CompletedTags.Add(TagA);
		TestFalse(TEXT("AND mode should fail when only ChildA is completed"), CompositeObj->EvaluateCompleted(CompletedTags));

		CompletedTags.Add(TagB);
		TestTrue(TEXT("AND mode should succeed when ChildA and ChildB are completed"), CompositeObj->EvaluateCompleted(CompletedTags));

		// 2. AnyRequired (OR) mode
		CompositeObj->CompositeOperation = EGameplayQuestCompositeOperation::AnyRequired;
		CompositeObj->RequiredCompletedCount = 1;

		CompletedTags.Empty();
		TestFalse(TEXT("OR mode should fail when nothing is completed"), CompositeObj->EvaluateCompleted(CompletedTags));

		CompletedTags.Add(TagB);
		TestTrue(TEXT("OR mode should succeed when at least one child is completed"), CompositeObj->EvaluateCompleted(CompletedTags));
	}

	return true;
}

/**
 * Validates FGameplayTagQuery prerequisite evaluation on UGameplayQuestDefinition.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestPrerequisitesTagQueryValidationTest,
	"GameplayQuest.Unit.Definitions.PrerequisitesTagQueryValidation",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestPrerequisitesTagQueryValidationTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UGameplayQuestDefinition* QuestDef = NewObject<UGameplayQuestDefinition>();
	TestNotNull(TEXT("QuestDefinition must be instantiable"), QuestDef);

	if (QuestDef)
	{
		const FGameplayTag CompletedPrereqQuestTag = TAG_Quest_Prereq_Completed.GetTag();
		const FGameplayTag RequiredLevelTag = TAG_Player_Level_10Plus.GetTag();

		// Build prerequisite query: Must have CompletedPrereqQuestTag AND RequiredLevelTag
		FGameplayTagContainer RequiredTags;
		RequiredTags.AddTag(CompletedPrereqQuestTag);
		RequiredTags.AddTag(RequiredLevelTag);

		QuestDef->PrerequisiteQuery = FGameplayTagQuery::MakeQuery_MatchAllTags(RequiredTags);

		// Test player with missing level
		FGameplayTagContainer PlayerTags;
		PlayerTags.AddTag(CompletedPrereqQuestTag);
		TestFalse(TEXT("Player without required level should be denied"), QuestDef->CanAcceptQuest(PlayerTags));

		// Test player with both required tags
		PlayerTags.AddTag(RequiredLevelTag);
		TestTrue(TEXT("Player with both prereq tags should be accepted"), QuestDef->CanAcceptQuest(PlayerTags));
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
