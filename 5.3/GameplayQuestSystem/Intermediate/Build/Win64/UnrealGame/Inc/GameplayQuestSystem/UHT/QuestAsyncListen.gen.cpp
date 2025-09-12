// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayQuestSystem/Public/QuestAsyncListen.h"
#include "GameplayQuestSystem/Public/QuestTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestAsyncListen() {}
// Cross Module References
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestAsyncActionBase();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestAsyncListen();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestAsyncListen_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UEnum* Z_Construct_UEnum_GameplayQuestSystem_EQuestState();
	GAMEPLAYQUESTSYSTEM_API UFunction* Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature();
	GAMEPLAYQUESTSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FQuestPayload();
	UPackage* Z_Construct_UPackage__Script_GameplayQuestSystem();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics
	{
		struct _Script_GameplayQuestSystem_eventQuestAsyncEvent_Parms
		{
			EQuestState State;
			FQuestPayload Payload;
			UQuestAsyncListen* Task;
		};
		static const UECodeGen_Private::FBytePropertyParams NewProp_State_Underlying;
		static const UECodeGen_Private::FEnumPropertyParams NewProp_State;
		static const UECodeGen_Private::FStructPropertyParams NewProp_Payload;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Task;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GameplayQuestSystem_eventQuestAsyncEvent_Parms, State), Z_Construct_UEnum_GameplayQuestSystem_EQuestState, METADATA_PARAMS(0, nullptr) }; // 3356138650
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::NewProp_Payload = { "Payload", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GameplayQuestSystem_eventQuestAsyncEvent_Parms, Payload), Z_Construct_UScriptStruct_FQuestPayload, METADATA_PARAMS(0, nullptr) }; // 2231514025
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::NewProp_Task = { "Task", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GameplayQuestSystem_eventQuestAsyncEvent_Parms, Task), Z_Construct_UClass_UQuestAsyncListen_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::NewProp_State_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::NewProp_State,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::NewProp_Payload,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::NewProp_Task,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/QuestAsyncListen.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GameplayQuestSystem, nullptr, "QuestAsyncEvent__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::_Script_GameplayQuestSystem_eventQuestAsyncEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::_Script_GameplayQuestSystem_eventQuestAsyncEvent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FQuestAsyncEvent_DelegateWrapper(const FMulticastScriptDelegate& QuestAsyncEvent, EQuestState State, FQuestPayload Payload, UQuestAsyncListen* Task)
{
	struct _Script_GameplayQuestSystem_eventQuestAsyncEvent_Parms
	{
		EQuestState State;
		FQuestPayload Payload;
		UQuestAsyncListen* Task;
	};
	_Script_GameplayQuestSystem_eventQuestAsyncEvent_Parms Parms;
	Parms.State=State;
	Parms.Payload=Payload;
	Parms.Task=Task;
	QuestAsyncEvent.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UQuestAsyncListen::execHandleQuestEvent)
	{
		P_GET_ENUM(EQuestState,Z_Param_State);
		P_GET_STRUCT_REF(FQuestPayload,Z_Param_Out_Payload);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HandleQuestEvent(EQuestState(Z_Param_State),Z_Param_Out_Payload);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UQuestAsyncListen::execListenQuestEvents)
	{
		P_GET_UBOOL(Z_Param_bAutoEndTaskOnFailed);
		P_GET_UBOOL(Z_Param_bAutoEndTaskOnCompleted);
		P_GET_UBOOL(Z_Param_bAutoEndTaskOnAbandoned);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UQuestAsyncListen**)Z_Param__Result=UQuestAsyncListen::ListenQuestEvents(Z_Param_bAutoEndTaskOnFailed,Z_Param_bAutoEndTaskOnCompleted,Z_Param_bAutoEndTaskOnAbandoned);
		P_NATIVE_END;
	}
	void UQuestAsyncListen::StaticRegisterNativesUQuestAsyncListen()
	{
		UClass* Class = UQuestAsyncListen::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "HandleQuestEvent", &UQuestAsyncListen::execHandleQuestEvent },
			{ "ListenQuestEvents", &UQuestAsyncListen::execListenQuestEvents },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics
	{
		struct QuestAsyncListen_eventHandleQuestEvent_Parms
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
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestAsyncListen_eventHandleQuestEvent_Parms, State), Z_Construct_UEnum_GameplayQuestSystem_EQuestState, METADATA_PARAMS(0, nullptr) }; // 3356138650
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::NewProp_Payload_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::NewProp_Payload = { "Payload", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestAsyncListen_eventHandleQuestEvent_Parms, Payload), Z_Construct_UScriptStruct_FQuestPayload, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::NewProp_Payload_MetaData), Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::NewProp_Payload_MetaData) }; // 2231514025
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::NewProp_State_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::NewProp_State,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::NewProp_Payload,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/** Internal handler for quest events */" },
		{ "ModuleRelativePath", "Public/QuestAsyncListen.h" },
		{ "ToolTip", "Internal handler for quest events" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestAsyncListen, nullptr, "HandleQuestEvent", nullptr, nullptr, Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::QuestAsyncListen_eventHandleQuestEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::QuestAsyncListen_eventHandleQuestEvent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics
	{
		struct QuestAsyncListen_eventListenQuestEvents_Parms
		{
			bool bAutoEndTaskOnFailed;
			bool bAutoEndTaskOnCompleted;
			bool bAutoEndTaskOnAbandoned;
			UQuestAsyncListen* ReturnValue;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoEndTaskOnFailed_MetaData[];
#endif
		static void NewProp_bAutoEndTaskOnFailed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoEndTaskOnFailed;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoEndTaskOnCompleted_MetaData[];
#endif
		static void NewProp_bAutoEndTaskOnCompleted_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoEndTaskOnCompleted;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoEndTaskOnAbandoned_MetaData[];
#endif
		static void NewProp_bAutoEndTaskOnAbandoned_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoEndTaskOnAbandoned;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnFailed_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnFailed_SetBit(void* Obj)
	{
		((QuestAsyncListen_eventListenQuestEvents_Parms*)Obj)->bAutoEndTaskOnFailed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnFailed = { "bAutoEndTaskOnFailed", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(QuestAsyncListen_eventListenQuestEvents_Parms), &Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnFailed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnFailed_MetaData), Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnFailed_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnCompleted_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnCompleted_SetBit(void* Obj)
	{
		((QuestAsyncListen_eventListenQuestEvents_Parms*)Obj)->bAutoEndTaskOnCompleted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnCompleted = { "bAutoEndTaskOnCompleted", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(QuestAsyncListen_eventListenQuestEvents_Parms), &Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnCompleted_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnCompleted_MetaData), Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnCompleted_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnAbandoned_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	void Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnAbandoned_SetBit(void* Obj)
	{
		((QuestAsyncListen_eventListenQuestEvents_Parms*)Obj)->bAutoEndTaskOnAbandoned = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnAbandoned = { "bAutoEndTaskOnAbandoned", nullptr, (EPropertyFlags)0x0010000000000082, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(QuestAsyncListen_eventListenQuestEvents_Parms), &Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnAbandoned_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnAbandoned_MetaData), Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnAbandoned_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestAsyncListen_eventListenQuestEvents_Parms, ReturnValue), Z_Construct_UClass_UQuestAsyncListen_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnFailed,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnCompleted,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_bAutoEndTaskOnAbandoned,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Quest|Async" },
		{ "Comment", "/** \n     * Starts listening to quest events asynchronously.\n     * @param bAutoEndTaskOnFailed Automatically completes the task if the quest fails.\n     * @param bAutoEndTaskOnCompleted Automatically completes the task if the quest is completed.\n     * @param bAutoEndTaskOnAbandoned Automatically completes the task if the quest is abandoned.\n     */" },
		{ "CPP_Default_bAutoEndTaskOnAbandoned", "false" },
		{ "CPP_Default_bAutoEndTaskOnCompleted", "true" },
		{ "CPP_Default_bAutoEndTaskOnFailed", "false" },
		{ "ModuleRelativePath", "Public/QuestAsyncListen.h" },
		{ "ToolTip", "Starts listening to quest events asynchronously.\n@param bAutoEndTaskOnFailed Automatically completes the task if the quest fails.\n@param bAutoEndTaskOnCompleted Automatically completes the task if the quest is completed.\n@param bAutoEndTaskOnAbandoned Automatically completes the task if the quest is abandoned." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestAsyncListen, nullptr, "ListenQuestEvents", nullptr, nullptr, Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::PropPointers), sizeof(Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::QuestAsyncListen_eventListenQuestEvents_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::QuestAsyncListen_eventListenQuestEvents_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuestAsyncListen);
	UClass* Z_Construct_UClass_UQuestAsyncListen_NoRegister()
	{
		return UQuestAsyncListen::StaticClass();
	}
	struct Z_Construct_UClass_UQuestAsyncListen_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnEventReceived_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnEventReceived;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoEndTaskOnAbandoned_MetaData[];
#endif
		static void NewProp_bAutoEndTaskOnAbandoned_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoEndTaskOnAbandoned;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoEndTaskOnCompleted_MetaData[];
#endif
		static void NewProp_bAutoEndTaskOnCompleted_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoEndTaskOnCompleted;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAutoEndTaskOnFailed_MetaData[];
#endif
		static void NewProp_bAutoEndTaskOnFailed_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAutoEndTaskOnFailed;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestAsyncListen_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UQuestAsyncActionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayQuestSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncListen_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestAsyncListen_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestAsyncListen_HandleQuestEvent, "HandleQuestEvent" }, // 4170756014
		{ &Z_Construct_UFunction_UQuestAsyncListen_ListenQuestEvents, "ListenQuestEvents" }, // 1987741024
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncListen_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncListen_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UQuestAsyncListen\n *\n * Asynchronous Blueprint node for listening to quest events.\n * Allows Blueprints to respond to quest state changes (e.g., Completed, Failed, Abandoned)\n * without blocking execution. Provides automatic task completion based on event type.\n *\n * Key Features:\n * - Can automatically end the async task when a quest is Completed, Failed, or Abandoned.\n * - Exposes a BlueprintAssignable event (`OnEventReceived`) for BP binding.\n * - Supports multiple event types via `FQuestAsyncEvent` delegate.\n *\n * Usage:\n * Call `ListenQuestEvents` in Blueprints to start listening to quest events.\n * Bind to `OnEventReceived` to handle quest updates asynchronously.\n */" },
		{ "IncludePath", "QuestAsyncListen.h" },
		{ "ModuleRelativePath", "Public/QuestAsyncListen.h" },
		{ "ToolTip", "UQuestAsyncListen\n\nAsynchronous Blueprint node for listening to quest events.\nAllows Blueprints to respond to quest state changes (e.g., Completed, Failed, Abandoned)\nwithout blocking execution. Provides automatic task completion based on event type.\n\nKey Features:\n- Can automatically end the async task when a quest is Completed, Failed, or Abandoned.\n- Exposes a BlueprintAssignable event (`OnEventReceived`) for BP binding.\n- Supports multiple event types via `FQuestAsyncEvent` delegate.\n\nUsage:\nCall `ListenQuestEvents` in Blueprints to start listening to quest events.\nBind to `OnEventReceived` to handle quest updates asynchronously." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_OnEventReceived_MetaData[] = {
		{ "Comment", "/** Event that Blueprint can bind to for quest state updates */" },
		{ "ModuleRelativePath", "Public/QuestAsyncListen.h" },
		{ "ToolTip", "Event that Blueprint can bind to for quest state updates" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_OnEventReceived = { "OnEventReceived", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestAsyncListen, OnEventReceived), Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncEvent__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_OnEventReceived_MetaData), Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_OnEventReceived_MetaData) }; // 116686427
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnAbandoned_MetaData[] = {
		{ "Comment", "/** Flags to control automatic task completion based on quest state */" },
		{ "ModuleRelativePath", "Public/QuestAsyncListen.h" },
		{ "ToolTip", "Flags to control automatic task completion based on quest state" },
	};
#endif
	void Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnAbandoned_SetBit(void* Obj)
	{
		((UQuestAsyncListen*)Obj)->bAutoEndTaskOnAbandoned = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnAbandoned = { "bAutoEndTaskOnAbandoned", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UQuestAsyncListen), &Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnAbandoned_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnAbandoned_MetaData), Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnAbandoned_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnCompleted_MetaData[] = {
		{ "ModuleRelativePath", "Public/QuestAsyncListen.h" },
	};
#endif
	void Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnCompleted_SetBit(void* Obj)
	{
		((UQuestAsyncListen*)Obj)->bAutoEndTaskOnCompleted = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnCompleted = { "bAutoEndTaskOnCompleted", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UQuestAsyncListen), &Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnCompleted_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnCompleted_MetaData), Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnCompleted_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnFailed_MetaData[] = {
		{ "ModuleRelativePath", "Public/QuestAsyncListen.h" },
	};
#endif
	void Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnFailed_SetBit(void* Obj)
	{
		((UQuestAsyncListen*)Obj)->bAutoEndTaskOnFailed = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnFailed = { "bAutoEndTaskOnFailed", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UQuestAsyncListen), &Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnFailed_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnFailed_MetaData), Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnFailed_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestAsyncListen_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_OnEventReceived,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnAbandoned,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnCompleted,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestAsyncListen_Statics::NewProp_bAutoEndTaskOnFailed,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestAsyncListen_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestAsyncListen>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuestAsyncListen_Statics::ClassParams = {
		&UQuestAsyncListen::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuestAsyncListen_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncListen_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncListen_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuestAsyncListen_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncListen_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UQuestAsyncListen()
	{
		if (!Z_Registration_Info_UClass_UQuestAsyncListen.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuestAsyncListen.OuterSingleton, Z_Construct_UClass_UQuestAsyncListen_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UQuestAsyncListen.OuterSingleton;
	}
	template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<UQuestAsyncListen>()
	{
		return UQuestAsyncListen::StaticClass();
	}
	UQuestAsyncListen::UQuestAsyncListen(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestAsyncListen);
	UQuestAsyncListen::~UQuestAsyncListen() {}
	struct Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UQuestAsyncListen, UQuestAsyncListen::StaticClass, TEXT("UQuestAsyncListen"), &Z_Registration_Info_UClass_UQuestAsyncListen, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuestAsyncListen), 201116874U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_4125579268(TEXT("/Script/GameplayQuestSystem"),
		Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncListen_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
