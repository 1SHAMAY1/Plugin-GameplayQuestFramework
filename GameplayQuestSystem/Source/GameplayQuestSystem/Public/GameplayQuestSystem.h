#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

// Declare quest log category
DECLARE_LOG_CATEGORY_EXTERN(LogQuestSystem, Log, All);

// Global toggle for quest logging
extern bool GQuestDebugEnabled;

// Base macro (respects toggle)
#define QUEST_LOG(Verbosity, Format, ...) \
do { \
if (GQuestDebugEnabled) \
{ \
UE_LOG(LogQuestSystem, Verbosity, Format, ##__VA_ARGS__); \
} \
} while (0)

#define QUEST_LOG_STARTED(Format, ...)    QUEST_LOG(Warning, TEXT("[QUEST STARTED] ") Format, ##__VA_ARGS__)
#define QUEST_LOG_COMPLETED(Format, ...)  QUEST_LOG(Warning, TEXT("[QUEST COMPLETED] ") Format, ##__VA_ARGS__)
#define QUEST_LOG_FAILED(Format, ...)     QUEST_LOG(Error,   TEXT("[QUEST FAILED] ") Format, ##__VA_ARGS__)
#define QUEST_LOG_ABANDONED(Format, ...)  QUEST_LOG(Error,   TEXT("[QUEST ABANDONED] ") Format, ##__VA_ARGS__)
#define QUEST_LOG_GENERAL(Format, ...)    QUEST_LOG(Display, TEXT("[QUEST] ") Format, ##__VA_ARGS__)

class FGameplayQuestSystemModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

};
