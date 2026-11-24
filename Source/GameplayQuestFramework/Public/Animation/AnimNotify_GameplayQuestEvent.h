// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "GameplayTagContainer.h"
#include "AnimNotify_GameplayQuestEvent.generated.h"

/**
 * Generic Animation Notify for triggering Gameplay Quest Framework events directly from Montages,
 * Sequences, and Cinematics. Fully decoupled from specific character or weapon classes.
 */
UCLASS(meta = (DisplayName = "Broadcast Quest Event"))
class GAMEPLAYQUESTFRAMEWORK_API UAnimNotify_GameplayQuestEvent : public UAnimNotify
{
	GENERATED_BODY()

public:
	UAnimNotify_GameplayQuestEvent();

	/** Channel identifying the quest event type (e.g. Quest.Event.Interact, Quest.Event.Custom). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework|Event", meta = (Categories = "Quest.Event"))
	FGameplayTag EventChannelTag;

	/** Optional specific target or action tag (e.g. Target.Interact.Lever, Action.PerformRitual). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework|Event")
	FGameplayTag TargetTag;

	/** Quantity or progress magnitude to increment (defaults to 1). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework|Event", meta = (ClampMin = "1"))
	int32 Quantity = 1;

	/** Additional contextual gameplay tags to stamp onto the payload. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework|Event")
	FGameplayTagContainer ContextTags;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	virtual FString GetNotifyName_Implementation() const override;
};
