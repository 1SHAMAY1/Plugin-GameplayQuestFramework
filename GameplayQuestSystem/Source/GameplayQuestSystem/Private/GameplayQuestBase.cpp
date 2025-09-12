#include "GameplayQuestBase.h"
#include "GameplayQuestSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Engine/Engine.h"                
#include "Engine/GameInstance.h"   

void UGameplayQuestBase::StartQuest_Implementation()
{
	CurrentProgress = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("Quest [%s] started."), *QuestTag.ToString());
}

void UGameplayQuestBase::CompleteQuest_Implementation()
{
	CurrentProgress = 1.0f;
	if (UGameplayQuestSubsystem* Subsystem = GetQuestSubsystem())
	{
		Subsystem->CompleteQuest(QuestTag);
	}
	UE_LOG(LogTemp, Log, TEXT("Quest [%s] completed."), *QuestTag.ToString());
}

void UGameplayQuestBase::ResetQuest_Implementation()
{
	CurrentProgress = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("Quest [%s] reset."), *QuestTag.ToString());
}

void UGameplayQuestBase::UpdateProgress(float NewProgress)
{
	// Add new and clamp between 0.0 and 1.0
	CurrentProgress = FMath::Clamp(CurrentProgress + NewProgress, 0.0f, 1.0f);

	// Auto-complete if progress reaches 1.0
	if (CurrentProgress >= 1.0f)
	{
		CompleteQuest();
	}
}

UGameplayQuestSubsystem* UGameplayQuestBase::GetQuestSubsystem() const
{
	for (const FWorldContext& Context : GEngine->GetWorldContexts())
		if (Context.WorldType == EWorldType::Game || Context.WorldType == EWorldType::PIE)
			if (UWorld* World = Context.World())
				if (UGameInstance* GI = World->GetGameInstance())
					return GI->GetSubsystem<UGameplayQuestSubsystem>();
	return nullptr;
}
