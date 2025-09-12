#include "QuestSystemBlueprintFunctionLibrary.h"

#include "Engine/Engine.h"                
#include "Engine/World.h"                  
#include "Engine/GameInstance.h"          
#include "GameplayQuestSubsystem.h"

void UQuestSystemBlueprintFunctionLibrary::SendQuestEvent(EQuestState State,
                                                          const FQuestPayload& Payload)
{
	for (const FWorldContext& Context : GEngine->GetWorldContexts())
	{
		if (Context.WorldType == EWorldType::Game || Context.WorldType == EWorldType::PIE)
		{
			if (UWorld* World = Context.World())
			{
				if (UGameInstance* GI = World->GetGameInstance())
				{
					if (UGameplayQuestSubsystem* Subsystem = GI->GetSubsystem<UGameplayQuestSubsystem>())
					{
						Subsystem->HandleQuestEvent(State, Payload);
						return;
					}
				}
			}
		}
	}
}
