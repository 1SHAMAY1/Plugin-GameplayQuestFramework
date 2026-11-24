// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestTypes.h"
#include "GameplayObjectiveDefinition.generated.h"

/**
 * Designer-first, modular, instanced base class for all quest objectives.
 *
 * Authored inline within UGameplayQuestDefinition via EditInlineNew & DefaultToInstanced.
 * Zero hardcoding: completely driven by FGameplayTag channels and query conditions.
 * Extensible in C++ and Blueprint (UCLASS(Blueprintable, BlueprintType, EditInlineNew, Abstract)).
 */
UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class GAMEPLAYQUESTFRAMEWORK_API UGameplayObjectiveDefinition : public UObject
{
	GENERATED_BODY()

public:
	UGameplayObjectiveDefinition(const FObjectInitializer& ObjectInitializer);

	/** Unique identifier tag for this objective within the quest (e.g. Quest.Objective.DefeatGoblins). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Objective", meta = (Categories = "Quest.Objective"))
	FGameplayTag ObjectiveTag;

	/** User-facing display description (e.g. "Eliminate 5 Cave Goblins"). Supports text localization. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Objective")
	FText DescriptionText;

	/** Total count or threshold required to fulfill this objective. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Objective", meta = (ClampMin = "1"))
	int32 RequiredCount = 1;

	/** If true, failing or skipping this objective does not block quest completion. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Objective")
	bool bIsOptional = false;

	/** If true, this objective is hidden from the player HUD/journal until revealed or completed. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Objective")
	bool bIsHidden = false;

	/** Multiplayer sharing policy tag (e.g. Quest.Policy.Sharing.PartyUniform, Proximity, SoloOnly). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Multiplayer", meta = (Categories = "Quest.Policy.Sharing"))
	FGameplayTag SharingPolicyTag;

	/**
	 * World / Zone scope tag (e.g. Zone.Dungeon.Cave).
	 * If set, only events stamped with this exact zone (or matching parent zone) will progress this objective.
	 * If empty, the objective progresses in any world/zone.
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "World Scoping", meta = (Categories = "Zone"))
	FGameplayTag ZoneScopeTag;

	/** Primary event channel this objective subscribes to on the zero-tick event bus. */
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category = "Objective")
	FGameplayTag GetEventChannelTag() const;
	virtual FGameplayTag GetEventChannelTag_Implementation() const;

	/** Evaluates whether an incoming event payload matches this objective's criteria. */
	UFUNCTION(BlueprintNativeEvent, Category = "Objective")
	bool MatchesEvent(const FGameplayQuestEventPayload& Payload) const;
	virtual bool MatchesEvent_Implementation(const FGameplayQuestEventPayload& Payload) const;

	/** Evaluates how much progress an incoming event yields (default is Payload.Quantity). */
	UFUNCTION(BlueprintNativeEvent, Category = "Objective")
	int32 EvaluateProgressYield(const FGameplayQuestEventPayload& Payload) const;
	virtual int32 EvaluateProgressYield_Implementation(const FGameplayQuestEventPayload& Payload) const;

	/** Designer validation: validates that the objective is properly configured without missing tags. */
#if WITH_EDITOR
	virtual EDataValidationResult IsDataValid(class FDataValidationContext& Context) const;
#endif
};
