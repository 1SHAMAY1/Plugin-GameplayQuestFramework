// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayTagContainer.h"
#include "IGameplayQuestGiverInterface.generated.h"

class AActor;

UINTERFACE(MinimalAPI, BlueprintType)
class UGameplayQuestGiverInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface implemented by quest giver actors, NPCs, and mission boards.
 */
class GAMEPLAYQUESTFRAMEWORK_API IGameplayQuestGiverInterface
{
	GENERATED_BODY()

public:
	/** Returns all quest tags offered by this giver to the specified interactor. */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework|Giver")
	void GetOfferedQuests(const AActor* Interactor, TArray<FGameplayTag>& OutQuests) const;

	/** Returns current visual marker/dialogue state tag (e.g. Quest.Giver.State.Available, InProgress, ReadyToTurnIn). */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Quest Framework|Giver")
	FGameplayTag GetQuestGiverStateTag(const AActor* Interactor) const;
};
