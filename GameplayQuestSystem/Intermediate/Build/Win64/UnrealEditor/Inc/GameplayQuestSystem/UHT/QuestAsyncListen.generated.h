// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "QuestAsyncListen.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UQuestAsyncListen;
enum class EQuestState : uint8;
struct FQuestPayload;
#ifdef GAMEPLAYQUESTSYSTEM_QuestAsyncListen_generated_h
#error "QuestAsyncListen.generated.h already included, missing '#pragma once' in QuestAsyncListen.h"
#endif
#define GAMEPLAYQUESTSYSTEM_QuestAsyncListen_generated_h

#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_7_DELEGATE \
GAMEPLAYQUESTSYSTEM_API void FQuestAsyncEvent_DelegateWrapper(const FMulticastScriptDelegate& QuestAsyncEvent, EQuestState State, FQuestPayload Payload, UQuestAsyncListen* Task);


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_SPARSE_DATA
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execHandleQuestEvent); \
	DECLARE_FUNCTION(execListenQuestEvents);


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuestAsyncListen(); \
	friend struct Z_Construct_UClass_UQuestAsyncListen_Statics; \
public: \
	DECLARE_CLASS(UQuestAsyncListen, UQuestAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayQuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestAsyncListen)


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestAsyncListen(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestAsyncListen(UQuestAsyncListen&&); \
	NO_API UQuestAsyncListen(const UQuestAsyncListen&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestAsyncListen); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestAsyncListen); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestAsyncListen) \
	NO_API virtual ~UQuestAsyncListen();


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_25_PROLOG
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_SPARSE_DATA \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_INCLASS_NO_PURE_DECLS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<class UQuestAsyncListen>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
