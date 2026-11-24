// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestDataSubsystem.h"
#include "GameplayQuestSettings.h"
#include "GameplayQuestModule.h"
#include "Engine/World.h"
#include "Misc/App.h"

UGameplayQuestDataSubsystem::UGameplayQuestDataSubsystem()
{
}

void UGameplayQuestDataSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UE_LOG(LogGameplayQuest, Log, TEXT("GameplayQuestDataSubsystem initialized across GameInstance."));

	const UGameplayQuestSettings* Settings = UGameplayQuestSettings::Get();
	if (Settings && Settings->bAutoRegisterQuestDefinitions)
	{
		ScanAndRegisterAllQuests();
	}
}

void UGameplayQuestDataSubsystem::Deinitialize()
{
	QuestRegistry.Empty();
	PlayerTravelCache.Empty();
	Super::Deinitialize();
}

void UGameplayQuestDataSubsystem::RegisterQuestDefinition(const FGameplayTag& QuestTag, UGameplayQuestDefinition* QuestAsset)
{
	if (!QuestTag.IsValid() || !QuestAsset)
	{
		return;
	}

	QuestRegistry.FindOrAdd(QuestTag) = QuestAsset;
	UE_LOG(LogGameplayQuest, Verbose, TEXT("Registered Quest Definition: %s for Tag: %s"),
		*QuestAsset->GetName(), *QuestTag.ToString());
}

UGameplayQuestDefinition* UGameplayQuestDataSubsystem::GetQuestDefinition(const FGameplayTag& QuestTag) const
{
	if (!QuestTag.IsValid())
	{
		return nullptr;
	}

	if (const TObjectPtr<UGameplayQuestDefinition>* FoundAsset = QuestRegistry.Find(QuestTag))
	{
		return FoundAsset->Get();
	}

	return nullptr;
}

void UGameplayQuestDataSubsystem::ScanAndRegisterAllQuests()
{
	// Asset registry scanning for UGameplayQuestDefinition assets.
	// Populated as quest definitions are authored in the content browser.
}

void UGameplayQuestDataSubsystem::CachePlayerQuestsForTravel(const FGuid& PlayerGuid, const TArray<uint8>& SerializedBuffer)
{
	if (!PlayerGuid.IsValid() || SerializedBuffer.Num() == 0)
	{
		return;
	}

	FGameplayQuestTravelCache CacheEntry;
	CacheEntry.PlayerGuid = PlayerGuid;
	CacheEntry.SerializedQuestBuffer = SerializedBuffer;
	CacheEntry.CachedTimestamp = FApp::GetCurrentTime();

	PlayerTravelCache.FindOrAdd(PlayerGuid) = MoveTemp(CacheEntry);

	UE_LOG(LogGameplayQuest, Log, TEXT("Cached %d bytes of quest data for Player: %s across level travel."),
		SerializedBuffer.Num(), *PlayerGuid.ToString());
}

bool UGameplayQuestDataSubsystem::RestorePlayerQuestsFromTravel(const FGuid& PlayerGuid, TArray<uint8>& OutSerializedBuffer)
{
	OutSerializedBuffer.Reset();

	if (!PlayerGuid.IsValid())
	{
		return false;
	}

	if (FGameplayQuestTravelCache* FoundCache = PlayerTravelCache.Find(PlayerGuid))
	{
		OutSerializedBuffer = MoveTemp(FoundCache->SerializedQuestBuffer);
		PlayerTravelCache.Remove(PlayerGuid);

		UE_LOG(LogGameplayQuest, Log, TEXT("Restored %d bytes of quest data for Player: %s upon arriving in world."),
			OutSerializedBuffer.Num(), *PlayerGuid.ToString());
		return true;
	}

	return false;
}

bool UGameplayQuestDataSubsystem::HasTravelCacheForPlayer(const FGuid& PlayerGuid) const
{
	return PlayerGuid.IsValid() && PlayerTravelCache.Contains(PlayerGuid);
}

void UGameplayQuestDataSubsystem::InvalidateTravelCache(const FGuid& PlayerGuid)
{
	if (PlayerGuid.IsValid())
	{
		PlayerTravelCache.Remove(PlayerGuid);
	}
}

void UGameplayQuestDataSubsystem::InvalidateAllTravelCaches()
{
	PlayerTravelCache.Empty();
}

int32 UGameplayQuestDataSubsystem::GetRegisteredQuestCount() const
{
	return QuestRegistry.Num();
}
