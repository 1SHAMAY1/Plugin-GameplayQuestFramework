#pragma once

#include "QuestAsyncActionBase.h"
#include "QuestAsyncListen.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FQuestAsyncEvent, EQuestState, State, FQuestPayload, Payload, UQuestAsyncListen*, Task);

/**
 * UQuestAsyncListen
 *
 * Asynchronous Blueprint node for listening to quest events.
 * Allows Blueprints to respond to quest state changes (e.g., Completed, Failed, Abandoned)
 * without blocking execution. Provides automatic task completion based on event type.
 *
 * Key Features:
 * - Can automatically end the async task when a quest is Completed, Failed, or Abandoned.
 * - Exposes a BlueprintAssignable event (`OnEventReceived`) for BP binding.
 * - Supports multiple event types via `FQuestAsyncEvent` delegate.
 *
 * Usage:
 * Call `ListenQuestEvents` in Blueprints to start listening to quest events.
 * Bind to `OnEventReceived` to handle quest updates asynchronously.
 */
UCLASS()
class GAMEPLAYQUESTSYSTEM_API UQuestAsyncListen : public UQuestAsyncActionBase
{
    GENERATED_BODY()

public:
    /** 
     * Starts listening to quest events asynchronously.
     * @param bAutoEndTaskOnFailed Automatically completes the task if the quest fails.
     * @param bAutoEndTaskOnCompleted Automatically completes the task if the quest is completed.
     * @param bAutoEndTaskOnAbandoned Automatically completes the task if the quest is abandoned.
     */
    UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true"), Category="Quest|Async")
    static UQuestAsyncListen* ListenQuestEvents(
        const bool bAutoEndTaskOnFailed = false,
        const bool bAutoEndTaskOnCompleted = true,
        const bool bAutoEndTaskOnAbandoned = false
    );

    /** Called when the async action is activated */
    virtual void Activate() override;

    /** Event that Blueprint can bind to for quest state updates */
    UPROPERTY(BlueprintAssignable)
    FQuestAsyncEvent OnEventReceived;

protected:
    /** Internal handler for quest events */
    UFUNCTION()
    void HandleQuestEvent(EQuestState State, const FQuestPayload& Payload);

    /** Flags to control automatic task completion based on quest state */
    UPROPERTY()
    bool bAutoEndTaskOnAbandoned;

    UPROPERTY()
    bool bAutoEndTaskOnCompleted;

    UPROPERTY()
    bool bAutoEndTaskOnFailed;
};
