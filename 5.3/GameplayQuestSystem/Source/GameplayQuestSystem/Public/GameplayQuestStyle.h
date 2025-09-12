#pragma once

#include "CoreMinimal.h"
#include "CoreMinimal.h"
#include "Styling/SlateStyle.h"        
#include "Styling/SlateStyleRegistry.h" 
#include "Brushes/SlateImageBrush.h"   
#include "Templates/SharedPointer.h" 
class FSlateStyleSet;

class FGameplayQuestSystemStyle
{
public:
	static void Initialize();
	static void Shutdown();

	static TSharedPtr<ISlateStyle> Get();
	static FName GetStyleSetName();

private:
	static TSharedPtr<FSlateStyleSet> StyleSet;
};
