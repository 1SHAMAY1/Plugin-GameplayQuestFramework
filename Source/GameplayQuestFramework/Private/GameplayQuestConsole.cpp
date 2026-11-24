// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HAL/IConsoleManager.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestFunctionLibrary.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestEventSubsystem.h"
#include "GameplayQuestModule.h"
#include "UI/SGameplayQuestDebugHUD.h"
#include "Engine/World.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"

namespace GameplayQuestConsole
{
	static TSharedPtr<SGameplayQuestDebugHUD> ActiveDebugHUD = nullptr;
	static UWorld* GetConsoleWorld()
	{
		if (GEngine)
		{
			for (const FWorldContext& Context : GEngine->GetWorldContexts())
			{
				if (Context.World() && (Context.WorldType == EWorldType::Game || Context.WorldType == EWorldType::PIE))
				{
					return Context.World();
				}
			}
		}
		return nullptr;
	}

	static FAutoConsoleCommand CVarQuestList(
		TEXT("quest.list"),
		TEXT("Prints all active, completed, and failed quests for the local player."),
		FConsoleCommandDelegate::CreateLambda([]()
		{
			UWorld* World = GetConsoleWorld();
			if (!World)
			{
				UE_LOG(LogGameplayQuest, Warning, TEXT("[quest.list] No active game world found."));
				return;
			}

			APlayerController* PC = World->GetFirstPlayerController();
			if (!PC)
			{
				UE_LOG(LogGameplayQuest, Warning, TEXT("[quest.list] No local PlayerController found."));
				return;
			}

			if (UGameplayQuestManagerComponent* Manager = UGameplayQuestFunctionLibrary::GetQuestManager(PC))
			{
				UE_LOG(LogGameplayQuest, Log, TEXT("--- [Quest List for %s] ---"), *PC->GetName());
				// Active quests
				const FGameplayQuestSaveData SaveData = Manager->ExportSaveData(FGuid());
				UE_LOG(LogGameplayQuest, Log, TEXT("Active Quests (%d):"), SaveData.ActiveQuests.Num());
				for (const FGameplayQuestSaveRecord& Rec : SaveData.ActiveQuests)
				{
					UE_LOG(LogGameplayQuest, Log, TEXT("  - %s (Stage: %d, Status: %s)"),
						*Rec.QuestTag.ToString(), Rec.CurrentStageIndex, *Rec.StatusTag.ToString());
					for (const FGameplayObjectiveSaveRecord& Obj : Rec.Objectives)
					{
						UE_LOG(LogGameplayQuest, Log, TEXT("      * %s [%d / %d] (%s)"),
							*Obj.ObjectiveTag.ToString(), Obj.CurrentProgress, Obj.RequiredCount, *Obj.StatusTag.ToString());
					}
				}

				UE_LOG(LogGameplayQuest, Log, TEXT("Completed Quests (%d): %s"),
					SaveData.CompletedQuests.Num(), *SaveData.CompletedQuests.ToStringSimple());
				UE_LOG(LogGameplayQuest, Log, TEXT("Failed Quests (%d): %s"),
					SaveData.FailedQuests.Num(), *SaveData.FailedQuests.ToStringSimple());
			}
			else
			{
				UE_LOG(LogGameplayQuest, Warning, TEXT("[quest.list] No UGameplayQuestManagerComponent found on player."));
			}
		})
	);

