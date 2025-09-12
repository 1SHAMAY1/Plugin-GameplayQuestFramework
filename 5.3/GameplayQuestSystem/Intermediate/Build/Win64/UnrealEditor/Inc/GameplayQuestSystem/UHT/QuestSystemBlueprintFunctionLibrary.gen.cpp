// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayQuestSystem/Public/QuestSystemBlueprintFunctionLibrary.h"
#include "GameplayQuestSystem/Public/QuestTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestSystemBlueprintFunctionLibrary() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UEnum* Z_Construct_UEnum_GameplayQuestSystem_EQuestState();
	GAMEPLAYQUESTSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FQuestPayload();
	UPackage* Z_Construct_UPackage__Script_GameplayQuestSystem();
// End Cross Module References
	DEFINE_FUNCTION(UQuestSystemBlueprintFunctionLibrary::execSendQuestEvent)
	{
		P_GET_ENUM(EQuestState,Z_Param_State);
		P_GET_STRUCT_REF(FQuestPayload,Z_Param_Out_Payload);
		P_FINISH;
		P_NATIVE_BEGIN;
		UQuestSystemBlueprintFunctionLibrary::SendQuestEvent(EQuestState(Z_Param_State),Z_Param_Out_Payload);
		P_NATIVE_END;
	}
	void UQuestSystemBlueprintFunctionLibrary::StaticRegisterNativesUQuestSystemBlueprintFunctionLibrary()
	{
		UClass* Class = UQuestSystemBlueprintFunctionLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SendQuestEvent", &UQuestSystemBlueprintFunctionLibrary::execSendQuestEvent },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics
	{
		struct QuestSystemBlueprintFunctionLibrary_eventSendQuestEvent_Parms
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
	const UECodeGen_Private::FBytePropertyParams Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::NewProp_State_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, nullptr, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FEnumPropertyParams Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestSystemBlueprintFunctionLibrary_eventSendQuestEvent_Parms, State), Z_Construct_UEnum_GameplayQuestSystem_EQuestState, METADATA_PARAMS(0, nullptr) }; // 3356138650
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::NewProp_Payload_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::NewProp_Payload = { "Payload", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestSystemBlueprintFunctionLibrary_eventSendQuestEvent_Parms, Payload), Z_Construct_UScriptStruct_FQuestPayload, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::NewProp_Payload_MetaData), Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::NewProp_Payload_MetaData) }; // 2231514025
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::NewProp_State_Underlying,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::NewProp_State,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::NewProp_Payload,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest System" },
		{ "Comment", "/**\n\x09 * Sends a quest event safely, usable from both C++ and Blueprints.\n\x09 * @param State The quest state to send (e.g., Completed, Failed, Abandoned).\n\x09 * @param Payload The payload containing quest-specific data.\n\x09 */" },
		{ "ModuleRelativePath", "Public/QuestSystemBlueprintFunctionLibrary.h" },
		{ "ToolTip", "Sends a quest event safely, usable from both C++ and Blueprints.\n@param State The quest state to send (e.g., Completed, Failed, Abandoned).\n@param Payload The payload containing quest-specific data." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary, nullptr, "SendQuestEvent", nullptr, nullptr, Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::PropPointers), sizeof(Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::QuestSystemBlueprintFunctionLibrary_eventSendQuestEvent_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04422401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::QuestSystemBlueprintFunctionLibrary_eventSendQuestEvent_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuestSystemBlueprintFunctionLibrary);
	UClass* Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_NoRegister()
	{
		return UQuestSystemBlueprintFunctionLibrary::StaticClass();
	}
	struct Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayQuestSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestSystemBlueprintFunctionLibrary_SendQuestEvent, "SendQuestEvent" }, // 2154282798
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UQuestSystemBlueprintFunctionLibrary\n *\n * A Blueprint Function Library providing utility functions for the Gameplay Quest System.\n * Exposes core quest functionality to Blueprints and C++ in a safe and reusable way.\n *\n * Key Features:\n * - Allows sending quest events from both Blueprints and C++.\n * - Provides a central, static interface for interacting with quest-related functionality\n *   without needing direct references to the Quest Subsystem.\n */" },
		{ "IncludePath", "QuestSystemBlueprintFunctionLibrary.h" },
		{ "ModuleRelativePath", "Public/QuestSystemBlueprintFunctionLibrary.h" },
		{ "ToolTip", "UQuestSystemBlueprintFunctionLibrary\n\nA Blueprint Function Library providing utility functions for the Gameplay Quest System.\nExposes core quest functionality to Blueprints and C++ in a safe and reusable way.\n\nKey Features:\n- Allows sending quest events from both Blueprints and C++.\n- Provides a central, static interface for interacting with quest-related functionality\n  without needing direct references to the Quest Subsystem." },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestSystemBlueprintFunctionLibrary>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::ClassParams = {
		&UQuestSystemBlueprintFunctionLibrary::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x001000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary()
	{
		if (!Z_Registration_Info_UClass_UQuestSystemBlueprintFunctionLibrary.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuestSystemBlueprintFunctionLibrary.OuterSingleton, Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UQuestSystemBlueprintFunctionLibrary.OuterSingleton;
	}
	template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<UQuestSystemBlueprintFunctionLibrary>()
	{
		return UQuestSystemBlueprintFunctionLibrary::StaticClass();
	}
	UQuestSystemBlueprintFunctionLibrary::UQuestSystemBlueprintFunctionLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestSystemBlueprintFunctionLibrary);
	UQuestSystemBlueprintFunctionLibrary::~UQuestSystemBlueprintFunctionLibrary() {}
	struct Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestSystemBlueprintFunctionLibrary_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestSystemBlueprintFunctionLibrary_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UQuestSystemBlueprintFunctionLibrary, UQuestSystemBlueprintFunctionLibrary::StaticClass, TEXT("UQuestSystemBlueprintFunctionLibrary"), &Z_Registration_Info_UClass_UQuestSystemBlueprintFunctionLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuestSystemBlueprintFunctionLibrary), 3532311317U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestSystemBlueprintFunctionLibrary_h_919850923(TEXT("/Script/GameplayQuestSystem"),
		Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestSystemBlueprintFunctionLibrary_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestSystemBlueprintFunctionLibrary_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
