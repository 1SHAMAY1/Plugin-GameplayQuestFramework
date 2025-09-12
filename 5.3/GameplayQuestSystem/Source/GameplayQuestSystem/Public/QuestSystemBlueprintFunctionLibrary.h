#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "QuestSystemBlueprintFunctionLibrary.generated.h"

struct FQuestPayload;
enum class EQuestState : uint8;
class UGameplayQuestSubsystem;

/**
 * UQuestSystemBlueprintFunctionLibrary
 *
 * A Blueprint Function Library providing utility functions for the Gameplay Quest System.
 * Exposes core quest functionality to Blueprints and C++ in a safe and reusable way.
 *
 * Key Features:
 * - Allows sending quest events from both Blueprints and C++.
 * - Provides a central, static interface for interacting with quest-related functionality
 *   without needing direct references to the Quest Subsystem.
 */
UCLASS()
class GAMEPLAYQUESTSYSTEM_API UQuestSystemBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Sends a quest event safely, usable from both C++ and Blueprints.
	 * @param State The quest state to send (e.g., Completed, Failed, Abandoned).
	 * @param Payload The payload containing quest-specific data.
	 */
	UFUNCTION(BlueprintCallable, Category="Quest System")
	static void SendQuestEvent(EQuestState State, const FQuestPayload& Payload);
};
