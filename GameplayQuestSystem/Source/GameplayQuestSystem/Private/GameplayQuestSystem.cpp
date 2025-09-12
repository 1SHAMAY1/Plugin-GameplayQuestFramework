#include "GameplayQuestSystem.h"

#include "GameplayQuestStyle.h"

#define LOCTEXT_NAMESPACE "FGameplayQuestSystemModule"

// Define log category and global toggle
DEFINE_LOG_CATEGORY(LogQuestSystem);
bool GQuestDebugEnabled = true;

// Console command to toggle logging
static FAutoConsoleCommand ToggleQuestDebugCmd(
    TEXT("Quest.DebugToggle"),
    TEXT("Toggle Quest System Debug Logging"),
    FConsoleCommandDelegate::CreateLambda([]()
    {
        GQuestDebugEnabled = !GQuestDebugEnabled;
        if (GQuestDebugEnabled)
        {
            UE_LOG(LogQuestSystem, Display, TEXT("Quest Debug Logging ENABLED"));
        }
        else
        {
            UE_LOG(LogQuestSystem, Display, TEXT("Quest Debug Logging DISABLED"));
        }
    })
);

void FGameplayQuestSystemModule::StartupModule()
{
    FGameplayQuestSystemStyle::Initialize();
}

void FGameplayQuestSystemModule::ShutdownModule()
{
    FGameplayQuestSystemStyle::Shutdown();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FGameplayQuestSystemModule, GameplayQuestSystem)
