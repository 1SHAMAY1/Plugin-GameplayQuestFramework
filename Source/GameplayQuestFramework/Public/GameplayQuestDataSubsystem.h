// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestTypes.h"
#include "GameplayQuestDefinition.h"
#include "GameplayQuestDataSubsystem.generated.h"

class UGameplayQuestDefinition;

/**
 * GameInstance subsystem providing global quest asset registry and cross-world travel persistence.
 *
 * Persists through level transitions (OpenLevel, ServerTravel, seamless travel),
 * holding active quest states across non-instanced world boundaries.
 */
UCLASS()
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestDataSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UGameplayQuestDataSubsystem();

	// USubsystem / UGameInstanceSubsystem interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Register a Quest Definition asset under its primary identifier tag. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Registry")
	void RegisterQuestDefinition(const FGameplayTag& QuestTag, UGameplayQuestDefinition* QuestAsset);

	/** Resolve a Quest Definition asset by its primary tag in O(1). */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quest Framework|Registry")
	UGameplayQuestDefinition* GetQuestDefinition(const FGameplayTag& QuestTag) const;

	/** Scan and register all quest definitions from asset registry. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Registry")
	void ScanAndRegisterAllQuests();

	// -------------------------------------------------------------------------
	// Cross-World Level Travel Cache Engine
	// -------------------------------------------------------------------------

	/**
	 * Stashes active quest states into the GameInstance travel cache before a level change.
	 * Keyed by PlayerGuid (or controller unique net ID) to support coop and dedicated servers.
	 */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Travel")
	void CachePlayerQuestsForTravel(const FGuid& PlayerGuid, const TArray<uint8>& SerializedBuffer);

	/**
	 * Restores and removes active quest states from the travel cache upon landing in a new world.
	 * Returns true if cached data was found and restored.
	 */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Travel")
	bool RestorePlayerQuestsFromTravel(const FGuid& PlayerGuid, TArray<uint8>& OutSerializedBuffer);

	/** Checks whether there is active cached travel data for a player. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quest Framework|Travel")
	bool HasTravelCacheForPlayer(const FGuid& PlayerGuid) const;

	/** Clears travel cache for a single player. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Travel")
	void InvalidateTravelCache(const FGuid& PlayerGuid);

	/** Clears all travel caches across all players. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|Travel")
	void InvalidateAllTravelCaches();

	/** Returns total count of registered quest assets. */
	int32 GetRegisteredQuestCount() const;

private:
	/** O(1) Tag-to-Asset registry map. */
	UPROPERTY(Transient)
	TMap<FGameplayTag, TObjectPtr<UGameplayQuestDefinition>> QuestRegistry;

	/** Cross-world travel storage keyed by PlayerGuid. */
	UPROPERTY(Transient)
	TMap<FGuid, FGameplayQuestTravelCache> PlayerTravelCache;
};
