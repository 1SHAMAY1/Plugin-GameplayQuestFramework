// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestTags.h"

namespace GameplayQuestTags
{
	// ------------------------------------------------------------------------
	// Quest Lifecycle Status Tags
	// ------------------------------------------------------------------------
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Status_NotStarted, "Quest.Status.NotStarted");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Status_Active, "Quest.Status.Active");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Status_Active_InProgress, "Quest.Status.Active.InProgress");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Status_Active_ReadyToTurnIn, "Quest.Status.Active.ReadyToTurnIn");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Status_Completed, "Quest.Status.Completed");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Status_Failed, "Quest.Status.Failed");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Status_Failed_Timeout, "Quest.Status.Failed.Timeout");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Status_Failed_ConditionFailed, "Quest.Status.Failed.ConditionFailed");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Status_Abandoned, "Quest.Status.Abandoned");

	// ------------------------------------------------------------------------
	// Objective Status Tags
	// ------------------------------------------------------------------------
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Objective_Status_Inactive, "Quest.Objective.Status.Inactive");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Objective_Status_Active, "Quest.Objective.Status.Active");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Objective_Status_Completed, "Quest.Objective.Status.Completed");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Objective_Status_Failed, "Quest.Objective.Status.Failed");

	// ------------------------------------------------------------------------
	// Multiplayer & Co-Op Sharing Policy Tags
	// ------------------------------------------------------------------------
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Policy_Sharing_SoloOnly, "Quest.Policy.Sharing.SoloOnly");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Policy_Sharing_PartyUniform, "Quest.Policy.Sharing.PartyUniform");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Policy_Sharing_PartyProximity, "Quest.Policy.Sharing.PartyProximity");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Policy_Sharing_WorldShared, "Quest.Policy.Sharing.WorldShared");

	// ------------------------------------------------------------------------
	// Progression Flow Tags
	// ------------------------------------------------------------------------
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Progression_Sequential, "Quest.Progression.Sequential");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Progression_Concurrent, "Quest.Progression.Concurrent");

	// ------------------------------------------------------------------------
	// Event Channel Tags (Zero-Tick Inverted Tag Dispatching)
	// ------------------------------------------------------------------------
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Event_Kill, "Quest.Event.Kill");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Event_Collect, "Quest.Event.Collect");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Event_Interact, "Quest.Event.Interact");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Event_ReachArea, "Quest.Event.ReachArea");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Event_Timer, "Quest.Event.Timer");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Event_Custom, "Quest.Event.Custom");

	// ------------------------------------------------------------------------
	// World / Zone Scoping Tags
	// ------------------------------------------------------------------------
	UE_DEFINE_GAMEPLAY_TAG(TAG_Zone_Default, "Zone.Default");

	// ------------------------------------------------------------------------
	// Quest Giver Visual Marker & Interaction States
	// ------------------------------------------------------------------------
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Giver_None, "Quest.Giver.State.None");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Giver_Available, "Quest.Giver.State.Available");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Giver_InProgress, "Quest.Giver.State.InProgress");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Giver_ReadyToTurnIn, "Quest.Giver.State.ReadyToTurnIn");

	// ------------------------------------------------------------------------
	// Test & Dynamic Category Tags
	// ------------------------------------------------------------------------
	UE_DEFINE_GAMEPLAY_TAG(TAG_Target_Enemy_Goblin, "Target.Enemy.Goblin");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Target_Enemy_Orc, "Target.Enemy.Orc");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Quest_Relic, "Item.Quest.Relic");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Item_Consumable_Potion, "Item.Consumable.Potion");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Zone_Dungeon_Depths, "Zone.Dungeon.Depths");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Zone_City_Hub, "Zone.City.Hub");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Objective_SampleA, "Quest.Objective.SampleA");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Objective_SampleB, "Quest.Objective.SampleB");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Quest_Prereq_Completed, "Quest.Prereq.Completed");
	UE_DEFINE_GAMEPLAY_TAG(TAG_Player_Level_10Plus, "Player.Level.10Plus");
}
