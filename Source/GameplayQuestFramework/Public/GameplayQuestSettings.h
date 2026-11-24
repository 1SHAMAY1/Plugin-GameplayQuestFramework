// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestSettings.generated.h"

/**
 * Project-wide settings for the Gameplay Quest Framework.
 * Configured via Project Settings -> Game -> Gameplay Quest Framework.
 * Zero hardcoding: all system constants and defaults are tuned here.
 */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Gameplay Quest Framework"))
class GAMEPLAYQUESTFRAMEWORK_API UGameplayQuestSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UGameplayQuestSettings(const FObjectInitializer& ObjectInitializer);

	/** Current schema version for quest save data migrations. */
	UPROPERTY(EditAnywhere, Config, Category = "Persistence", meta = (ClampMin = "1"))
	int32 SaveSchemaVersion = 1;

	/** Default proximity radius in Unreal Units (cm) for party co-op objective progress sharing (5000 cm = 50m). */
	UPROPERTY(EditAnywhere, Config, Category = "Multiplayer & Party", meta = (ClampMin = "100.0", Units = "cm"))
	float DefaultPartyShareRadius = 5000.0f;

	/** Maximum number of concurrently active quests allowed per player. */
	UPROPERTY(EditAnywhere, Config, Category = "Quests", meta = (ClampMin = "1", ClampMax = "1000"))
	int32 MaxActiveQuestsPerPlayer = 50;

	/** When enabled, outputs detailed Net Delta replication logs for FFastArraySerializer profiling. */
	UPROPERTY(EditAnywhere, Config, Category = "Networking & Profiling")
	bool bEnableNetworkDeltaProfiling = false;

	/** Default world/zone scope tag assigned to the world if none is explicitly specified on the level. */
	UPROPERTY(EditAnywhere, Config, Category = "World & Zones", meta = (Categories = "Zone"))
	FGameplayTag DefaultZoneTag;

	/** Default category tag assigned to new quests if omitted. */
	UPROPERTY(EditAnywhere, Config, Category = "Quests", meta = (Categories = "Quest.Category"))
	FGameplayTag DefaultQuestCategory;

	/** Whether to automatically scan and register quest definition assets at startup. */
	UPROPERTY(EditAnywhere, Config, Category = "Quests")
	bool bAutoRegisterQuestDefinitions = true;

	/** Get singleton instance of GameplayQuestSettings. */
	static const UGameplayQuestSettings* Get();

	virtual FName GetCategoryName() const override;
};
