// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "GameplayQuestTags.h"
#include "Tests/GameplayQuestTestMocks.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestPartyProviderMembershipTest,
	"GameplayQuest.Integration.Party.CrossZoneMembershipValidation",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestPartyProviderMembershipTest::RunTest(const FString& Parameters)
{
	using namespace GameplayQuestTags;

	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	TestNotNull(TEXT("World must be created"), World);

	if (World)
	{
		AMockPartyProviderActor* PartyProvider = World->SpawnActor<AMockPartyProviderActor>();
		AActor* PlayerA = World->SpawnActor<AActor>();
		AActor* PlayerB = World->SpawnActor<AActor>();
		AActor* SoloPlayer = World->SpawnActor<AActor>();

		TestNotNull(TEXT("PartyProvider must spawn"), PartyProvider);
		TestNotNull(TEXT("PlayerA must spawn"), PlayerA);
		TestNotNull(TEXT("PlayerB must spawn"), PlayerB);
		TestNotNull(TEXT("SoloPlayer must spawn"), SoloPlayer);

		// 1. Setup party with PlayerA and PlayerB
		PartyProvider->PartyMembers.Add(PlayerA);
		PartyProvider->PartyMembers.Add(PlayerB);
		PartyProvider->MemberZoneTag = TAG_Zone_Default.GetTag();
		PartyProvider->TestPartyId = FGuid::NewGuid();

		IGameplayQuestPartyProvider* Provider = Cast<IGameplayQuestPartyProvider>(PartyProvider);
		TestNotNull(TEXT("PartyProvider must implement IGameplayQuestPartyProvider"), Provider);

		if (Provider)
		{
			// 2. Party ID validation
			FGuid PartyId = IGameplayQuestPartyProvider::Execute_GetPartyId(PartyProvider, PlayerA);
			if (!PartyId.IsValid())
			{
				PartyId = Provider->GetPartyId_Implementation(PlayerA);
			}
			TestTrue(TEXT("PartyId must be a valid GUID"), PartyId.IsValid());

			// 3. Party membership evaluation
			bool bSameParty = IGameplayQuestPartyProvider::Execute_AreInSameParty(PartyProvider, PlayerA, PlayerB);
			if (!bSameParty)
			{
				bSameParty = Provider->AreInSameParty_Implementation(PlayerA, PlayerB);
			}
			TestTrue(TEXT("PlayerA and PlayerB should be in the same party"), bSameParty);

			bool bSoloSameParty = IGameplayQuestPartyProvider::Execute_AreInSameParty(PartyProvider, PlayerA, SoloPlayer);
			if (bSoloSameParty)
			{
				bSoloSameParty = Provider->AreInSameParty_Implementation(PlayerA, SoloPlayer);
			}
			TestFalse(TEXT("PlayerA and SoloPlayer should NOT be in the same party"), bSoloSameParty);

			// 4. Party members list retrieval
			TArray<AActor*> RetrievedMembers;
			IGameplayQuestPartyProvider::Execute_GetPartyMembers(PartyProvider, PlayerA, RetrievedMembers);
			if (RetrievedMembers.Num() == 0)
			{
				Provider->GetPartyMembers_Implementation(PlayerA, RetrievedMembers);
			}
			TestEqual(TEXT("RetrievedMembers count must be 2"), RetrievedMembers.Num(), 2);
			TestTrue(TEXT("RetrievedMembers must contain PlayerA"), RetrievedMembers.Contains(PlayerA));
			TestTrue(TEXT("RetrievedMembers must contain PlayerB"), RetrievedMembers.Contains(PlayerB));
			TestFalse(TEXT("RetrievedMembers must NOT contain SoloPlayer"), RetrievedMembers.Contains(SoloPlayer));

			// 5. Zone query
			FGameplayTag ZoneTag = IGameplayQuestPartyProvider::Execute_GetMemberZoneTag(PartyProvider, PlayerA);
			if (!ZoneTag.IsValid())
			{
				ZoneTag = Provider->GetMemberZoneTag_Implementation(PlayerA);
			}
			TestTrue(TEXT("MemberZoneTag must match default zone tag"), ZoneTag == TAG_Zone_Default.GetTag());
		}

		PartyProvider->Destroy();
		PlayerA->Destroy();
		PlayerB->Destroy();
		SoloPlayer->Destroy();
		World->DestroyWorld(false);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
