#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "QuestTypes.h"
#include "Engine/DataTable.h"
#include "GameplayQuestBase.generated.h"

class UGameplayQuestSubsystem;

/**
 * UGameplayQuestBase
 * 
 * Base class for all gameplay quests in the system. 
 * Designed to be subclassed in Blueprint or C++, allowing flexible quest creation.
 * 
 * Key Attributes:
 * - Abstract: Cannot be instantiated directly; intended as a base for derived quest types.
 * - Blueprintable: Can be extended and implemented in Blueprints.
 * - EditInlineNew: Allows creation and editing of instances directly within asset properties.
 * - DefaultToInstanced: Ensures default subobjects are instanced rather than shared references.
 */
UCLASS(Abstract, Blueprintable, EditInlineNew, DefaultToInstanced)
class GAMEPLAYQUESTSYSTEM_API UGameplayQuestBase : public UObject
{
	GENERATED_BODY()

public:

	/** Core Quest Data (Editable in Class Defaults) */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	FGameplayTag QuestTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	FText DescriptionRichText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest")
	UDataTable* RichTextStyleTable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest|Tags")
	FGameplayTagContainer CancelQuestTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest|Tags")
	FGameplayTagContainer RestartQuestTags;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Quest|Tags")
	FGameplayTagContainer RelatedQuestTags;

	/** Who triggered the quest (optional reference) */
	UPROPERTY(BlueprintReadWrite, Category="Quest")
	TWeakObjectPtr<AActor> Source;
	
	/** Internal Progress (0.0 → 1.0) */
	UPROPERTY(BlueprintReadWrite, Category="Quest|State")
	float CurrentProgress = 0.0f;

	/** Native Events */
	UFUNCTION(BlueprintNativeEvent, Category="Quest")
	void StartQuest();
	virtual void StartQuest_Implementation();

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="Quest")
	void CompleteQuest();
	virtual void CompleteQuest_Implementation();

	UFUNCTION(BlueprintNativeEvent,BlueprintCallable, Category="Quest")
	void ResetQuest();
	virtual void ResetQuest_Implementation();

	/** Add to the quest progress (0.0 → 1.0). If >= 1.0, automatically completes the quest */
	UFUNCTION(BlueprintCallable, Category="Quest|State")
	virtual void UpdateProgress(float NewProgress);

	UFUNCTION(BlueprintPure, Category="Quest|Subsystem")
	UGameplayQuestSubsystem* GetQuestSubsystem() const;
};
