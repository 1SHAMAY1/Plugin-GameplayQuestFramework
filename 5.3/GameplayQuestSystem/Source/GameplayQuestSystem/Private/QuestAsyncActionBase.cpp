#include "QuestAsyncActionBase.h"
#include "GameplayQuestSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Engine/StreamableManager.h"

void UQuestAsyncActionBase::Activate()
{
	// Base class does nothing
}

void UQuestAsyncActionBase::EndTask()
{
	// Remove async load handle if still pending
	if (PendingHandle.IsValid())
	{
		PendingHandle->CancelHandle();
		PendingHandle.Reset();
	}

	SetReadyToDestroy();
	MarkAsGarbage();

	UE_LOG(LogTemp, Verbose, TEXT("Quest async task [%s] ended and destroyed."), *GetName());
}

UWorld* UQuestAsyncActionBase::GetWorldRef() const
{
	if (!GEngine) return nullptr;

	// Return the first Game or PIE world
	for (const FWorldContext& Context : GEngine->GetWorldContexts())
	{
		if (Context.WorldType == EWorldType::Game || Context.WorldType == EWorldType::PIE)
		{
			return Context.World();
		}
	}

	return nullptr;
}

UGameplayQuestSubsystem* UQuestAsyncActionBase::GetQuestSubsystem() const
{
	if (UWorld* World = GetWorldRef())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			return GI->GetSubsystem<UGameplayQuestSubsystem>();
		}
	}
	return nullptr;
}
