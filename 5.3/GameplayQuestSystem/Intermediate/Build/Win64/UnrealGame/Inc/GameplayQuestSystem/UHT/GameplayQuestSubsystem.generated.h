// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameplayQuestSubsystem.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UGameplayQuestBase;
enum class EQuestState : uint8;
struct FGameplayTag;
struct FGameplayTag; class UGameplayQuestBase;
struct FQuestPayload;
#ifdef GAMEPLAYQUESTSYSTEM_GameplayQuestSubsystem_generated_h
#error "GameplayQuestSubsystem.generated.h already included, missing '#pragma once' in GameplayQuestSubsystem.h"
#endif
#define GAMEPLAYQUESTSYSTEM_GameplayQuestSubsystem_generated_h

#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_10_DELEGATE \
GAMEPLAYQUESTSYSTEM_API void FQuestEventBP_DelegateWrapper(const FMulticastScriptDelegate& QuestEventBP, EQuestState State, FQuestPayload const& Payload);


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_SPARSE_DATA
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIsQuestActive); \
	DECLARE_FUNCTION(execGetCompletedQuests); \
	DECLARE_FUNCTION(execGetActiveQuests); \
	DECLARE_FUNCTION(execResetQuest); \
	DECLARE_FUNCTION(execCompleteQuest);


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameplayQuestSubsystem(); \
	friend struct Z_Construct_UClass_UGameplayQuestSubsystem_Statics; \
public: \
	DECLARE_CLASS(UGameplayQuestSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayQuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UGameplayQuestSubsystem)


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameplayQuestSubsystem(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameplayQuestSubsystem(UGameplayQuestSubsystem&&); \
	NO_API UGameplayQuestSubsystem(const UGameplayQuestSubsystem&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameplayQuestSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameplayQuestSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGameplayQuestSubsystem) \
	NO_API virtual ~UGameplayQuestSubsystem();


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_22_PROLOG
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_SPARSE_DATA \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_INCLASS_NO_PURE_DECLS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_25_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<class UGameplayQuestSubsystem>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
