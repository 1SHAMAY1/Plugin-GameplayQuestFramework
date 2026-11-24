// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestSaveData.generated.h"

/**
 * Serialized representation of an objective record.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayObjectiveSaveRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	FGameplayTag ObjectiveTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	FGameplayTag StatusTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	int32 CurrentProgress = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	int32 RequiredCount = 1;
};

/**
 * Serialized representation of an active quest record.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayQuestSaveRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	FGameplayTag QuestTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	FGameplayTag StatusTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	int32 CurrentStageIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	TArray<FGameplayObjectiveSaveRecord> Objectives;
};

/**
 * Lightweight, high-density save container supporting dual persistence:
 * 1. Fast local binary serialization (USaveGame / SaveGameToSlot).
 * 2. Cloud / MMORPG database JSON string export/import.
 */
USTRUCT(BlueprintType)
struct GAMEPLAYQUESTFRAMEWORK_API FGameplayQuestSaveData
{
	GENERATED_BODY()

	FGameplayQuestSaveData();

	/** Schema version for migration safety. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	int32 SchemaVersion = 1;

	/** Player or Character GUID associated with this save state. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	FGuid CharacterGuid;

	/** Active quests currently in progress. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	TArray<FGameplayQuestSaveRecord> ActiveQuests;

	/** Completed quest tags. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	FGameplayTagContainer CompletedQuests;

	/** Failed quest tags. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Save")
	FGameplayTagContainer FailedQuests;

	// -------------------------------------------------------------------------
	// Binary Serialization (Local disk / USaveGame)
	// -------------------------------------------------------------------------
	void ExportToBinary(TArray<uint8>& OutBytes) const;
	bool ImportFromBinary(const TArray<uint8>& InBytes);

	// -------------------------------------------------------------------------
	// Cloud / MMORPG JSON Serialization (Postgres / Redis / MongoDB)
	// -------------------------------------------------------------------------
	bool ExportToJson(FString& OutJsonString) const;
	bool ImportFromJson(const FString& InJsonString);
};
