// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IGameplayQuestManagerInterface.generated.h"

class UGameplayQuestManagerComponent;

UINTERFACE(MinimalAPI, BlueprintType)
class UGameplayQuestManagerInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface implemented by Actors (PlayerController, PlayerState, Character, GameState)
 * that possess or provide access to a UGameplayQuestManagerComponent.
 * Eliminates slow FindComponentByClass calls across the codebase.
 */
class GAMEPLAYQUESTFRAMEWORK_API IGameplayQuestManagerInterface
{
	GENERATED_BODY()

public:
	/** Get the Quest Manager component associated with this actor. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework")
	UGameplayQuestManagerComponent* GetQuestManagerComponent() const;
};
