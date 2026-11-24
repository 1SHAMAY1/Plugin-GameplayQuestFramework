// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestTypes.h"
#include "GameplayQuestFunctionLibrary.generated.h"

class UGameplayQuestManagerComponent;
class AActor;

/**
 * Static function library exposing unified C++ and Blueprint APIs for the Gameplay Quest Framework.
 * Completely decouples event broadcasters from level blueprints, characters, and specific game modes.
 */
UCLASS()
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Resolves the UGameplayQuestManagerComponent for a target actor.
	 * Queries IGameplayQuestManagerInterface first ($O(1)$), then checks Controller/PlayerState if TargetActor is a Pawn,
	 * and finally falls back to FindComponentByClass.
	 */
	UFUNCTION(BlueprintPure, Category = "Quest Framework|Query")
	static UGameplayQuestManagerComponent* GetQuestManager(const AActor* TargetActor);

	/** Broadcast a Kill event across the quest system. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Events", meta = (WorldContext = "WorldContextObject"))
	static void BroadcastKillEvent(
		const UObject* WorldContextObject,
		AActor* Killer,
		AActor* Victim,
		FGameplayTag VictimTag
	);

	/** Broadcast an Item Collect event across the quest system. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Events", meta = (WorldContext = "WorldContextObject"))
	static void BroadcastCollectEvent(
		const UObject* WorldContextObject,
		AActor* Collector,
		FGameplayTag ItemTag,
		int32 Quantity = 1
	);

	/** Broadcast an Interaction event across the quest system. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Events", meta = (WorldContext = "WorldContextObject"))
	static void BroadcastInteractEvent(
		const UObject* WorldContextObject,
		AActor* Interactor,
		AActor* TargetActor,
		FGameplayTag InteractTag
	);

	/** Broadcast an Area Reached event across the quest system. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Events", meta = (WorldContext = "WorldContextObject"))
	static void BroadcastAreaReachedEvent(
		const UObject* WorldContextObject,
		AActor* InstigatorPawn,
		FGameplayTag AreaTag
	);

	/** Generic event broadcaster taking an extensible FGameplayQuestEventPayload. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Events", meta = (WorldContext = "WorldContextObject"))
	static void BroadcastQuestEvent(
		const UObject* WorldContextObject,
		const FGameplayQuestEventPayload& Payload
	);

	/** Query the lifecycle status tag of a quest for an actor. */
	UFUNCTION(BlueprintPure, Category = "Quest Framework|Query")
	static FGameplayTag GetQuestStatus(const AActor* TargetActor, FGameplayTag QuestTag);

	/** Returns true if the actor's quest status matches or descends from the specified status tag. */
	UFUNCTION(BlueprintPure, Category = "Quest Framework|Query")
	static bool HasQuestStatus(const AActor* TargetActor, FGameplayTag QuestTag, FGameplayTag StatusTag);
};
