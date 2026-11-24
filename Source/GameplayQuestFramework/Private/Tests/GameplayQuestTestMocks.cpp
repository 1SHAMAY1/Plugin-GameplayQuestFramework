// Copyright Epic Games, Inc. All Rights Reserved.

#include "Tests/GameplayQuestTestMocks.h"
#include "GameplayQuestTags.h"

// ----------------------------------------------------------------------------
// AMockQuestOwnerActor
// ----------------------------------------------------------------------------

AMockQuestOwnerActor::AMockQuestOwnerActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	MockManagerComponent = CreateDefaultSubobject<UGameplayQuestManagerComponent>(TEXT("MockQuestManager"));
}

UGameplayQuestManagerComponent* AMockQuestOwnerActor::GetQuestManagerComponent_Implementation() const
{
	return MockManagerComponent;
}

// ----------------------------------------------------------------------------
// AMockPartyProviderActor
// ----------------------------------------------------------------------------

AMockPartyProviderActor::AMockPartyProviderActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	TestPartyId = FGuid::NewGuid();
	MemberZoneTag = GameplayQuestTags::TAG_Zone_Default.GetTag();
}

FGuid AMockPartyProviderActor::GetPartyId_Implementation(const AActor* PartyMember) const
{
	return TestPartyId;
}

void AMockPartyProviderActor::GetPartyMembers_Implementation(const AActor* Requester, TArray<AActor*>& OutMembers) const
{
	OutMembers.Empty();
	for (AActor* Member : PartyMembers)
	{
		if (Member)
		{
			OutMembers.Add(Member);
		}
	}
}

bool AMockPartyProviderActor::AreInSameParty_Implementation(const AActor* ActorA, const AActor* ActorB) const
{
	return ActorA && ActorB && PartyMembers.Contains(ActorA) && PartyMembers.Contains(ActorB);
}

FGameplayTag AMockPartyProviderActor::GetMemberZoneTag_Implementation(const AActor* PartyMember) const
{
	return MemberZoneTag;
}

// ----------------------------------------------------------------------------
// AMockInteractableActor
// ----------------------------------------------------------------------------

AMockInteractableActor::AMockInteractableActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	InteractTag = GameplayQuestTags::TAG_Quest_Event_Interact.GetTag();
	bAllowInteract = true;
	bWasInteractedWith = false;
}

FGameplayTag AMockInteractableActor::GetInteractableTag_Implementation() const
{
	return InteractTag;
}

bool AMockInteractableActor::CanInteract_Implementation(const AActor* Interactor) const
{
	return bAllowInteract;
}

void AMockInteractableActor::OnQuestInteraction_Implementation(AActor* Interactor)
{
	bWasInteractedWith = true;
}

// ----------------------------------------------------------------------------
// AMockQuestGiverActor
// ----------------------------------------------------------------------------

AMockQuestGiverActor::AMockQuestGiverActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GiverState = GameplayQuestTags::TAG_Quest_Giver_Available.GetTag();
}

void AMockQuestGiverActor::GetOfferedQuests_Implementation(const AActor* Interactor, TArray<FGameplayTag>& OutQuests) const
{
	OutQuests = OfferedQuests;
}

FGameplayTag AMockQuestGiverActor::GetQuestGiverStateTag_Implementation(const AActor* Interactor) const
{
	return GiverState;
}
