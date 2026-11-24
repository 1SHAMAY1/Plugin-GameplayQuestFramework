// Copyright Epic Games, Inc. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "UObject/UObjectIterator.h"
#include "UObject/Class.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestGiverComponent.h"
#include "GameplayQuestEventSubsystem.h"
#include "GameplayQuestDataSubsystem.h"

#if WITH_DEV_AUTOMATION_TESTS

/**
 * Static architecture audit test to ensure the GameplayQuestFramework upholds the
 * Zero-Tick and Zero-NetMulticast non-negotiable architectural mandates.
 */
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FGameplayQuestArchitectureAuditTest,
	"GameplayQuest.Audit.Architecture.ZeroNetMulticastRPC",
	EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter
)

bool FGameplayQuestArchitectureAuditTest::RunTest(const FString& Parameters)
{
	int32 MulticastRpcCount = 0;
	TArray<FString> ViolatingFunctions;

	// Iterate over all UClasses belonging to the GameplayQuestFramework package
	const UPackage* FrameworkPackage = FindPackage(nullptr, TEXT("/Script/GameplayQuestFramework"));
	TestNotNull(TEXT("GameplayQuestFramework package must be loaded in memory"), FrameworkPackage);

	for (TObjectIterator<UClass> ClassIt; ClassIt; ++ClassIt)
	{
		UClass* CurrentClass = *ClassIt;
		if (CurrentClass->IsIn(FrameworkPackage))
		{
			// Check all functions in this class
			for (TFieldIterator<UFunction> FuncIt(CurrentClass, EFieldIterationFlags::None); FuncIt; ++FuncIt)
			{
				UFunction* Func = *FuncIt;
				if (Func->HasAnyFunctionFlags(FUNC_NetMulticast))
				{
					MulticastRpcCount++;
					ViolatingFunctions.Add(FString::Printf(TEXT("%s::%s"), *CurrentClass->GetName(), *Func->GetName()));
				}
			}
		}
	}

	for (const FString& Violation : ViolatingFunctions)
	{
		AddError(FString::Printf(TEXT("Architectural violation: Forbidden NetMulticast RPC detected in '%s'! Framework strictly mandates FFastArraySerializer + RepNotify."), *Violation));
	}

	TestEqual(TEXT("GameplayQuestFramework must have exactly 0 NetMulticast RPCs"), MulticastRpcCount, 0);

	// Also verify that UGameplayQuestManagerComponent and UGameplayQuestEventSubsystem do not tick
	UGameplayQuestManagerComponent* ManagerCDO = GetMutableDefault<UGameplayQuestManagerComponent>();
	TestNotNull(TEXT("Manager CDO must exist"), ManagerCDO);
	TestFalse(TEXT("UGameplayQuestManagerComponent PrimaryComponentTick.bCanEverTick must be FALSE"), ManagerCDO->PrimaryComponentTick.bCanEverTick);

	UGameplayQuestGiverComponent* GiverCDO = GetMutableDefault<UGameplayQuestGiverComponent>();
	TestNotNull(TEXT("Giver CDO must exist"), GiverCDO);
	TestFalse(TEXT("UGameplayQuestGiverComponent PrimaryComponentTick.bCanEverTick must be FALSE"), GiverCDO->PrimaryComponentTick.bCanEverTick);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
