// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "IGameplayQuestInteractable.generated.h"

class AActor;

UINTERFACE(MinimalAPI, BlueprintType)
class UGameplayQuestInteractable : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface implemented by interactive world actors (NPCs, chests, doors, terminals).
 * Allows the quest framework to query interaction targets and trigger progress cleanly.
 */
class GAMEPLAYQUESTFRAMEWORK_API IGameplayQuestInteractable
{
	GENERATED_BODY()

public:
	/** Returns the interaction tag identifying this actor (e.g. Quest.Target.Interact.OldChest). */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework|Interaction")
	FGameplayTag GetInteractableTag() const;

	/** Returns true if the Interactor is allowed to interact with this target. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework|Interaction")
	bool CanInteract(const AActor* Interactor) const;

	/** Called when interaction with this target occurs. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework|Interaction")
	void OnQuestInteraction(AActor* Interactor);
};
