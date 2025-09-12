// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayQuestSystem/Public/GameplayQuestSubsystem.h"
#include "../../Source/Runtime/Engine/Classes/Engine/GameInstance.h"
#include "GameplayQuestSystem/Public/QuestTypes.h"
#include "GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameplayQuestSubsystem() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UGameplayQuestBase_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UGameplayQuestSubsystem();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UGameplayQuestSubsystem_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UEnum* Z_Construct_UEnum_GameplayQuestSystem_EQuestState();
	GAMEPLAYQUESTSYSTEM_API UFunction* Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature();
	GAMEPLAYQUESTSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FQuestPayload();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	UPackage* Z_Construct_UPackage__Script_GameplayQuestSystem();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics
	{
		struct _Script_GameplayQuestSystem_eventQuestEventBP_Parms
		{
			EQuestState State;
			FQuestPayload Payload;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Payload_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Payload;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GameplayQuestSystem_eventQuestEventBP_Parms, State), Z_Construct_UEnum_GameplayQuestSystem_EQuestState, METADATA_PARAMS(0, nullptr) }; // 3356138650
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::NewProp_Payload_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::NewProp_Payload = { "Payload", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GameplayQuestSystem_eventQuestEventBP_Parms, Payload), Z_Construct_UScriptStruct_FQuestPayload, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::NewProp_Payload_MetaData), Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::NewProp_Payload_MetaData) }; // 2231514025
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::NewProp_State_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::NewProp_State,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::NewProp_Payload,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GameplayQuestSystem, nullptr, "QuestEventBP__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::_Script_GameplayQuestSystem_eventQuestEventBP_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::_Script_GameplayQuestSystem_eventQuestEventBP_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FQuestEventBP_DelegateWrapper(const FMulticastScriptDelegate& QuestEventBP, EQuestState State, FQuestPayload const& Payload)
{
	struct _Script_GameplayQuestSystem_eventQuestEventBP_Parms
	{
		EQuestState State;
		FQuestPayload Payload;
	};
	_Script_GameplayQuestSystem_eventQuestEventBP_Parms Parms;
	Parms.State=State;
	Parms.Payload=Payload;
	QuestEventBP.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UGameplayQuestSubsystem::execIsQuestActive)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_QuestTag);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsQuestActive(Z_Param_QuestTag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameplayQuestSubsystem::execGetCompletedQuests)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TArray<UGameplayQuestBase*>*)Z_Param__Result=P_THIS->GetCompletedQuests();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameplayQuestSubsystem::execGetActiveQuests)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(TMap<FGameplayTag,UGameplayQuestBase*>*)Z_Param__Result=P_THIS->GetActiveQuests();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameplayQuestSubsystem::execResetQuest)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_QuestTag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetQuest(Z_Param_QuestTag);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameplayQuestSubsystem::execCompleteQuest)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_QuestTag);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CompleteQuest(Z_Param_QuestTag);
		P_NATIVE_END;
	}
	void UGameplayQuestSubsystem::StaticRegisterNativesUGameplayQuestSubsystem()
	{
		UClass* Class = UGameplayQuestSubsystem::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CompleteQuest", &UGameplayQuestSubsystem::execCompleteQuest },
			{ "GetActiveQuests", &UGameplayQuestSubsystem::execGetActiveQuests },
			{ "GetCompletedQuests", &UGameplayQuestSubsystem::execGetCompletedQuests },
			{ "IsQuestActive", &UGameplayQuestSubsystem::execIsQuestActive },
			{ "ResetQuest", &UGameplayQuestSubsystem::execResetQuest },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics
	{
		struct GameplayQuestSubsystem_eventCompleteQuest_Parms
		{
			FGameplayTag QuestTag;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_QuestTag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::NewProp_QuestTag = { "QuestTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayQuestSubsystem_eventCompleteQuest_Parms, QuestTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 2083603574
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::NewProp_QuestTag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Complete a quest by GameplayTag */" },
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
		{ "ToolTip", "Complete a quest by GameplayTag" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestSubsystem, nullptr, "CompleteQuest", nullptr, nullptr, Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::GameplayQuestSubsystem_eventCompleteQuest_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::GameplayQuestSubsystem_eventCompleteQuest_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics
	{
		struct GameplayQuestSubsystem_eventGetActiveQuests_Parms
		{
			TMap<FGameplayTag,UGameplayQuestBase*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_ValueProp;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::NewProp_ReturnValue_ValueProp = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UGameplayQuestBase_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::NewProp_ReturnValue_Key_KeyProp = { "ReturnValue_Key", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 2083603574
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x001000800800058a, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayQuestSubsystem_eventGetActiveQuests_Parms, ReturnValue), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::NewProp_ReturnValue_MetaData) }; // 2083603574
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::NewProp_ReturnValue_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::NewProp_ReturnValue_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Get all active quests */" },
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
		{ "ToolTip", "Get all active quests" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestSubsystem, nullptr, "GetActiveQuests", nullptr, nullptr, Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::GameplayQuestSubsystem_eventGetActiveQuests_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::GameplayQuestSubsystem_eventGetActiveQuests_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics
	{
		struct GameplayQuestSubsystem_eventGetCompletedQuests_Parms
		{
			TArray<UGameplayQuestBase*> ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UGameplayQuestBase_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::NewProp_ReturnValue_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x001000800800058a, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayQuestSubsystem_eventGetCompletedQuests_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::NewProp_ReturnValue_MetaData), Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::NewProp_ReturnValue_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::NewProp_ReturnValue_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Get all completed quests */" },
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
		{ "ToolTip", "Get all completed quests" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestSubsystem, nullptr, "GetCompletedQuests", nullptr, nullptr, Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::GameplayQuestSubsystem_eventGetCompletedQuests_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::GameplayQuestSubsystem_eventGetCompletedQuests_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics
	{
		struct GameplayQuestSubsystem_eventIsQuestActive_Parms
		{
			FGameplayTag QuestTag;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_QuestTag;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::NewProp_QuestTag = { "QuestTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayQuestSubsystem_eventIsQuestActive_Parms, QuestTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 2083603574
	void Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((GameplayQuestSubsystem_eventIsQuestActive_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(GameplayQuestSubsystem_eventIsQuestActive_Parms), &Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::NewProp_QuestTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Check if a quest with a specific tag is currently active */" },
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
		{ "ToolTip", "Check if a quest with a specific tag is currently active" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestSubsystem, nullptr, "IsQuestActive", nullptr, nullptr, Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::GameplayQuestSubsystem_eventIsQuestActive_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::GameplayQuestSubsystem_eventIsQuestActive_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics
	{
		struct GameplayQuestSubsystem_eventResetQuest_Parms
		{
			FGameplayTag QuestTag;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_QuestTag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::NewProp_QuestTag = { "QuestTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayQuestSubsystem_eventResetQuest_Parms, QuestTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 2083603574
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::NewProp_QuestTag,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Reset a quest by GameplayTag */" },
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
		{ "ToolTip", "Reset a quest by GameplayTag" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestSubsystem, nullptr, "ResetQuest", nullptr, nullptr, Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::GameplayQuestSubsystem_eventResetQuest_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::GameplayQuestSubsystem_eventResetQuest_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGameplayQuestSubsystem);
	UClass* Z_Construct_UClass_UGameplayQuestSubsystem_NoRegister()
	{
		return UGameplayQuestSubsystem::StaticClass();
	}
	struct Z_Construct_UClass_UGameplayQuestSubsystem_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnQuestEventBP_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnQuestEventBP;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ActiveQuests_ValueProp;
		static const UECodeGen_Private::FStructPropertyParams NewProp_ActiveQuests_Key_KeyProp;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ActiveQuests_MetaData[];
#endif
		static const UECodeGen_Private::FMapPropertyParams NewProp_ActiveQuests;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CompletedQuests_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CompletedQuests_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_CompletedQuests;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameplayQuestSubsystem_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayQuestSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestSubsystem_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameplayQuestSubsystem_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameplayQuestSubsystem_CompleteQuest, "CompleteQuest" }, // 742863577
		{ &Z_Construct_UFunction_UGameplayQuestSubsystem_GetActiveQuests, "GetActiveQuests" }, // 1705821117
		{ &Z_Construct_UFunction_UGameplayQuestSubsystem_GetCompletedQuests, "GetCompletedQuests" }, // 2062323778
		{ &Z_Construct_UFunction_UGameplayQuestSubsystem_IsQuestActive, "IsQuestActive" }, // 3543114135
		{ &Z_Construct_UFunction_UGameplayQuestSubsystem_ResetQuest, "ResetQuest" }, // 1039713444
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestSubsystem_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestSubsystem_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UGameplayQuestSubsystem\n *\n * Subsystem responsible for managing all active quests within the game instance.\n * Handles quest registration, tracking, and lifecycle events, providing a centralized \n * interface for gameplay systems to interact with quests.\n *\n * Inherits from UGameInstanceSubsystem, ensuring a single instance per game session \n * and automatic initialization with the game instance.\n */" },
		{ "IncludePath", "GameplayQuestSubsystem.h" },
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
		{ "ToolTip", "UGameplayQuestSubsystem\n\nSubsystem responsible for managing all active quests within the game instance.\nHandles quest registration, tracking, and lifecycle events, providing a centralized\ninterface for gameplay systems to interact with quests.\n\nInherits from UGameInstanceSubsystem, ensuring a single instance per game session\nand automatic initialization with the game instance." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_OnQuestEventBP_MetaData[] = {
		{ "Category", "Quest|Events" },
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_OnQuestEventBP = { "OnQuestEventBP", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestSubsystem, OnQuestEventBP), Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestEventBP__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_OnQuestEventBP_MetaData), Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_OnQuestEventBP_MetaData) }; // 294813397
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_ActiveQuests_ValueProp = { "ActiveQuests", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, Z_Construct_UClass_UGameplayQuestBase_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_ActiveQuests_Key_KeyProp = { "ActiveQuests_Key", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 2083603574
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_ActiveQuests_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FMapPropertyParams Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_ActiveQuests = { "ActiveQuests", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestSubsystem, ActiveQuests), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_ActiveQuests_MetaData), Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_ActiveQuests_MetaData) }; // 2083603574
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_CompletedQuests_Inner = { "CompletedQuests", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UGameplayQuestBase_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_CompletedQuests_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/GameplayQuestSubsystem.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_CompletedQuests = { "CompletedQuests", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestSubsystem, CompletedQuests), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_CompletedQuests_MetaData), Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_CompletedQuests_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameplayQuestSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_OnQuestEventBP,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_ActiveQuests_ValueProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_ActiveQuests_Key_KeyProp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_ActiveQuests,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_CompletedQuests_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestSubsystem_Statics::NewProp_CompletedQuests,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameplayQuestSubsystem_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameplayQuestSubsystem>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameplayQuestSubsystem_Statics::ClassParams = {
		&UGameplayQuestSubsystem::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGameplayQuestSubsystem_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestSubsystem_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UGameplayQuestSubsystem_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestSubsystem_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UGameplayQuestSubsystem()
	{
		if (!Z_Registration_Info_UClass_UGameplayQuestSubsystem.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameplayQuestSubsystem.OuterSingleton, Z_Construct_UClass_UGameplayQuestSubsystem_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGameplayQuestSubsystem.OuterSingleton;
	}
	template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<UGameplayQuestSubsystem>()
	{
		return UGameplayQuestSubsystem::StaticClass();
	}
	UGameplayQuestSubsystem::UGameplayQuestSubsystem() {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameplayQuestSubsystem);
	UGameplayQuestSubsystem::~UGameplayQuestSubsystem() {}
	struct Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGameplayQuestSubsystem, UGameplayQuestSubsystem::StaticClass, TEXT("UGameplayQuestSubsystem"), &Z_Registration_Info_UClass_UGameplayQuestSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameplayQuestSubsystem), 3207153954U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_1226426736(TEXT("/Script/GameplayQuestSystem"),
		Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestSubsystem_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
