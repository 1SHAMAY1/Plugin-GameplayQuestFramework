#include "GameplayQuestStyle.h"

#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleRegistry.h"

TSharedPtr<FSlateStyleSet> FGameplayQuestSystemStyle::StyleSet = nullptr;

void FGameplayQuestSystemStyle::Initialize()
{
	if (StyleSet.IsValid()) return;

	StyleSet = MakeShareable(new FSlateStyleSet(GetStyleSetName()));
	FString ContentDir = IPluginManager::Get().FindPlugin(TEXT("GameplayQuestSystem"))->GetBaseDir() / TEXT("Resources");
	StyleSet->SetContentRoot(ContentDir);

	const FVector2D Icon16(16.f, 16.f);
	const FVector2D Icon64(64.f, 64.f);

	StyleSet->Set("ClassIcon.GameplayQuestBase", new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("GameplayQuest_Icon_16x.png")), Icon16));
	StyleSet->Set("ClassThumbnail.GameplayQuestBase", new FSlateImageBrush(StyleSet->RootToContentDir(TEXT("GameplayQuest_Thumbnail_64x.png")), Icon64));

	FSlateStyleRegistry::RegisterSlateStyle(*StyleSet);
}

void FGameplayQuestSystemStyle::Shutdown()
{
	if (StyleSet.IsValid())
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*StyleSet);
		StyleSet.Reset();
	}
}

TSharedPtr<ISlateStyle> FGameplayQuestSystemStyle::Get()
{
	return StyleSet;
}

FName FGameplayQuestSystemStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("GameplayQuestSystemStyle"));
	return StyleSetName;
}
