// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayQuestSystem/Public/QuestAsyncActionBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestAsyncActionBase() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintAsyncActionBase();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestAsyncActionBase();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UQuestAsyncActionBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameplayQuestSystem();
// End Cross Module References
	DEFINE_FUNCTION(UQuestAsyncActionBase::execEndTask)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->EndTask();
		P_NATIVE_END;
	}
	void UQuestAsyncActionBase::StaticRegisterNativesUQuestAsyncActionBase()
	{
		UClass* Class = UQuestAsyncActionBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "EndTask", &UQuestAsyncActionBase::execEndTask },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UQuestAsyncActionBase_EndTask_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UQuestAsyncActionBase_EndTask_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest|Async" },
		{ "Comment", "/** Manually destroy this async task (exposed to BP) */" },
		{ "ModuleRelativePath", "Public/QuestAsyncActionBase.h" },
		{ "ToolTip", "Manually destroy this async task (exposed to BP)" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestAsyncActionBase_EndTask_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UQuestAsyncActionBase, nullptr, "EndTask", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestAsyncActionBase_EndTask_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuestAsyncActionBase_EndTask_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UQuestAsyncActionBase_EndTask()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuestAsyncActionBase_EndTask_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UQuestAsyncActionBase);
	UClass* Z_Construct_UClass_UQuestAsyncActionBase_NoRegister()
	{
		return UQuestAsyncActionBase::StaticClass();
	}
	struct Z_Construct_UClass_UQuestAsyncActionBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_WorldContext_MetaData[];
#endif
		static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_WorldContext;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UQuestAsyncActionBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UBlueprintAsyncActionBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayQuestSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncActionBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UQuestAsyncActionBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestAsyncActionBase_EndTask, "EndTask" }, // 4254198058
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncActionBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncActionBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * UQuestAsyncActionBase\n *\n * Abstract base class for asynchronous quest actions in the gameplay quest system.\n * Designed to be extended in Blueprints or C++ to implement async operations\n * such as quest registration, completion, or event-driven quest updates.\n *\n * Inherits from UBlueprintAsyncActionBase, allowing usage with Blueprint\n * nodes that support latent/asynchronous execution.\n *\n * Key Attributes:\n * - Abstract: Cannot be instantiated directly; must be subclassed for specific async actions.\n */" },
		{ "IncludePath", "QuestAsyncActionBase.h" },
		{ "ModuleRelativePath", "Public/QuestAsyncActionBase.h" },
		{ "ToolTip", "UQuestAsyncActionBase\n\nAbstract base class for asynchronous quest actions in the gameplay quest system.\nDesigned to be extended in Blueprints or C++ to implement async operations\nsuch as quest registration, completion, or event-driven quest updates.\n\nInherits from UBlueprintAsyncActionBase, allowing usage with Blueprint\nnodes that support latent/asynchronous execution.\n\nKey Attributes:\n- Abstract: Cannot be instantiated directly; must be subclassed for specific async actions." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UQuestAsyncActionBase_Statics::NewProp_WorldContext_MetaData[] = {
		{ "Comment", "/** Stored context */" },
		{ "ModuleRelativePath", "Public/QuestAsyncActionBase.h" },
		{ "ToolTip", "Stored context" },
	};
#endif
	const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UQuestAsyncActionBase_Statics::NewProp_WorldContext = { "WorldContext", nullptr, (EPropertyFlags)0x0024080000000000, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestAsyncActionBase, WorldContext), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncActionBase_Statics::NewProp_WorldContext_MetaData), Z_Construct_UClass_UQuestAsyncActionBase_Statics::NewProp_WorldContext_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestAsyncActionBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestAsyncActionBase_Statics::NewProp_WorldContext,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UQuestAsyncActionBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestAsyncActionBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuestAsyncActionBase_Statics::ClassParams = {
		&UQuestAsyncActionBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UQuestAsyncActionBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncActionBase_Statics::PropPointers),
		0,
		0x001000A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncActionBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuestAsyncActionBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestAsyncActionBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UQuestAsyncActionBase()
	{
		if (!Z_Registration_Info_UClass_UQuestAsyncActionBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuestAsyncActionBase.OuterSingleton, Z_Construct_UClass_UQuestAsyncActionBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UQuestAsyncActionBase.OuterSingleton;
	}
	template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<UQuestAsyncActionBase>()
	{
		return UQuestAsyncActionBase::StaticClass();
	}
	UQuestAsyncActionBase::UQuestAsyncActionBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UQuestAsyncActionBase);
	UQuestAsyncActionBase::~UQuestAsyncActionBase() {}
	struct Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncActionBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncActionBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UQuestAsyncActionBase, UQuestAsyncActionBase::StaticClass, TEXT("UQuestAsyncActionBase"), &Z_Registration_Info_UClass_UQuestAsyncActionBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuestAsyncActionBase), 506383195U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncActionBase_h_3636193935(TEXT("/Script/GameplayQuestSystem"),
		Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncActionBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestAsyncActionBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
