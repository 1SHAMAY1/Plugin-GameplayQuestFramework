#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "QuestTypes.generated.h"

UENUM(BlueprintType)
enum class EQuestState : uint8
{
	None       UMETA(DisplayName="None"),
	Started    UMETA(DisplayName="Started"),
	Completed  UMETA(DisplayName="Completed"),
	Failed     UMETA(DisplayName="Failed"),
	Abandoned  UMETA(DisplayName="Abandoned")
};

USTRUCT(BlueprintType)
struct FQuestPayload
{
	GENERATED_BODY()

public:

	/** Tag for the related event */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
	FGameplayTag EventTag;

	/** General message or description for the quest event */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
	FText QuestMessage;

	/** Tags for filtering and categorizing quest events */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
	FGameplayTagContainer Tags;

	/** Generic value (progress, score, damage amount, etc.) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest")
	float Magnitude = 0;

	/** Any additional objects to carry with the quest event */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest|References")
	TArray<TObjectPtr<UObject>> AdditionalObjectReferences;

	/** Actor who triggered the event (player, NPC, etc.) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest|Actors")
	TWeakObjectPtr<AActor> Instigator;

	/** The source of the quest event (item, system, actor, etc.) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest|Actors")
	TWeakObjectPtr<AActor> Source;

	/** The target actor of the quest event */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Quest|Actors")
	TWeakObjectPtr<AActor> Target;
};
