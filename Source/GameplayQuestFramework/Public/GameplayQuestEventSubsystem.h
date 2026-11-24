// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestTypes.h"
#include "GameplayQuestEventSubsystem.generated.h"

class UGameplayQuestManagerComponent;

/**
 * World subsystem implementing a zero-tick inverted tag-indexed quest event bus.
 *
 * Instead of iterating through all active players and all quests per event (O(N*M)),
 * quest managers subscribe only to the specific event tags their active objectives care about.
 * When an event fires, it is routed in O(K) where K is the number of interested listeners.
 */
UCLASS()
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestEventSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UGameplayQuestEventSubsystem();

	// USubsystem / UWorldSubsystem interface
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

	/** Set or override the zone tag stamped onto events generated within this world. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|World")
	void SetWorldZoneTag(const FGameplayTag& InZoneTag);

	/** Returns current world zone tag. */
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Quest Framework|World")
	FGameplayTag GetWorldZoneTag() const;

	/** Subscribe a Quest Manager to receive notifications for a specific event tag. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|EventBus")
	void RegisterEventListener(const FGameplayTag& EventTag, UGameplayQuestManagerComponent* Listener);

	/** Unsubscribe a Quest Manager from a specific event tag. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|EventBus")
	void UnregisterEventListener(const FGameplayTag& EventTag, UGameplayQuestManagerComponent* Listener);

	/** Remove a Quest Manager from all event channels (called on quest manager destroy/deactivation). */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|EventBus")
	void UnregisterAllForListener(UGameplayQuestManagerComponent* Listener);

	/** Dispatches an event payload to all interested listeners matching the payload's EventTag. */
	UFUNCTION(BlueprintCallable, Category = "Quest Framework|EventBus")
	void BroadcastQuestEvent(UPARAM(ref) FGameplayQuestEventPayload& Payload);

	/** Returns the number of registered listeners for an event tag. */
	int32 GetListenerCountForTag(const FGameplayTag& EventTag) const;

	/** Returns the total number of distinct event channels currently indexed. */
	int32 GetChannelCount() const;

private:
	/** Active zone tag identifying this world/map level. */
	UPROPERTY(Transient)
	FGameplayTag CurrentWorldZoneTag;

	/**
	 * Inverted interest table: EventTag -> Set of listening Quest Manager components.
	 * Cleaned lazily if weak pointers become stale.
	 */
	TMap<FGameplayTag, TSet<TWeakObjectPtr<UGameplayQuestManagerComponent>>> InvertedInterestTable;
};
