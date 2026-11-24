// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "GameplayTagContainer.h"
#include "AnimNotifyState_GameplayQuestWindow.generated.h"

/**
 * Generic Animation Notify State defining a temporal window for quest events
 * (e.g., QTE windows, sustained interaction animations, channel ritual windows).
 */
UCLASS(meta = (DisplayName = "Quest Event Window"))
class GAMEPLAYQUESTFRAMEWORK_API UAnimNotifyState_GameplayQuestWindow : public UAnimNotifyState
{
	GENERATED_BODY()

public:
	UAnimNotifyState_GameplayQuestWindow();

	/** Event tag broadcast when the animation window begins. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework|Window", meta = (Categories = "Quest.Event"))
	FGameplayTag BeginEventTag;

	/** Event tag broadcast when the animation window ends. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework|Window", meta = (Categories = "Quest.Event"))
	FGameplayTag EndEventTag;

	/** Additional contextual tags applied to both start and end events. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Framework|Window")
	FGameplayTagContainer WindowContextTags;

	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	virtual FString GetNotifyName_Implementation() const override;
};
