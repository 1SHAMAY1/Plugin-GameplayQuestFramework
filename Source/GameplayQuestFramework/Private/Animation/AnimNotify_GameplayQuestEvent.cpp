// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/AnimNotify_GameplayQuestEvent.h"
#include "GameplayQuestFunctionLibrary.h"
#include "GameplayQuestTags.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"

UAnimNotify_GameplayQuestEvent::UAnimNotify_GameplayQuestEvent()
{
	EventChannelTag = GameplayQuestTags::TAG_Quest_Event_Interact.GetTag();
	Quantity = 1;
}

void UAnimNotify_GameplayQuestEvent::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (!MeshComp)
	{
		return;
	}

	AActor* OwnerActor = MeshComp->GetOwner();
	if (!OwnerActor)
	{
		return;
	}

	FGameplayQuestEventPayload Payload;
	Payload.EventTag = EventChannelTag.IsValid() ? EventChannelTag : GameplayQuestTags::TAG_Quest_Event_Custom.GetTag();
	Payload.Instigator = OwnerActor;
	Payload.TargetActor = OwnerActor;
	Payload.Quantity = FMath::Max(1, Quantity);
	Payload.ContextTags = ContextTags;

	if (TargetTag.IsValid())
	{
		Payload.ContextTags.AddTag(TargetTag);
	}

	UGameplayQuestFunctionLibrary::BroadcastQuestEvent(OwnerActor, Payload);
}

FString UAnimNotify_GameplayQuestEvent::GetNotifyName_Implementation() const
{
	if (EventChannelTag.IsValid())
	{
		return FString::Printf(TEXT("Quest Event: %s"), *EventChannelTag.ToString());
	}
	return TEXT("Quest Event");
}
