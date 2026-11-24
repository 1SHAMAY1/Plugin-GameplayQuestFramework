// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestModule.h"

#if WITH_EDITOR
#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Brushes/SlateImageBrush.h"
#include "Misc/Paths.h"

TSharedPtr<FSlateStyleSet> FGameplayQuestFrameworkModule::StyleSetInstance = nullptr;

TSharedPtr<FSlateStyleSet> FGameplayQuestFrameworkModule::GetStyleSet()
{
	return StyleSetInstance;
}
#endif

DEFINE_LOG_CATEGORY(LogGameplayQuest);

#define LOCTEXT_NAMESPACE "FGameplayQuestFrameworkModule"

void FGameplayQuestFrameworkModule::StartupModule()
{
#if WITH_EDITOR
	// Register custom Slate styles for quest framework component icons and asset thumbnails
	StyleSetInstance = MakeShared<FSlateStyleSet>("GameplayQuestFrameworkStyle");

	FString ResourcesDir = FPaths::ProjectPluginsDir() / TEXT("GameplayQuestFramework/Resources");
	if (!FPaths::DirectoryExists(ResourcesDir))
	{
		ResourcesDir = FPaths::EnginePluginsDir() / TEXT("Marketplace/GameplayQuestFramework/Resources");
	}
	if (!FPaths::DirectoryExists(ResourcesDir))
	{
		ResourcesDir = FPaths::EnginePluginsDir() / TEXT("GameplayQuestFramework/Resources");
	}

	if (FPaths::DirectoryExists(ResourcesDir))
	{
		StyleSetInstance->SetContentRoot(ResourcesDir);

		const FVector2D Icon16(16.0f, 16.0f);
		const FVector2D Icon64(64.0f, 64.0f);

		// 1. UGameplayQuestManagerComponent
		StyleSetInstance->Set("ClassIcon.GameplayQuestManagerComponent",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayQuestManagerComponent_16"), TEXT(".png")), Icon16));
		StyleSetInstance->Set("ClassThumbnail.GameplayQuestManagerComponent",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayQuestManagerComponent_64"), TEXT(".png")), Icon64));

		// 2. UGameplayQuestGiverComponent
		StyleSetInstance->Set("ClassIcon.GameplayQuestGiverComponent",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayQuestGiverComponent_16"), TEXT(".png")), Icon16));
		StyleSetInstance->Set("ClassThumbnail.GameplayQuestGiverComponent",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayQuestGiverComponent_64"), TEXT(".png")), Icon64));

		// 3. UGameplayQuestDefinition
		StyleSetInstance->Set("ClassIcon.GameplayQuestDefinition",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayQuestDefinition_16"), TEXT(".png")), Icon16));
		StyleSetInstance->Set("ClassThumbnail.GameplayQuestDefinition",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayQuestDefinition_64"), TEXT(".png")), Icon64));

		// 4. UGameplayObjectiveDefinition
		StyleSetInstance->Set("ClassIcon.GameplayObjectiveDefinition",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayObjectiveDefinition_16"), TEXT(".png")), Icon16));
		StyleSetInstance->Set("ClassThumbnail.GameplayObjectiveDefinition",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayObjectiveDefinition_64"), TEXT(".png")), Icon64));

		// 5. AGameplayQuestTriggerVolume
		StyleSetInstance->Set("ClassIcon.GameplayQuestTriggerVolume",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayQuestTriggerVolume_16"), TEXT(".png")), Icon16));
		StyleSetInstance->Set("ClassThumbnail.GameplayQuestTriggerVolume",
			new FSlateImageBrush(StyleSetInstance->RootToContentDir(TEXT("Icons/GameplayQuestTriggerVolume_64"), TEXT(".png")), Icon64));

		FSlateStyleRegistry::RegisterSlateStyle(*StyleSetInstance.Get());
	}
#endif

	UE_LOG(LogGameplayQuest, Log, TEXT("GameplayQuestFramework module started up successfully."));
}

void FGameplayQuestFrameworkModule::ShutdownModule()
{
#if WITH_EDITOR
	if (StyleSetInstance.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSetInstance.Get());
		StyleSetInstance.Reset();
	}
#endif

	UE_LOG(LogGameplayQuest, Log, TEXT("GameplayQuestFramework module shut down."));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameplayQuestFrameworkModule, GameplayQuestFramework)
