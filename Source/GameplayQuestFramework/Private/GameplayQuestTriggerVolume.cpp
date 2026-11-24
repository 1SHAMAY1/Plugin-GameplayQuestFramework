// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestTriggerVolume.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "GameplayQuestEventSubsystem.h"
#include "GameplayQuestFunctionLibrary.h"
#include "GameplayQuestTags.h"
#include "GameplayQuestModule.h"
#include "Engine/World.h"

AGameplayQuestTriggerVolume::AGameplayQuestTriggerVolume(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	bReplicates = false; // Server-authoritative logic, can be evaluated purely on server

	EventChannelTag = GameplayQuestTags::TAG_Quest_Event_ReachArea.GetTag();
	AreaTag = GameplayQuestTags::TAG_Zone_Default.GetTag();

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxComponent->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxComponent->SetCollisionProfileName(UCollisionProfile::BlockAll_ProfileName);
	BoxComponent->SetGenerateOverlapEvents(true);
	RootComponent = BoxComponent;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	SphereComponent->InitSphereRadius(100.0f);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SphereComponent->SetGenerateOverlapEvents(false);
	SphereComponent->SetupAttachment(RootComponent);
}

void AGameplayQuestTriggerVolume::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UShapeComponent* ActiveShape = GetCollisionShape();
	if (ActiveShape)
	{
		ActiveShape->OnComponentBeginOverlap.AddDynamic(this, &AGameplayQuestTriggerVolume::OnOverlapBegin);
	}
}

UShapeComponent* AGameplayQuestTriggerVolume::GetCollisionShape() const
{
	return (TriggerShape == EGameplayQuestTriggerShape::Sphere) ? Cast<UShapeComponent>(SphereComponent) : Cast<UShapeComponent>(BoxComponent);
}

void AGameplayQuestTriggerVolume::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	TriggerForActor(OtherActor);
}

bool AGameplayQuestTriggerVolume::TriggerForActor(AActor* OverlappingActor)
{
	if (!OverlappingActor || bHasFiredTotal)
	{
		return false;
	}

	// Server-authoritative check: only trigger where authority resides
	if (!HasAuthority())
	{
		return false;
	}

	// Filter already triggered actors if bTriggerOncePerActor
	if (bTriggerOncePerActor && TriggeredActors.Contains(OverlappingActor))
	{
		return false;
	}

	// Optional Tag filtering
	if (RequiredActorTag.IsValid() && !OverlappingActor->ActorHasTag(RequiredActorTag.GetTagName()))
	{
		return false;
	}

	TriggeredActors.Add(OverlappingActor);
	if (bTriggerOnceTotal)
	{
		bHasFiredTotal = true;
	}

	// Broadcast via World Event Subsystem or Function Library
	UWorld* World = GetWorld();
	if (!World)
	{
		return false;
	}

	UGameplayQuestFunctionLibrary::BroadcastAreaReachedEvent(
		World,
		OverlappingActor,
		AreaTag.IsValid() ? AreaTag : EventChannelTag
	);

	UE_LOG(LogGameplayQuest, Verbose, TEXT("GameplayQuestTriggerVolume %s triggered by %s for AreaTag: %s"),
		*GetName(), *OverlappingActor->GetName(), *AreaTag.ToString());

	return true;
}

void AGameplayQuestTriggerVolume::ResetTriggerState()
{
	TriggeredActors.Empty();
	bHasFiredTotal = false;
}
