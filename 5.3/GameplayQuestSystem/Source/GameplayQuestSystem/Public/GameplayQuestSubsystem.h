#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestTypes.h"
#include "GameplayQuestSubsystem.generated.h"

class UGameplayQuestBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestEventBP, EQuestState, State, const FQuestPayload&, Payload);

/**
 * UGameplayQuestSubsystem
 *
 * Subsystem responsible for managing all active quests within the game instance.
 * Handles quest registration, tracking, and lifecycle events, providing a centralized 
 * interface for gameplay systems to interact with quests.
 *
 * Inherits from UGameInstanceSubsystem, ensuring a single instance per game session 
 * and automatic initialization with the game instance.
 */
UCLASS()
class GAMEPLAYQUESTSYSTEM_API UGameplayQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category="Quest|Events")
	FQuestEventBP OnQuestEventBP;

	/** Internal call: registers a quest that’s already loaded */
	void RegisterQuest_Internal(FGameplayTag QuestTag, UGameplayQuestBase* Quest, AActor* Source);

	/** Complete a quest by GameplayTag */
	UFUNCTION(BlueprintCallable, Category="Quest")
	void CompleteQuest(FGameplayTag QuestTag);

	/** Reset a quest by GameplayTag */
	UFUNCTION(BlueprintCallable, Category="Quest")
	void ResetQuest(FGameplayTag QuestTag);

	/** Send quest event */
	void HandleQuestEvent(EQuestState State, const FQuestPayload& Payload);

	/** Get all active quests */
	UFUNCTION(BlueprintCallable, Category="Quest")
	const TMap<FGameplayTag, UGameplayQuestBase*>& GetActiveQuests() const { return ActiveQuests; }

	/** Get all completed quests */
	UFUNCTION(BlueprintCallable, Category="Quest")
	const TArray<UGameplayQuestBase*>& GetCompletedQuests() const { return CompletedQuests; }

	/** Check if a quest with a specific tag is currently active */
	UFUNCTION(BlueprintPure, Category="Quest")
	bool IsQuestActive(FGameplayTag QuestTag) const;

private:
	UPROPERTY()
	TMap<FGameplayTag, UGameplayQuestBase*> ActiveQuests;

	UPROPERTY()
	TArray<UGameplayQuestBase*> CompletedQuests;
};

