// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayQuestSystem/Public/QuestAsyncRegister.h"
#include "GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestAsyncRegister() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UGameplayQuestBase_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestAsyncActionBase();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestAsyncRegister();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestAsyncRegister_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UFunction* Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	UPackage* Z_Construct_UPackage__Script_GameplayQuestSystem();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics
	{
		struct _Script_GameplayQuestSystem_eventQuestAsyncRegister_Parms
		{
			UGameplayQuestBase* Quest;
			UQuestAsyncRegister* Task;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Quest_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Quest;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Task;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::NewProp_Quest_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::NewProp_Quest = { "Quest", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GameplayQuestSystem_eventQuestAsyncRegister_Parms, Quest), Z_Construct_UClass_UGameplayQuestBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::NewProp_Quest_MetaData), Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::NewProp_Quest_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::NewProp_Task = { "Task", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GameplayQuestSystem_eventQuestAsyncRegister_Parms, Task), Z_Construct_UClass_UQuestAsyncRegister_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::NewProp_Quest,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::NewProp_Task,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/QuestAsyncRegister.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GameplayQuestSystem, nullptr, "QuestAsyncRegister__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::_Script_GameplayQuestSystem_eventQuestAsyncRegister_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::_Script_GameplayQuestSystem_eventQuestAsyncRegister_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FQuestAsyncRegister_DelegateWrapper(const FMulticastScriptDelegate& QuestAsyncRegister, UGameplayQuestBase* Quest, UQuestAsyncRegister* Task)
{
	struct _Script_GameplayQuestSystem_eventQuestAsyncRegister_Parms
	{
		UGameplayQuestBase* Quest;
		UQuestAsyncRegister* Task;
	};
	_Script_GameplayQuestSystem_eventQuestAsyncRegister_Parms Parms;
	Parms.Quest=Quest;
	Parms.Task=Task;
	QuestAsyncRegister.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UQuestAsyncRegister::execRegisterQuest)
	{
		P_GET_STRUCT(FGameplayTag,Z_Param_QuestTag);
		P_GET_SOFTCLASS(TSoftClassPtr<UGameplayQuestBase> ,Z_Param_QuestClass);
		P_GET_OBJECT(AActor,Z_Param_Source);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UQuestAsyncRegister**)Z_Param__Result=UQuestAsyncRegister::RegisterQuest(Z_Param_QuestTag,Z_Param_QuestClass,Z_Param_Source);
		P_NATIVE_END;
	}
	void UQuestAsyncRegister::StaticRegisterNativesUQuestAsyncRegister()
	{
		UClass* Class = UQuestAsyncRegister::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "RegisterQuest", &UQuestAsyncRegister::execRegisterQuest },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics
	{
		struct QuestAsyncRegister_eventRegisterQuest_Parms
		{
			FGameplayTag QuestTag;
			TSoftClassPtr<UGameplayQuestBase>  QuestClass;
			AActor* Source;
			UQuestAsyncRegister* ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_QuestTag;
		static const UECodeGen_Private::FSoftClassPropertyParams NewProp_QuestClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Source;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::NewProp_QuestTag = { "QuestTag", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestAsyncRegister_eventRegisterQuest_Parms, QuestTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(0, nullptr) }; // 2083603574
	const UECodeGen_Private::FSoftClassPropertyParams Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::NewProp_QuestClass = { "QuestClass", nullptr, (EPropertyFlags)0x0014000000000080, UECodeGen_Private::EPropertyGenFlags::SoftClass, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestAsyncRegister_eventRegisterQuest_Parms, QuestClass), Z_Construct_UClass_UGameplayQuestBase_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestAsyncRegister_eventRegisterQuest_Parms, Source), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestAsyncRegister_eventRegisterQuest_Parms, ReturnValue), Z_Construct_UClass_UQuestAsyncRegister_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::NewProp_QuestTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::NewProp_QuestClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::NewProp_Source,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::Function_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "Category", "Quest|Async" },
		{ "Comment", "/**\n     * Starts an asynchronous quest registration task.\n     * @param QuestTag Tag identifying the quest to register.\n     * @param QuestClass Soft reference to the quest class to load and register.\n     * @param Source Optional actor associated with the quest registration.\n     * @return A UQuestAsyncRegister object representing the async task.\n     */" },
		{ "ModuleRelativePath", "Public/QuestAsyncRegister.h" },
		{ "ToolTip", "Starts an asynchronous quest registration task.\n@param QuestTag Tag identifying the quest to register.\n@param QuestClass Soft reference to the quest class to load and register.\n@param Source Optional actor associated with the quest registration.\n@return A UQuestAsyncRegister object representing the async task." },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestAsyncRegister, nullptr, "RegisterQuest", nullptr, nullptr, Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::PropPointers), sizeof(Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::QuestAsyncRegister_eventRegisterQuest_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::QuestAsyncRegister_eventRegisterQuest_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuestAsyncRegister);
	UClass* Z_Construct_UClass_UQuestAsyncRegister_NoRegister()
	{
		return UQuestAsyncRegister::StaticClass();
	}
	struct Z_Construct_UClass_UQuestAsyncRegister_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnRegisterSuccess_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRegisterSuccess;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnRegisterFail_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnRegisterFail;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Source_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Source;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestAsyncRegister_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UQuestAsyncActionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayQuestSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncRegister_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestAsyncRegister_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestAsyncRegister_RegisterQuest, "RegisterQuest" }, // 1787852436
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncRegister_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncRegister_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UQuestAsyncRegister\n *\n * Asynchronous Blueprint node for registering quests at runtime.\n * Allows Blueprints to register a quest by tag and class without blocking execution,\n * handling the asset loading asynchronously.\n *\n * Key Features:\n * - Supports asynchronous quest class loading via TSoftClassPtr.\n * - Fires `OnRegisterSuccess` when the quest is successfully registered.\n * - Fires `OnRegisterFail` if registration fails (invalid class or tag).\n * - Tracks the source actor for context during quest registration.\n *\n * Usage:\n * Call `RegisterQuest` in Blueprints to initiate quest registration.\n * Bind to `OnRegisterSuccess` or `OnRegisterFail` to handle the result asynchronously.\n */" },
		{ "IncludePath", "QuestAsyncRegister.h" },
		{ "ModuleRelativePath", "Public/QuestAsyncRegister.h" },
		{ "ToolTip", "UQuestAsyncRegister\n\nAsynchronous Blueprint node for registering quests at runtime.\nAllows Blueprints to register a quest by tag and class without blocking execution,\nhandling the asset loading asynchronously.\n\nKey Features:\n- Supports asynchronous quest class loading via TSoftClassPtr.\n- Fires `OnRegisterSuccess` when the quest is successfully registered.\n- Fires `OnRegisterFail` if registration fails (invalid class or tag).\n- Tracks the source actor for context during quest registration.\n\nUsage:\nCall `RegisterQuest` in Blueprints to initiate quest registration.\nBind to `OnRegisterSuccess` or `OnRegisterFail` to handle the result asynchronously." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterSuccess_MetaData[] = {
		{ "Comment", "/** Delegate called when the quest is successfully registered */" },
		{ "ModuleRelativePath", "Public/QuestAsyncRegister.h" },
		{ "ToolTip", "Delegate called when the quest is successfully registered" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterSuccess = { "OnRegisterSuccess", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestAsyncRegister, OnRegisterSuccess), Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterSuccess_MetaData), Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterSuccess_MetaData) }; // 2379758027
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterFail_MetaData[] = {
		{ "Comment", "/** Delegate called if quest registration fails */" },
		{ "ModuleRelativePath", "Public/QuestAsyncRegister.h" },
		{ "ToolTip", "Delegate called if quest registration fails" },
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterFail = { "OnRegisterFail", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestAsyncRegister, OnRegisterFail), Z_Construct_UDelegateFunction_GameplayQuestSystem_QuestAsyncRegister__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterFail_MetaData), Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterFail_MetaData) }; // 2379758027
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_Source_MetaData[] = {
		{ "Comment", "/** Optional actor associated with the quest registration */" },
		{ "ModuleRelativePath", "Public/QuestAsyncRegister.h" },
		{ "ToolTip", "Optional actor associated with the quest registration" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestAsyncRegister, Source), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_Source_MetaData), Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_Source_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestAsyncRegister_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterSuccess,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_OnRegisterFail,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestAsyncRegister_Statics::NewProp_Source,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestAsyncRegister_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestAsyncRegister>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuestAsyncRegister_Statics::ClassParams = {
		&UQuestAsyncRegister::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuestAsyncRegister_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncRegister_Statics::PropPointers),
		0,
		0x009000A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncRegister_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuestAsyncRegister_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncRegister_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UQuestAsyncRegister()
	{
		if (!Z_Registration_Info_UClass_UQuestAsyncRegister.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuestAsyncRegister.OuterSingleton, Z_Construct_UClass_UQuestAsyncRegister_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UQuestAsyncRegister.OuterSingleton;
	}
	template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<UQuestAsyncRegister>()
	{
		return UQuestAsyncRegister::StaticClass();
	}
	UQuestAsyncRegister::UQuestAsyncRegister(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestAsyncRegister);
	UQuestAsyncRegister::~UQuestAsyncRegister() {}
	struct Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UQuestAsyncRegister, UQuestAsyncRegister::StaticClass, TEXT("UQuestAsyncRegister"), &Z_Registration_Info_UClass_UQuestAsyncRegister, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuestAsyncRegister), 1118603418U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_1487835820(TEXT("/Script/GameplayQuestSystem"),
		Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncRegister_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
