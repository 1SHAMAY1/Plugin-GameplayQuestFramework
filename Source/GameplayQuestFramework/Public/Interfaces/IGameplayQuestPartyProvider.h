// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "IGameplayQuestPartyProvider.generated.h"

class AActor;

UINTERFACE(MinimalAPI, BlueprintType)
class UGameplayQuestPartyProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * Decoupled party and co-op membership query interface.
 * Implemented by GameState, PartySubsystem, or custom Party Managers.
 */
class GAMEPLAYQUESTFRAMEWORK_API IGameplayQuestPartyProvider
{
	GENERATED_BODY()

public:
	/** Returns the unique identifier of the party that this actor belongs to, or invalid GUID if solo. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework|Party")
	FGuid GetPartyId(const AActor* PartyMember) const;

	/** Fills OutMembers with all active actors currently in the same party as Requester. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework|Party")
	void GetPartyMembers(const AActor* Requester, TArray<AActor*>& OutMembers) const;

	/** Returns true if ActorA and ActorB belong to the same active party. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework|Party")
	bool AreInSameParty(const AActor* ActorA, const AActor* ActorB) const;

	/** Returns the current zone scope tag of a party member for cross-world co-op isolation. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework|Party")
	FGameplayTag GetMemberZoneTag(const AActor* PartyMember) const;
};
