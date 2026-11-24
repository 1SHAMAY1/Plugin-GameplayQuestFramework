// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/AnimNotifyState_GameplayQuestWindow.h"
#include "GameplayQuestFunctionLibrary.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"

UAnimNotifyState_GameplayQuestWindow::UAnimNotifyState_GameplayQuestWindow()
{
}

void UAnimNotifyState_GameplayQuestWindow::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (!MeshComp || !BeginEventTag.IsValid())
	{
		return;
	}

	AActor* OwnerActor = MeshComp->GetOwner();
	if (!OwnerActor)
	{
		return;
	}

	FGameplayQuestEventPayload Payload;
	Payload.EventTag = BeginEventTag;
	Payload.Instigator = OwnerActor;
	Payload.TargetActor = OwnerActor;
	Payload.Quantity = 1;
	Payload.ContextTags = WindowContextTags;

	UGameplayQuestFunctionLibrary::BroadcastQuestEvent(OwnerActor, Payload);
}

void UAnimNotifyState_GameplayQuestWindow::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (!MeshComp || !EndEventTag.IsValid())
	{
		return;
	}

	AActor* OwnerActor = MeshComp->GetOwner();
	if (!OwnerActor)
	{
		return;
	}

	FGameplayQuestEventPayload Payload;
	Payload.EventTag = EndEventTag;
	Payload.Instigator = OwnerActor;
	Payload.TargetActor = OwnerActor;
	Payload.Quantity = 1;
	Payload.ContextTags = WindowContextTags;

	UGameplayQuestFunctionLibrary::BroadcastQuestEvent(OwnerActor, Payload);
}

FString UAnimNotifyState_GameplayQuestWindow::GetNotifyName_Implementation() const
{
	if (BeginEventTag.IsValid() && EndEventTag.IsValid())
	{
		return FString::Printf(TEXT("Quest Window: %s -> %s"), *BeginEventTag.ToString(), *EndEventTag.ToString());
	}
	return TEXT("Quest Event Window");
}
