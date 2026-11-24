// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestEventSubsystem.h"
#include "Engine/World.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestSettings.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestModule.h"

UGameplayQuestEventSubsystem::UGameplayQuestEventSubsystem()
{
}

void UGameplayQuestEventSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	const UGameplayQuestSettings* Settings = UGameplayQuestSettings::Get();
	if (Settings && Settings->DefaultZoneTag.IsValid())
	{
		CurrentWorldZoneTag = Settings->DefaultZoneTag;
	}
	else
	{
		CurrentWorldZoneTag = GameplayQuestTags::TAG_Zone_Default.GetTag();
	}

	UE_LOG(LogGameplayQuest, Verbose, TEXT("GameplayQuestEventSubsystem initialized for World: %s with Zone: %s"),
		*GetWorld()->GetName(), *CurrentWorldZoneTag.ToString());
}

void UGameplayQuestEventSubsystem::Deinitialize()
{
	InvertedInterestTable.Empty();
	Super::Deinitialize();
}

bool UGameplayQuestEventSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game ||
	       WorldType == EWorldType::PIE ||
	       WorldType == EWorldType::Editor;
}

void UGameplayQuestEventSubsystem::SetWorldZoneTag(const FGameplayTag& InZoneTag)
{
	if (InZoneTag.IsValid())
	{
		CurrentWorldZoneTag = InZoneTag;
	}
}

FGameplayTag UGameplayQuestEventSubsystem::GetWorldZoneTag() const
{
	return CurrentWorldZoneTag;
}

void UGameplayQuestEventSubsystem::RegisterEventListener(const FGameplayTag& EventTag, UGameplayQuestManagerComponent* Listener)
{
	if (!EventTag.IsValid() || !Listener)
	{
		return;
	}

	TSet<TWeakObjectPtr<UGameplayQuestManagerComponent>>& Listeners = InvertedInterestTable.FindOrAdd(EventTag);
	Listeners.Add(Listener);
}

void UGameplayQuestEventSubsystem::UnregisterEventListener(const FGameplayTag& EventTag, UGameplayQuestManagerComponent* Listener)
{
	if (!EventTag.IsValid() || !Listener)
	{
		return;
	}

	if (TSet<TWeakObjectPtr<UGameplayQuestManagerComponent>>* Listeners = InvertedInterestTable.Find(EventTag))
	{
		Listeners->Remove(Listener);
		if (Listeners->Num() == 0)
		{
			InvertedInterestTable.Remove(EventTag);
		}
	}
}

void UGameplayQuestEventSubsystem::UnregisterAllForListener(UGameplayQuestManagerComponent* Listener)
{
	if (!Listener)
	{
		return;
	}

	for (auto It = InvertedInterestTable.CreateIterator(); It; ++It)
	{
		It.Value().Remove(Listener);
		if (It.Value().Num() == 0)
		{
			It.RemoveCurrent();
		}
	}
}

void UGameplayQuestEventSubsystem::BroadcastQuestEvent(FGameplayQuestEventPayload& Payload)
{
	if (!Payload.EventTag.IsValid())
	{
		return;
	}

	// Auto-stamp current zone if payload does not explicitly specify one
	if (!Payload.ZoneTag.IsValid())
	{
		Payload.ZoneTag = CurrentWorldZoneTag;
	}

	// Find interested listeners for this exact tag
	TSet<TWeakObjectPtr<UGameplayQuestManagerComponent>>* Listeners = InvertedInterestTable.Find(Payload.EventTag);
	if (!Listeners || Listeners->Num() == 0)
	{
		return;
	}

	// Make snapshot to avoid iterator invalidation during dispatch
	TArray<UGameplayQuestManagerComponent*> ValidListeners;
	ValidListeners.Reserve(Listeners->Num());

	bool bHasStalePointers = false;
	for (const TWeakObjectPtr<UGameplayQuestManagerComponent>& WeakComp : *Listeners)
	{
		if (UGameplayQuestManagerComponent* Comp = WeakComp.Get())
		{
			ValidListeners.Add(Comp);
		}
		else
		{
			bHasStalePointers = true;
		}
	}

	// Clean up stale listeners if any detected
	if (bHasStalePointers)
	{
		Listeners->Remove(nullptr);
		if (Listeners->Num() == 0)
		{
			InvertedInterestTable.Remove(Payload.EventTag);
		}
	}

	// O(K) dispatch to interested listeners only
	for (UGameplayQuestManagerComponent* Comp : ValidListeners)
	{
		if (IsValid(Comp))
		{
			Comp->ProcessQuestEvent(Payload);
		}
	}
}

int32 UGameplayQuestEventSubsystem::GetListenerCountForTag(const FGameplayTag& EventTag) const
{
	if (const TSet<TWeakObjectPtr<UGameplayQuestManagerComponent>>* Listeners = InvertedInterestTable.Find(EventTag))
	{
		int32 Count = 0;
		for (const TWeakObjectPtr<UGameplayQuestManagerComponent>& WeakComp : *Listeners)
		{
			if (WeakComp.IsValid())
			{
				++Count;
			}
		}
		return Count;
	}
	return 0;
}

int32 UGameplayQuestEventSubsystem::GetChannelCount() const
{
	return InvertedInterestTable.Num();
}
