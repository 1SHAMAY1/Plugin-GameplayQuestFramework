// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestReward.h"
#include "GameplayQuestModule.h"
#include "GameFramework/Actor.h"

UGameplayQuestReward::UGameplayQuestReward(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UGameplayQuestReward::GrantReward_Implementation(AActor* Recipient)
{
}

void UGameplayQuestNumericReward::GrantReward_Implementation(AActor* Recipient)
{
	if (!Recipient)
	{
		return;
	}

	UE_LOG(LogGameplayQuest, Log, TEXT("Granted Numeric Reward %s x%d to %s"),
		*RewardTypeTag.ToString(), Amount, *Recipient->GetName());
}

void UGameplayQuestItemReward::GrantReward_Implementation(AActor* Recipient)
{
	if (!Recipient)
	{
		return;
	}

	UE_LOG(LogGameplayQuest, Log, TEXT("Granted Item Reward %s x%d to %s"),
		*ItemTag.ToString(), Quantity, *Recipient->GetName());
}
