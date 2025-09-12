#include "GameplayQuestSubsystem.h"
#include "GameplayQuestBase.h"
#include "GameplayQuestSystem.h"

void UGameplayQuestSubsystem::RegisterQuest_Internal(FGameplayTag QuestTag, UGameplayQuestBase* Quest, AActor* Source)
{
	if (!Quest)
	{
		QUEST_LOG_FAILED(TEXT("RegisterQuest_Internal failed: Quest [%s] is nullptr"), *QuestTag.ToString());
		return;
	}

	// If the quest already exists in active list
	if (UGameplayQuestBase** ExistingQuestPtr = ActiveQuests.Find(QuestTag))
	{
		UGameplayQuestBase* ExistingQuest = *ExistingQuestPtr;
		if (ExistingQuest && ExistingQuest->CurrentProgress >= 1.0f)
		{
			// Quest is completed → remove it before restarting
			QUEST_LOG_GENERAL(TEXT("Quest [%s] was completed earlier, restarting..."), *QuestTag.ToString());
			ActiveQuests.Remove(QuestTag);
		}
		else
		{
			// Already active & not completed → don't restart
			QUEST_LOG_GENERAL(TEXT("Quest [%s] already active. Skipping registration."), *QuestTag.ToString());
			return;
		}
	}

	// Remove from CompletedQuests if present
	int32 RemovedCount = CompletedQuests.RemoveAll([&](const UGameplayQuestBase* CompletedQuest)
	{
		return CompletedQuest && CompletedQuest->QuestTag == QuestTag;
	});

	if (RemovedCount > 0)
	{
		QUEST_LOG_GENERAL(TEXT("Quest [%s] was in CompletedQuests. Removed %d instance(s) for restart."),
			*QuestTag.ToString(), RemovedCount);
	}

	// Register the new quest
	ActiveQuests.Add(QuestTag, Quest);
	Quest->StartQuest();

	QUEST_LOG_STARTED(TEXT("Quest [%s] started by [%s]."),
		*QuestTag.ToString(),
		Source ? *Source->GetName() : TEXT("Unknown"));

	// Build payload for event
	FQuestPayload Payload;
	Payload.QuestMessage = FText::FromString("Quest Started");
	Payload.Tags.AddTag(QuestTag);
	Payload.Source = Source;
	Payload.Magnitude = 0.0f; // progress starts at 0

	OnQuestEventBP.Broadcast(EQuestState::Started, Payload);
}


void UGameplayQuestSubsystem::CompleteQuest(FGameplayTag QuestTag)
{
	if (UGameplayQuestBase** FoundQuest = ActiveQuests.Find(QuestTag))
	{
		UGameplayQuestBase* Quest = *FoundQuest;
		CompletedQuests.Add(Quest);
		ActiveQuests.Remove(QuestTag);

		Quest->CompleteQuest();

		QUEST_LOG_COMPLETED(TEXT("Quest [%s] completed."), *QuestTag.ToString());

		// Build payload
		FQuestPayload Payload;
		Payload.QuestMessage = FText::FromString("Quest Completed");
		Payload.Tags.AddTag(QuestTag);
		Payload.Source = Quest->Source;
		Payload.Magnitude = 1.0f; // completed -> force to 1

		OnQuestEventBP.Broadcast(EQuestState::Completed, Payload);
	}
	else
	{
		QUEST_LOG_FAILED(TEXT("CompleteQuest failed: Quest [%s] not found in active list."), *QuestTag.ToString());
	}
}

void UGameplayQuestSubsystem::ResetQuest(FGameplayTag QuestTag)
{
	if (UGameplayQuestBase** FoundQuest = ActiveQuests.Find(QuestTag))
	{
		UGameplayQuestBase* Quest = *FoundQuest;
		Quest->ResetQuest();

		QUEST_LOG_GENERAL(TEXT("Quest [%s] has been reset."), *QuestTag.ToString());

		// Build payload
		FQuestPayload Payload;
		Payload.QuestMessage = FText::FromString("Quest Reset");
		Payload.Tags.AddTag(QuestTag);
		Payload.Source = Quest->Source;
		Payload.Magnitude = 0.0f; // reset -> progress goes back to 0

		// Use a dedicated state (if you have Reset/Restart), or Started again
		OnQuestEventBP.Broadcast(EQuestState::Started, Payload);
	}
	else
	{
		QUEST_LOG_FAILED(TEXT("ResetQuest failed: Quest [%s] not found in active list."), *QuestTag.ToString());
	}
}


void UGameplayQuestSubsystem::HandleQuestEvent(EQuestState State, const FQuestPayload& Payload)
{
	switch (State)
	{
	case EQuestState::Started:
		QUEST_LOG_STARTED(TEXT("Quest Event: [%s]"), *Payload.QuestMessage.ToString());
		break;
	case EQuestState::Completed:
		QUEST_LOG_COMPLETED(TEXT("Quest Event: [%s]"), *Payload.QuestMessage.ToString());
		break;
	case EQuestState::Failed:
		QUEST_LOG_FAILED(TEXT("Quest Event: [%s]"), *Payload.QuestMessage.ToString());
		break;
	case EQuestState::Abandoned:
		QUEST_LOG_ABANDONED(TEXT("Quest Event: [%s]"), *Payload.QuestMessage.ToString());
		break;
	default:
		QUEST_LOG_GENERAL(TEXT("Quest Event: [%s]"), *Payload.QuestMessage.ToString());
		break;
	}

	OnQuestEventBP.Broadcast(State, Payload);
}

bool UGameplayQuestSubsystem::IsQuestActive(FGameplayTag QuestTag) const
{
	return ActiveQuests.Contains(QuestTag);
}

