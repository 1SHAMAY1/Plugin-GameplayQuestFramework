// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "QuestAsyncRegister.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class UGameplayQuestBase;
class UQuestAsyncRegister;
struct FGameplayTag;
#ifdef GAMEPLAYQUESTSYSTEM_QuestAsyncRegister_generated_h
#error "QuestAsyncRegister.generated.h already included, missing '#pragma once' in QuestAsyncRegister.h"
#endif
#define GAMEPLAYQUESTSYSTEM_QuestAsyncRegister_generated_h

#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_8_DELEGATE \
GAMEPLAYQUESTSYSTEM_API void FQuestAsyncRegister_DelegateWrapper(const FMulticastScriptDelegate& QuestAsyncRegister, UGameplayQuestBase* Quest, UQuestAsyncRegister* Task);


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_SPARSE_DATA
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRegisterQuest);


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_ACCESSORS
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuestAsyncRegister(); \
	friend struct Z_Construct_UClass_UQuestAsyncRegister_Statics; \
public: \
	DECLARE_CLASS(UQuestAsyncRegister, UQuestAsyncActionBase, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/GameplayQuestSystem"), NO_API) \
	DECLARE_SERIALIZER(UQuestAsyncRegister)


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestAsyncRegister(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UQuestAsyncRegister(UQuestAsyncRegister&&); \
	NO_API UQuestAsyncRegister(const UQuestAsyncRegister&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestAsyncRegister); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestAsyncRegister); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UQuestAsyncRegister) \
	NO_API virtual ~UQuestAsyncRegister();


#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_27_PROLOG
#define FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_SPARSE_DATA \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_ACCESSORS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_INCLASS_NO_PURE_DECLS \
	FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<class UQuestAsyncRegister>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
