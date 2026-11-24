// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NativeGameplayTags.h"

namespace GameplayQuestTags
{
	// ------------------------------------------------------------------------
	// Quest Lifecycle Status Tags
	// ------------------------------------------------------------------------
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Status_NotStarted);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Status_Active);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Status_Active_InProgress);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Status_Active_ReadyToTurnIn);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Status_Completed);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Status_Failed);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Status_Failed_Timeout);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Status_Failed_ConditionFailed);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Status_Abandoned);

	// ------------------------------------------------------------------------
	// Objective Status Tags
	// ------------------------------------------------------------------------
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Objective_Status_Inactive);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Objective_Status_Active);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Objective_Status_Completed);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Objective_Status_Failed);

	// ------------------------------------------------------------------------
	// Multiplayer & Co-Op Sharing Policy Tags
	// ------------------------------------------------------------------------
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Policy_Sharing_SoloOnly);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Policy_Sharing_PartyUniform);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Policy_Sharing_PartyProximity);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Policy_Sharing_WorldShared);

	// ------------------------------------------------------------------------
	// Progression Flow Tags
	// ------------------------------------------------------------------------
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Progression_Sequential);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Progression_Concurrent);

	// ------------------------------------------------------------------------
	// Event Channel Tags (Zero-Tick Inverted Tag Dispatching)
	// ------------------------------------------------------------------------
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Event_Kill);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Event_Collect);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Event_Interact);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Event_ReachArea);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Event_Timer);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Event_Custom);

	// ------------------------------------------------------------------------
	// World / Zone Scoping Tags
	// ------------------------------------------------------------------------
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Zone_Default);

	// ------------------------------------------------------------------------
	// Quest Giver Visual Marker & Interaction States
	// ------------------------------------------------------------------------
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Giver_None);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Giver_Available);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Giver_InProgress);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Giver_ReadyToTurnIn);
	// ------------------------------------------------------------------------
	// Test & Dynamic Category Tags
	// ------------------------------------------------------------------------
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Target_Enemy_Goblin);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Target_Enemy_Orc);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Quest_Relic);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Item_Consumable_Potion);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Zone_Dungeon_Depths);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Zone_City_Hub);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Objective_SampleA);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Objective_SampleB);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Quest_Prereq_Completed);
	GAMEPLAYQUESTFRAMEWORK_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(TAG_Player_Level_10Plus);
}
