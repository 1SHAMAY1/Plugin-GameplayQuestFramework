// Copyright Epic Games, Inc. All Rights Reserved.

#include "UI/SGameplayQuestDebugHUD.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestRecords.h"
#include "GameplayQuestDefinition.h"
#include "Widgets/Layout/SBorder.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SBoxPanel.h"

void SGameplayQuestDebugHUD::Construct(const FArguments& InArgs)
{
	QuestManager = InArgs._QuestManager;

	ChildSlot
	[
		SNew(SBox)
		.Padding(FMargin(20.0f, 60.0f, 0.0f, 0.0f))
		[
			SNew(SBorder)
			.BorderBackgroundColor(FLinearColor(0.0f, 0.0f, 0.0f, 0.75f))
			.Padding(FMargin(14.0f))
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.0f, 0.0f, 0.0f, 8.0f)
				[
					SNew(STextBlock)
					.Text(FText::FromString(TEXT("=== GAMEPLAY QUEST DEBUG HUD ===")))
					.ColorAndOpacity(FLinearColor(1.0f, 0.85f, 0.2f))
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				.Padding(0.0f, 0.0f, 0.0f, 6.0f)
				[
					SNew(STextBlock)
					.Text(this, &SGameplayQuestDebugHUD::GetQuestStatusOverviewText)
					.ColorAndOpacity(FLinearColor(0.8f, 0.8f, 0.8f))
				]
				+ SVerticalBox::Slot()
				.AutoHeight()
				[
					SNew(STextBlock)
					.Text(this, &SGameplayQuestDebugHUD::GetActiveQuestsDetailText)
					.ColorAndOpacity(FLinearColor::White)
				]
			]
		]
	];
}

void SGameplayQuestDebugHUD::SetQuestManager(UGameplayQuestManagerComponent* InQuestManager)
{
	QuestManager = InQuestManager;
}

FText SGameplayQuestDebugHUD::GetQuestStatusOverviewText() const
{
	if (!QuestManager.IsValid())
	{
		return FText::FromString(TEXT("Status: No Quest Manager Bound"));
	}

	const FGameplayQuestRecordList& Records = QuestManager->GetActiveQuestList();
	return FText::FromString(FString::Printf(TEXT("Active Quests: %d"), Records.Items.Num()));
}

FText SGameplayQuestDebugHUD::GetActiveQuestsDetailText() const
{
	if (!QuestManager.IsValid())
	{
		return FText::FromString(TEXT("Attach to player controller via `quest.hud` or API."));
	}

	const FGameplayQuestRecordList& Records = QuestManager->GetActiveQuestList();
	if (Records.Items.Num() == 0)
	{
		return FText::FromString(TEXT("No active quests currently tracked."));
	}

	FString OutString;
	for (const FGameplayQuestRecord& QuestRec : Records.Items)
	{
		OutString += FString::Printf(TEXT("[Quest: %s]\n  Stage: %d | Status: %s\n"),
			*QuestRec.QuestTag.ToString(),
			QuestRec.CurrentStageIndex,
			*QuestRec.StatusTag.ToString());

		for (const FGameplayObjectiveRecord& ObjRec : QuestRec.ObjectiveRecords)
		{
			OutString += FString::Printf(TEXT("    - %s: %d / %d (%s)\n"),
				*ObjRec.ObjectiveTag.ToString(),
				ObjRec.CurrentProgress,
				ObjRec.RequiredCount,
				*ObjRec.StatusTag.ToString());
		}
		OutString += TEXT("\n");
	}

	return FText::FromString(OutString);
}
