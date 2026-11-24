// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayObjectiveDefinition.h"
#include "InteractObjectiveDefinition.generated.h"

/**
 * Objective requiring interaction with a specific world object, NPC, or terminal.
 * Interfaces seamlessly with IGameplayQuestInteractable.
 */
UCLASS(BlueprintType, meta = (DisplayName = "Interact Target Objective"))
class GAMEPLAYQUESTFRAMEWORK_API UInteractObjectiveDefinition : public UGameplayObjectiveDefinition
{
	GENERATED_BODY()

public:
	UInteractObjectiveDefinition(const FObjectInitializer& ObjectInitializer);

	/** Target interactable tag (e.g. Quest.Target.Interact.ControlPanel). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Interact Objective", meta = (Categories = "Quest.Target.Interact"))
	FGameplayTag InteractableTag;

	virtual FGameplayTag GetEventChannelTag_Implementation() const override;
	virtual bool MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const override;
};