	static FAutoConsoleCommandWithWorldAndArgs CVarQuestAdvance(
		TEXT("quest.progress"),
		TEXT("Advances objective progress: quest.progress <QuestTag> <ObjectiveTag> <Amount>"),
		FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, UWorld* World)
		{
			if (Args.Num() < 2)
			{
				UE_LOG(LogGameplayQuest, Warning, TEXT("Usage: quest.progress <QuestTag> <ObjectiveTag> [Amount=1]"));
				return;
			}

			if (!World)
			{
				World = GetConsoleWorld();
			}
			if (!World)
			{
				return;
			}

			APlayerController* PC = World->GetFirstPlayerController();
			if (!PC)
			{
				return;
			}

			UGameplayQuestManagerComponent* Manager = UGameplayQuestFunctionLibrary::GetQuestManager(PC);
			if (!Manager)
			{
				return;
			}

			const FGameplayTag QuestTag = FGameplayTag::RequestGameplayTag(FName(*Args[0]), false);
			const FGameplayTag ObjectiveTag = FGameplayTag::RequestGameplayTag(FName(*Args[1]), false);
			const int32 Amount = (Args.Num() >= 3) ? FCString::Atoi(*Args[2]) : 1;

			if (Manager->AdvanceObjectiveProgress(QuestTag, ObjectiveTag, Amount))
			{
				UE_LOG(LogGameplayQuest, Log, TEXT("[quest.progress] Advanced %s -> %s by %d"),
					*QuestTag.ToString(), *ObjectiveTag.ToString(), Amount);
			}
			else
			{
				UE_LOG(LogGameplayQuest, Warning, TEXT("[quest.progress] Failed to advance objective."));
			}
		})
	);

	static FAutoConsoleCommandWithWorldAndArgs CVarQuestComplete(
		TEXT("quest.complete"),
		TEXT("Forces completion of an active quest: quest.complete <QuestTag>"),
		FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, UWorld* World)
		{
			if (Args.Num() < 1)
			{
				UE_LOG(LogGameplayQuest, Warning, TEXT("Usage: quest.complete <QuestTag>"));
				return;
			}

			if (!World)
			{
				World = GetConsoleWorld();
			}
			if (!World)
			{
				return;
			}

			APlayerController* PC = World->GetFirstPlayerController();
			if (!PC)
			{
				return;
			}

			if (UGameplayQuestManagerComponent* Manager = UGameplayQuestFunctionLibrary::GetQuestManager(PC))
			{
				const FGameplayTag QuestTag = FGameplayTag::RequestGameplayTag(FName(*Args[0]), false);
				if (Manager->CompleteQuest(QuestTag))
				{
					UE_LOG(LogGameplayQuest, Log, TEXT("[quest.complete] Successfully completed quest %s"), *QuestTag.ToString());
				}
				else
				{
					UE_LOG(LogGameplayQuest, Warning, TEXT("[quest.complete] Failed to complete quest %s"), *QuestTag.ToString());
				}
			}
		})
	);

	static FAutoConsoleCommand CVarQuestHUD(
		TEXT("quest.hud"),
		TEXT("Toggles the Slate Gameplay Quest Debug HUD overlay on the viewport."),
		FConsoleCommandDelegate::CreateLambda([]()
		{
			UWorld* World = GetConsoleWorld();
			if (!World || !GEngine || !GEngine->GameViewport)
			{
				UE_LOG(LogGameplayQuest, Warning, TEXT("[quest.hud] Viewport client or game world not available."));
				return;
			}

			if (ActiveDebugHUD.IsValid())
			{
				GEngine->GameViewport->RemoveViewportWidgetContent(ActiveDebugHUD.ToSharedRef());
				ActiveDebugHUD.Reset();
				UE_LOG(LogGameplayQuest, Log, TEXT("[quest.hud] Debug HUD disabled."));
			}
			else
			{
				APlayerController* PC = World->GetFirstPlayerController();
				UGameplayQuestManagerComponent* Manager = PC ? UGameplayQuestFunctionLibrary::GetQuestManager(PC) : nullptr;

				ActiveDebugHUD = SNew(SGameplayQuestDebugHUD)
					.QuestManager(Manager);

				GEngine->GameViewport->AddViewportWidgetContent(ActiveDebugHUD.ToSharedRef(), 100);
				UE_LOG(LogGameplayQuest, Log, TEXT("[quest.hud] Debug HUD enabled."));
			}
		})
	);
}
