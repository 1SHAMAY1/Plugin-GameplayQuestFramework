#include "QuestAsyncListen.h"
#include "GameplayQuestSubsystem.h"
#include "GameplayQuestSystem.h"

UQuestAsyncListen* UQuestAsyncListen::ListenQuestEvents(const bool bAutoEndTaskOnFailed, const bool bAutoEndTaskOnCompleted,
	const bool bAutoEndTaskOnAbandoned)
{
	UQuestAsyncListen* Node = NewObject<UQuestAsyncListen>();
	Node->bAutoEndTaskOnAbandoned = bAutoEndTaskOnAbandoned;
	Node->bAutoEndTaskOnCompleted = bAutoEndTaskOnCompleted;
	Node->bAutoEndTaskOnFailed = bAutoEndTaskOnFailed;
	QUEST_LOG_GENERAL(TEXT("Quest async listen node created."));
	return Node;
}

void UQuestAsyncListen::Activate()
{
	if (UGameplayQuestSubsystem* Subsystem = GetQuestSubsystem())
	{
		Subsystem->OnQuestEventBP.AddDynamic(this, &UQuestAsyncListen::HandleQuestEvent);
		QUEST_LOG_GENERAL(TEXT("Quest async listen node activated. Subscribed to quest events."));
	}
	else
	{
		QUEST_LOG_FAILED(TEXT("Quest async listen node could not find GameplayQuestSubsystem."));
	}
}

void UQuestAsyncListen::HandleQuestEvent(EQuestState State, const FQuestPayload& Payload)
{
	QUEST_LOG_GENERAL(TEXT("Quest event received: State=[%d], Payload ID=[%s]"), 
		(int32)State, *Payload.QuestMessage.ToString());

	// Broadcast to BP
	OnEventReceived.Broadcast(State, Payload, this);

	switch (State)
	{
	case EQuestState::Started:
		QUEST_LOG_STARTED(TEXT("Quest started.[%s]"), *Payload.QuestMessage.ToString());
		break;

	case EQuestState::Completed:
		QUEST_LOG_COMPLETED(TEXT("Quest completed.[%s]"), *Payload.QuestMessage.ToString());
		if (bAutoEndTaskOnCompleted)
		{
			QUEST_LOG_GENERAL(TEXT("Destroying listen node (Completed)."));
			EndTask();
		}
		break;

	case EQuestState::Failed:
		QUEST_LOG_FAILED(TEXT("Quest failed.[%s]"), *Payload.QuestMessage.ToString());
		if (bAutoEndTaskOnFailed)
		{
			QUEST_LOG_GENERAL(TEXT("Destroying listen node (Failed)."));
			EndTask();
		}
		break;

	case EQuestState::Abandoned:
		QUEST_LOG_ABANDONED(TEXT("Quest abandoned.[%s]"), *Payload.QuestMessage.ToString());
		if (bAutoEndTaskOnAbandoned)
		{
			QUEST_LOG_GENERAL(TEXT("Destroying listen node (Abandoned)."));
			EndTask();
		}
		break;

	default:
		QUEST_LOG_GENERAL(TEXT("Quest updated state:[%s] %d"), *Payload.QuestMessage.ToString(), (int32)State);
		break;
	}
}

