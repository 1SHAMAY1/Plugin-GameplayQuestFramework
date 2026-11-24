// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestGiverComponent.h"
#include "GameplayQuestDefinition.h"
#include "GameplayQuestFunctionLibrary.h"
#include "GameplayQuestTags.h"

UGameplayQuestGiverComponent::UGameplayQuestGiverComponent(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryComponentTick.bCanEverTick = false;
	DefaultGiverState = GameplayQuestTags::TAG_Quest_Giver_Available.GetTag();
}

void UGameplayQuestGiverComponent::GetOfferedQuests_Implementation(const AActor* Interactor, TArray<FGameplayTag>& OutQuests) const
{
	OutQuests.Reset();
	for (const TObjectPtr<UGameplayQuestDefinition>& QuestDef : OfferedQuests)
	{
		if (QuestDef && QuestDef->QuestTag.IsValid())
		{
			OutQuests.AddUnique(QuestDef->QuestTag);
		}
	}

	for (const TSoftObjectPtr<UGameplayQuestDefinition>& SoftQuestDef : SoftOfferedQuests)
	{
		if (const UGameplayQuestDefinition* QuestDef = SoftQuestDef.Get())
		{
			if (QuestDef->QuestTag.IsValid())
			{
				OutQuests.AddUnique(QuestDef->QuestTag);
			}
		}
	}
}

FGameplayTag UGameplayQuestGiverComponent::GetQuestGiverStateTag_Implementation(const AActor* Interactor) const
{
	if (!Interactor)
	{
		return DefaultGiverState;
	}

	bool bHasAvailable = false;
	bool bHasInProgress = false;

	for (const TObjectPtr<UGameplayQuestDefinition>& QuestDef : OfferedQuests)
	{
		if (!QuestDef || !QuestDef->QuestTag.IsValid())
		{
			continue;
		}

		const FGameplayTag QuestStatus = UGameplayQuestFunctionLibrary::GetQuestStatus(Interactor, QuestDef->QuestTag);

		if (QuestStatus == GameplayQuestTags::TAG_Quest_Status_Active_ReadyToTurnIn.GetTag())
		{
			return GameplayQuestTags::TAG_Quest_Giver_ReadyToTurnIn.GetTag();
		}
		else if (QuestStatus == GameplayQuestTags::TAG_Quest_Status_Active_InProgress.GetTag())
		{
			bHasInProgress = true;
		}
		else if (QuestStatus == GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag())
		{
			bHasAvailable = true;
		}
	}

	for (const TSoftObjectPtr<UGameplayQuestDefinition>& SoftQuestDef : SoftOfferedQuests)
	{
		const UGameplayQuestDefinition* QuestDef = SoftQuestDef.Get();
		if (!QuestDef || !QuestDef->QuestTag.IsValid())
		{
			continue;
		}

		const FGameplayTag QuestStatus = UGameplayQuestFunctionLibrary::GetQuestStatus(Interactor, QuestDef->QuestTag);

		if (QuestStatus == GameplayQuestTags::TAG_Quest_Status_Active_ReadyToTurnIn.GetTag())
		{
			return GameplayQuestTags::TAG_Quest_Giver_ReadyToTurnIn.GetTag();
		}
		else if (QuestStatus == GameplayQuestTags::TAG_Quest_Status_Active_InProgress.GetTag())
		{
			bHasInProgress = true;
		}
		else if (QuestStatus == GameplayQuestTags::TAG_Quest_Status_NotStarted.GetTag())
		{
			bHasAvailable = true;
		}
	}

	if (bHasInProgress)
	{
		return GameplayQuestTags::TAG_Quest_Giver_InProgress.GetTag();
	}

	if (bHasAvailable)
	{
		return GameplayQuestTags::TAG_Quest_Giver_Available.GetTag();
	}

	return GameplayQuestTags::TAG_Quest_Giver_None.GetTag();
}
