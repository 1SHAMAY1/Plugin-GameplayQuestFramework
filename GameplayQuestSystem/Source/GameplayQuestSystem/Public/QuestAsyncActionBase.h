#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "QuestTypes.h"
#include "QuestAsyncActionBase.generated.h"

class UGameplayQuestBase;
class UGameplayQuestSubsystem;

/**
 * UQuestAsyncActionBase
 *
 * Abstract base class for asynchronous quest actions in the gameplay quest system.
 * Designed to be extended in Blueprints or C++ to implement async operations
 * such as quest registration, completion, or event-driven quest updates.
 *
 * Inherits from UBlueprintAsyncActionBase, allowing usage with Blueprint
 * nodes that support latent/asynchronous execution.
 *
 * Key Attributes:
 * - Abstract: Cannot be instantiated directly; must be subclassed for specific async actions.
 */
UCLASS(Abstract)
class GAMEPLAYQUESTSYSTEM_API UQuestAsyncActionBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	/** Activate node */
	virtual void Activate() override;

	/** Manually destroy this async task (exposed to BP) */
	UFUNCTION(BlueprintCallable, Category="Quest|Async")
	void EndTask();

protected:
	/** Resolve world from context object automatically */
	UWorld* GetWorldRef() const;

	/** Stored context */
	UPROPERTY()
	TWeakObjectPtr<UObject> WorldContext;

	/** Async streamable handle if needed */
	TSharedPtr<struct FStreamableHandle> PendingHandle;

	/** Internal helper to get subsystem */
	UGameplayQuestSubsystem* GetQuestSubsystem() const;
};
