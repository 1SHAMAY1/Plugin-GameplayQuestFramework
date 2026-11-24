// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "GameplayQuestTriggerVolume.generated.h"

class UBoxComponent;
class USphereComponent;
class UShapeComponent;

/**
 * Shape types supported by GameplayQuestTriggerVolume.
 */
UENUM(BlueprintType)
enum class EGameplayQuestTriggerShape : uint8
{
	Box,
	Sphere
};

/**
 * Placeable world trigger actor that notifies UGameplayQuestEventSubsystem upon actor overlap.
 *
 * Designed for reaching areas, exploration, zone transitions, and discovery objectives.
 * Zero-tick: Uses standard physics collision events (OnComponentBeginOverlap) instead of Tick.
 * Server-authoritative: Only processes overlaps on HasAuthority().
 */
UCLASS(Blueprintable, ClassGroup = (QuestFramework))
class GAMEPLAYQUESTFRAMEWORK_API AGameplayQuestTriggerVolume : public AActor
{
	GENERATED_BODY()

public:
	AGameplayQuestTriggerVolume(const FObjectInitializer& ObjectInitializer);

	/** Shape style: Box or Sphere collider. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Quest Trigger")
	EGameplayQuestTriggerShape TriggerShape = EGameplayQuestTriggerShape::Box;

	/** Primary event channel dispatched when triggered (Default: Quest.Event.AreaReached). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Trigger")
	FGameplayTag EventChannelTag;

	/** Specific area/location tag stamped onto the payload (e.g. Zone.Dungeon.BossRoom). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Trigger")
	FGameplayTag AreaTag;

	/** Optional required actor tag or gameplay tag to filter overlapping actors. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Trigger")
	FGameplayTag RequiredActorTag;

	/** If true, this trigger can only fire once per player/actor. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Trigger")
	bool bTriggerOncePerActor = true;

	/** If true, the trigger volume disables itself entirely after firing once. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest Trigger")
	bool bTriggerOnceTotal = false;

	/** Returns the active collision shape component. */
	UFUNCTION(BlueprintPure, Category = "Quest Trigger")
	UShapeComponent* GetCollisionShape() const;

	/** Manually trigger this volume with a specific overlapping actor. */
	UFUNCTION(BlueprintCallable, Category = "Quest Trigger")
	bool TriggerForActor(AActor* OverlappingActor);

	/** Resets trigger history so actors can trigger it again. */
	UFUNCTION(BlueprintCallable, Category = "Quest Trigger")
	void ResetTriggerState();

protected:
	virtual void PostInitializeComponents() override;

	UFUNCTION()
	virtual void OnOverlapBegin(
		UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);

	/** Set of actors that have already triggered this volume. */
	UPROPERTY(Transient)
	TSet<TWeakObjectPtr<AActor>> TriggeredActors;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Quest Trigger")
	TObjectPtr<UBoxComponent> BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Quest Trigger")
	TObjectPtr<USphereComponent> SphereComponent;

	UPROPERTY(Transient)
	bool bHasFiredTotal = false;
};
