// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#if WITH_EDITOR
class FSlateStyleSet;
#endif

GAMEPLAYQUESTFRAMEWORK_API DECLARE_LOG_CATEGORY_EXTERN(LogGameplayQuest, Log, All);

class GAMEPLAYQUESTFRAMEWORK_API FGameplayQuestFrameworkModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

#if WITH_EDITOR
	/** Returns the Slate style set for quest editor icons and thumbnails. */
	static TSharedPtr<FSlateStyleSet> GetStyleSet();

private:
	static TSharedPtr<FSlateStyleSet> StyleSetInstance;
#endif
};
