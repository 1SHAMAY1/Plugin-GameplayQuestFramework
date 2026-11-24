// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/IGameplayQuestManagerInterface.h"
#include "Interfaces/IGameplayQuestPartyProvider.h"
#include "Interfaces/IGameplayQuestInteractable.h"
#include "Interfaces/IGameplayQuestGiverInterface.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestTestMocks.generated.h"

/**
 * Mock Actor implementing IGameplayQuestManagerInterface for test verification.
 */
UCLASS()
class GAMEPLAYQUESTFRAMEWORK_API AMockQuestOwnerActor : public AActor, public IGameplayQuestManagerInterface
{
	GENERATED_BODY()

public:
	AMockQuestOwnerActor(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Quest Framework")
	TObjectPtr<UGameplayQuestManagerComponent> MockManagerComponent;

	virtual UGameplayQuestManagerComponent* GetQuestManagerComponent_Implementation() const override;
};

/**
 * Mock Actor implementing IGameplayQuestPartyProvider for party membership verification.
 */
UCLASS()
class GAMEPLAYQUESTFRAMEWORK_API AMockPartyProviderActor : public AActor, public IGameplayQuestPartyProvider
{
	GENERATED_BODY()

public:
	AMockPartyProviderActor(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	FGuid TestPartyId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	TArray<TObjectPtr<AActor>> PartyMembers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	FGameplayTag MemberZoneTag;

	virtual FGuid GetPartyId_Implementation(const AActor* PartyMember) const override;
	virtual void GetPartyMembers_Implementation(const AActor* Requester, TArray<AActor*>& OutMembers) const override;
	virtual bool AreInSameParty_Implementation(const AActor* ActorA, const AActor* ActorB) const override;
	virtual FGameplayTag GetMemberZoneTag_Implementation(const AActor* PartyMember) const override;
};

/**
 * Mock Actor implementing IGameplayQuestInteractable for interaction verification.
 */
UCLASS()
class GAMEPLAYQUESTFRAMEWORK_API AMockInteractableActor : public AActor, public IGameplayQuestInteractable
{
	GENERATED_BODY()

public:
	AMockInteractableActor(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	FGameplayTag InteractTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	bool bAllowInteract = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Quest Framework")
	bool bWasInteractedWith = false;

	virtual FGameplayTag GetInteractableTag_Implementation() const override;
	virtual bool CanInteract_Implementation(const AActor* Interactor) const override;
	virtual void OnQuestInteraction_Implementation(AActor* Interactor) override;
};

/**
 * Mock Actor implementing IGameplayQuestGiverInterface for quest giver queries.
 */
UCLASS()
class GAMEPLAYQUESTFRAMEWORK_API AMockQuestGiverActor : public AActor, public IGameplayQuestGiverInterface
{
	GENERATED_BODY()

public:
	AMockQuestGiverActor(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	TArray<FGameplayTag> OfferedQuests;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework")
	FGameplayTag GiverState;

	virtual void GetOfferedQuests_Implementation(const AActor* Interactor, TArray<FGameplayTag>& OutQuests) const override;
	virtual FGameplayTag GetQuestGiverStateTag_Implementation(const AActor* Interactor) const override;
};
