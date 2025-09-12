// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "QuestTypes.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMEPLAYQUESTSYSTEM_QuestTypes_generated_h
#error "QuestTypes.generated.h already included, missing '#pragma once' in QuestTypes.h"
#endif
#define GAMEPLAYQUESTSYSTEM_QuestTypes_generated_h

#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FQuestPayload_Statics; \
	GAMEPLAYQUESTSYSTEM_API static class UScriptStruct* StaticStruct();


template<> GAMEPLAYQUESTSYSTEM_API UScriptStruct* StaticStruct<struct FQuestPayload>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h


#define FOREACH_ENUM_EQUESTSTATE(op) \
	op(EQuestState::None) \
	op(EQuestState::Started) \
	op(EQuestState::Completed) \
	op(EQuestState::Failed) \
	op(EQuestState::Abandoned) 

enum class EQuestState : uint8;
template<> struct TIsUEnumClass<EQuestState> { enum { Value = true }; };
template<> GAMEPLAYQUESTSYSTEM_API UEnum* StaticEnum<EQuestState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
