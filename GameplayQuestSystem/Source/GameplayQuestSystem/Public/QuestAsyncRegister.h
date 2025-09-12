#pragma once

#include "QuestAsyncActionBase.h"
#include "QuestAsyncRegister.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FQuestAsyncRegister, UGameplayQuestBase*, Quest, UQuestAsyncRegister*, Task);

/**
 * UQuestAsyncRegister
 *
 * Asynchronous Blueprint node for registering quests at runtime.
 * Allows Blueprints to register a quest by tag and class without blocking execution,
 * handling the asset loading asynchronously.
 *
 * Key Features:
 * - Supports asynchronous quest class loading via TSoftClassPtr.
 * - Fires `OnRegisterSuccess` when the quest is successfully registered.
 * - Fires `OnRegisterFail` if registration fails (invalid class or tag).
 * - Tracks the source actor for context during quest registration.
 *
 * Usage:
 * Call `RegisterQuest` in Blueprints to initiate quest registration.
 * Bind to `OnRegisterSuccess` or `OnRegisterFail` to handle the result asynchronously.
 */
UCLASS()
class GAMEPLAYQUESTSYSTEM_API UQuestAsyncRegister : public UQuestAsyncActionBase
{
    GENERATED_BODY()

public:
    /**
     * Starts an asynchronous quest registration task.
     * @param QuestTag Tag identifying the quest to register.
     * @param QuestClass Soft reference to the quest class to load and register.
     * @param Source Optional actor associated with the quest registration.
     * @return A UQuestAsyncRegister object representing the async task.
     */
    UFUNCTION(BlueprintCallable, meta=(BlueprintInternalUseOnly="true"), Category="Quest|Async")
    static UQuestAsyncRegister* RegisterQuest(FGameplayTag QuestTag, TSoftClassPtr<UGameplayQuestBase> QuestClass, AActor* Source);

    /** Called when the async action is activated */
    virtual void Activate() override;

    /** Delegate called when the quest is successfully registered */
    UPROPERTY(BlueprintAssignable)
    FQuestAsyncRegister OnRegisterSuccess;

    /** Delegate called if quest registration fails */
    UPROPERTY(BlueprintAssignable)
    FQuestAsyncRegister OnRegisterFail;

protected:
    /** Tag of the quest pending registration */
    FGameplayTag PendingQuestTag;

    /** Soft reference to the quest class pending registration */
    TSoftClassPtr<UGameplayQuestBase> PendingQuestClass;

    /** Called internally when the quest class asset finishes loading */
    void HandleQuestClassLoaded();

    /** Optional actor associated with the quest registration */
    UPROPERTY()
    AActor* Source;
};
