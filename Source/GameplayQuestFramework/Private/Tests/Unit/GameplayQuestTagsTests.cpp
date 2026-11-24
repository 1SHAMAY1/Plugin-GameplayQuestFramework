// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GameplayQuestTags.h"
#include "GameplayTagsManager.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestTagsTests,
	"GameplayQuest.Unit.Tags.NativeTaxonomyRegistration",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestTagsTests::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	// 1. Verify Quest Lifecycle Status Tags
	TestTrue(TEXT("TAG_Quest_Status_NotStarted must be valid"), TAG_Quest_Status_NotStarted.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Status_Active must be valid"), TAG_Quest_Status_Active.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Status_Active_InProgress must be valid"), TAG_Quest_Status_Active_InProgress.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Status_Active_ReadyToTurnIn must be valid"), TAG_Quest_Status_Active_ReadyToTurnIn.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Status_Completed must be valid"), TAG_Quest_Status_Completed.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Status_Failed must be valid"), TAG_Quest_Status_Failed.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Status_Failed_Timeout must be valid"), TAG_Quest_Status_Failed_Timeout.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Status_Failed_ConditionFailed must be valid"), TAG_Quest_Status_Failed_ConditionFailed.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Status_Abandoned must be valid"), TAG_Quest_Status_Abandoned.GetTag().IsValid());

	// Hierarchy check: Active.InProgress must match parent Active
	TestTrue(
		TEXT("TAG_Quest_Status_Active_InProgress must match parent TAG_Quest_Status_Active"),
		TAG_Quest_Status_Active_InProgress.GetTag().MatchesTag(TAG_Quest_Status_Active.GetTag())
	);

	// 2. Verify Objective Status Tags
	TestTrue(TEXT("TAG_Quest_Objective_Status_Inactive must be valid"), TAG_Quest_Objective_Status_Inactive.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Objective_Status_Active must be valid"), TAG_Quest_Objective_Status_Active.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Objective_Status_Completed must be valid"), TAG_Quest_Objective_Status_Completed.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Objective_Status_Failed must be valid"), TAG_Quest_Objective_Status_Failed.GetTag().IsValid());

	// 3. Verify Multiplayer Sharing Policy Tags
	TestTrue(TEXT("TAG_Quest_Policy_Sharing_SoloOnly must be valid"), TAG_Quest_Policy_Sharing_SoloOnly.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Policy_Sharing_PartyUniform must be valid"), TAG_Quest_Policy_Sharing_PartyUniform.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Policy_Sharing_PartyProximity must be valid"), TAG_Quest_Policy_Sharing_PartyProximity.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Policy_Sharing_WorldShared must be valid"), TAG_Quest_Policy_Sharing_WorldShared.GetTag().IsValid());

	// 4. Verify Progression Tags
	TestTrue(TEXT("TAG_Quest_Progression_Sequential must be valid"), TAG_Quest_Progression_Sequential.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Progression_Concurrent must be valid"), TAG_Quest_Progression_Concurrent.GetTag().IsValid());

	// 5. Verify Event Channel Tags
	TestTrue(TEXT("TAG_Quest_Event_Kill must be valid"), TAG_Quest_Event_Kill.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Event_Collect must be valid"), TAG_Quest_Event_Collect.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Event_Interact must be valid"), TAG_Quest_Event_Interact.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Event_ReachArea must be valid"), TAG_Quest_Event_ReachArea.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Event_Timer must be valid"), TAG_Quest_Event_Timer.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Event_Custom must be valid"), TAG_Quest_Event_Custom.GetTag().IsValid());

	// 6. Verify Zone Tag
	TestTrue(TEXT("TAG_Zone_Default must be valid"), TAG_Zone_Default.GetTag().IsValid());

	// 7. Verify Quest Giver States
	TestTrue(TEXT("TAG_Quest_Giver_None must be valid"), TAG_Quest_Giver_None.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Giver_Available must be valid"), TAG_Quest_Giver_Available.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Giver_InProgress must be valid"), TAG_Quest_Giver_InProgress.GetTag().IsValid());
	TestTrue(TEXT("TAG_Quest_Giver_ReadyToTurnIn must be valid"), TAG_Quest_Giver_ReadyToTurnIn.GetTag().IsValid());

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
