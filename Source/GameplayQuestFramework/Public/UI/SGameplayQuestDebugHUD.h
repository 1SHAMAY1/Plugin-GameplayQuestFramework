// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"

class UGameplayQuestManagerComponent;

/**
 * Lightweight Slate compound widget for real-time visual quest and objective debugging.
 * Can be attached to the GameViewportClient to provide an on-screen HUD without any Blueprints.
 */
class GAMEPLAYQUESTFRAMEWORK_API SGameplayQuestDebugHUD : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SGameplayQuestDebugHUD)
		: _QuestManager(nullptr)
	{}
		SLATE_ARGUMENT(TWeakObjectPtr<UGameplayQuestManagerComponent>, QuestManager)
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Update target quest manager to observe */
	void SetQuestManager(UGameplayQuestManagerComponent* InQuestManager);

private:
	FText GetQuestStatusOverviewText() const;
	FText GetActiveQuestsDetailText() const;

	TWeakObjectPtr<UGameplayQuestManagerComponent> QuestManager;
};
