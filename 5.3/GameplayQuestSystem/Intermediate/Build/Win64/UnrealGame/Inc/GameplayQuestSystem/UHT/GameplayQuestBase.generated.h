// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "GameplayQuestBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UGameplayQuestSubsystem;
#ifdef GAMEPLAYQUESTSYSTEM_GameplayQuestBase_generated_h
#error "GameplayQuestBase.generated.h already included, missing '#pragma once' in GameplayQuestBase.h"
#endif
#define GAMEPLAYQUESTSYSTEM_GameplayQuestBase_generated_h

#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_SPARSE_DATA
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetQuestSubsystem); \
	DECLARE_FUNCTION(execUpdateProgress); \
	DECLARE_FUNCTION(execResetQuest); \
	DECLARE_FUNCTION(execCompleteQuest); \
	DECLARE_FUNCTION(execStartQuest);


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_CALLBACK_WRAPPERS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameplayQuestBase(); \
	friend struct Z_Construct_UClass_UGameplayQuestBase_Statics; \
public: \
	DECLARE_CLASS(UGameplayQuestBase, UObject, COMPILED_IN_FLAGS(CLASS_Abstract), CASTCLASS_None, TEXT("/Script/GameplayQuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UGameplayQuestBase)


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameplayQuestBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameplayQuestBase(UGameplayQuestBase&&); \
	NO_API UGameplayQuestBase(const UGameplayQuestBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameplayQuestBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameplayQuestBase); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameplayQuestBase) \
	NO_API virtual ~UGameplayQuestBase();


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_23_PROLOG
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_SPARSE_DATA \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_CALLBACK_WRAPPERS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_INCLASS_NO_PURE_DECLS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_26_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<class UGameplayQuestBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
