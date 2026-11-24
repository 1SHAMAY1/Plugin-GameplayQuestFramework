// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestFunctionLibrary.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestEventSubsystem.h"
#include "Interfaces/IGameplayQuestManagerInterface.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestModule.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerState.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

UGameplayQuestManagerComponent* UGameplayQuestFunctionLibrary::GetQuestManager(const AActor* TargetActor)
{
	if (!TargetActor)
	{
		return nullptr;
	}

	// 1. Direct Interface Check (O(1))
	if (TargetActor->Implements<UGameplayQuestManagerInterface>())
	{
		if (UGameplayQuestManagerComponent* Comp = IGameplayQuestManagerInterface::Execute_GetQuestManagerComponent(TargetActor))
		{
			return Comp;
		}
	}

	// 2. Direct Component Check
	if (UGameplayQuestManagerComponent* DirectComp = TargetActor->FindComponentByClass<UGameplayQuestManagerComponent>())
	{
		return DirectComp;
	}

	// 3. Pawn traversal (Check PlayerState, then Controller)
	if (const APawn* Pawn = Cast<APawn>(TargetActor))
	{
		if (const APlayerState* PS = Pawn->GetPlayerState())
		{
			if (PS->Implements<UGameplayQuestManagerInterface>())
			{
				if (UGameplayQuestManagerComponent* Comp = IGameplayQuestManagerInterface::Execute_GetQuestManagerComponent(PS))
				{
					return Comp;
				}
			}
			if (UGameplayQuestManagerComponent* Comp = PS->FindComponentByClass<UGameplayQuestManagerComponent>())
			{
				return Comp;
			}
		}

		if (const AController* Controller = Pawn->GetController())
		{
			if (Controller->Implements<UGameplayQuestManagerInterface>())
			{
				if (UGameplayQuestManagerComponent* Comp = IGameplayQuestManagerInterface::Execute_GetQuestManagerComponent(Controller))
				{
					return Comp;
				}
			}
			if (UGameplayQuestManagerComponent* Comp = Controller->FindComponentByClass<UGameplayQuestManagerComponent>())
			{
				return Comp;
			}
		}
	}

	// 4. Controller traversal (Check PlayerState)
	if (const AController* Controller = Cast<AController>(TargetActor))
	{
		if (const APlayerState* PS = Controller->PlayerState)
		{
			if (PS->Implements<UGameplayQuestManagerInterface>())
			{
				if (UGameplayQuestManagerComponent* Comp = IGameplayQuestManagerInterface::Execute_GetQuestManagerComponent(PS))
				{
					return Comp;
				}
			}
			if (UGameplayQuestManagerComponent* Comp = PS->FindComponentByClass<UGameplayQuestManagerComponent>())
			{
				return Comp;
			}
		}
	}

	return nullptr;
}

void UGameplayQuestFunctionLibrary::BroadcastKillEvent(
	const UObject* WorldContextObject,
	AActor* Killer,
	AActor* Victim,
	FGameplayTag VictimTag)
{
	FGameplayQuestEventPayload Payload(GameplayQuestTags::TAG_Quest_Event_Kill.GetTag(), Killer, 1);
	Payload.TargetActor = Victim;
	if (VictimTag.IsValid())
	{
		Payload.ContextTags.AddTag(VictimTag);
	}
	BroadcastQuestEvent(WorldContextObject, Payload);
}

void UGameplayQuestFunctionLibrary::BroadcastCollectEvent(
	const UObject* WorldContextObject,
	AActor* Collector,
	FGameplayTag ItemTag,
	int32 Quantity)
{
	FGameplayQuestEventPayload Payload(GameplayQuestTags::TAG_Quest_Event_Collect.GetTag(), Collector, Quantity);
	if (ItemTag.IsValid())
	{
		Payload.ContextTags.AddTag(ItemTag);
	}
	BroadcastQuestEvent(WorldContextObject, Payload);
}

void UGameplayQuestFunctionLibrary::BroadcastInteractEvent(
	const UObject* WorldContextObject,
	AActor* Interactor,
	AActor* TargetActor,
	FGameplayTag InteractTag)
{
	FGameplayQuestEventPayload Payload(GameplayQuestTags::TAG_Quest_Event_Interact.GetTag(), Interactor, 1);
	Payload.TargetActor = TargetActor;
	if (InteractTag.IsValid())
	{
		Payload.ContextTags.AddTag(InteractTag);
	}
	BroadcastQuestEvent(WorldContextObject, Payload);
}

void UGameplayQuestFunctionLibrary::BroadcastAreaReachedEvent(
	const UObject* WorldContextObject,
	AActor* InstigatorPawn,
	FGameplayTag AreaTag)
{
	FGameplayQuestEventPayload Payload(GameplayQuestTags::TAG_Quest_Event_ReachArea.GetTag(), InstigatorPawn, 1);
	if (AreaTag.IsValid())
	{
		Payload.ContextTags.AddTag(AreaTag);
	}
	BroadcastQuestEvent(WorldContextObject, Payload);
}

void UGameplayQuestFunctionLibrary::BroadcastQuestEvent(
	const UObject* WorldContextObject,
	const FGameplayQuestEventPayload& Payload)
{
	if (!WorldContextObject)
	{
		return;
	}

	UWorld* World = GEngine ? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull) : nullptr;
	if (!World)
	{
		return;
	}

	// 1. Dispatch through zero-tick World Event Subsystem (inverted interest table)
	if (UGameplayQuestEventSubsystem* EventSubsystem = World->GetSubsystem<UGameplayQuestEventSubsystem>())
	{
		FGameplayQuestEventPayload MutablePayload = Payload;
		EventSubsystem->BroadcastQuestEvent(MutablePayload);
	}

	// 2. Direct fallback dispatch if Instigator has a manager component not registered
	if (Payload.Instigator)
	{
		if (UGameplayQuestManagerComponent* Manager = GetQuestManager(Payload.Instigator))
		{
			Manager->ProcessQuestEvent(Payload);
		}
	}
}

FGameplayTag UGameplayQuestFunctionLibrary::GetQuestStatus(const AActor* TargetActor, FGameplayTag QuestTag)
{
	if (const UGameplayQuestManagerComponent* Manager = GetQuestManager(TargetActor))
	{
		return Manager->GetQuestStatus(QuestTag);
	}
	return GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag();
}

bool UGameplayQuestFunctionLibrary::HasQuestStatus(const AActor* TargetActor, FGameplayTag QuestTag, FGameplayTag StatusTag)
{
	if (const UGameplayQuestManagerComponent* Manager = GetQuestManager(TargetActor))
	{
		return Manager->HasQuestStatus(QuestTag, StatusTag);
	}
	return StatusTag == GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag();
}
