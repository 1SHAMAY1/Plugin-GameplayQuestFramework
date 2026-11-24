// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "GameplayQuestTypes.h"
#include "GameplayQuestTags.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestPayloadTests,
	"GameplayQuest.Unit.Events.PayloadSerializationAndContext",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestPayloadTests::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	// 1. Basic construction
	FGameplayQuestEventPayload Payload(TAG_Quest_Event_Kill.GetTag(), nullptr, 3);
	TestTrue(TEXT("EventTag must match assigned tag"), Payload.EventTag == TAG_Quest_Event_Kill.GetTag());
	TestEqual(TEXT("Quantity must be initialized to 3"), Payload.Quantity, 3);
	TestNull(TEXT("Instigator should be null in this test"), Payload.Instigator.Get());

	// 2. Zone stamping
	Payload.ZoneTag = TAG_Zone_Default.GetTag();
	TestTrue(TEXT("ZoneTag must match assigned default zone"), Payload.ZoneTag == TAG_Zone_Default.GetTag());

	// 3. Context tags matching
	Payload.ContextTags.AddTag(TAG_Quest_Event_Kill.GetTag());
	TestTrue(TEXT("HasContextTag must return true for added tag"), Payload.HasContextTag(TAG_Quest_Event_Kill.GetTag()));
	TestFalse(TEXT("HasContextTag must return false for absent tag"), Payload.HasContextTag(TAG_Quest_Event_Collect.GetTag()));

	// 4. Tag query evaluation
	FGameplayTagQuery MatchQuery = FGameplayTagQuery::MakeQuery_MatchTag(TAG_Quest_Event_Kill.GetTag());
	FGameplayTagQuery FailQuery = FGameplayTagQuery::MakeQuery_MatchTag(TAG_Quest_Event_Collect.GetTag());
	TestTrue(TEXT("MatchesTagQuery must return true for matching query"), Payload.MatchesTagQuery(MatchQuery));
	TestFalse(TEXT("MatchesTagQuery must return false for non-matching query"), Payload.MatchesTagQuery(FailQuery));

	// 5. Numeric parameter map storage and fallback
	const FGameplayTag ParamDamage = TAG_Quest_Event_Custom.GetTag();
	TestEqual(TEXT("GetNumericParameter default value test"), Payload.GetNumericParameter(ParamDamage, 42.0f), 42.0f);

	Payload.SetNumericParameter(ParamDamage, 150.5f);
	TestEqual(TEXT("GetNumericParameter retrieved stored value test"), Payload.GetNumericParameter(ParamDamage, 0.0f), 150.5f);

	// 6. Travel cache validity test
	FGameplayQuestTravelCache TravelCache;
	TestFalse(TEXT("Default TravelCache must be invalid"), TravelCache.IsValid());

	TravelCache.PlayerGuid = FGuid::NewGuid();
	TravelCache.SerializedQuestBuffer.Add(0xFF);
	TestTrue(TEXT("TravelCache with valid GUID and non-empty buffer must be valid"), TravelCache.IsValid());

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
