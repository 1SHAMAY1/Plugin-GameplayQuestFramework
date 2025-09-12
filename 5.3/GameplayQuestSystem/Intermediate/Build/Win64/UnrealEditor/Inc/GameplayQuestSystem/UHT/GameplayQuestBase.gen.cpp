// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayQuestSystem/Public/GameplayQuestBase.h"
#include "GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameplayQuestBase() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UGameplayQuestBase();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UGameplayQuestBase_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UClass* Z_Construct_UClass_UGameplayQuestSubsystem_NoRegister();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	UPackage* Z_Construct_UPackage__Script_GameplayQuestSystem();
// End Cross Module References
	DEFINE_FUNCTION(UGameplayQuestBase::execGetQuestSubsystem)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(UGameplayQuestSubsystem**)Z_Param__Result=P_THIS->GetQuestSubsystem();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameplayQuestBase::execUpdateProgress)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_NewProgress);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateProgress(Z_Param_NewProgress);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameplayQuestBase::execResetQuest)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ResetQuest_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameplayQuestBase::execCompleteQuest)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CompleteQuest_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameplayQuestBase::execStartQuest)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->StartQuest_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_UGameplayQuestBase_CompleteQuest = FName(TEXT("CompleteQuest"));
	void UGameplayQuestBase::CompleteQuest()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameplayQuestBase_CompleteQuest),NULL);
	}
	static FName NAME_UGameplayQuestBase_ResetQuest = FName(TEXT("ResetQuest"));
	void UGameplayQuestBase::ResetQuest()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameplayQuestBase_ResetQuest),NULL);
	}
	static FName NAME_UGameplayQuestBase_StartQuest = FName(TEXT("StartQuest"));
	void UGameplayQuestBase::StartQuest()
	{
		ProcessEvent(FindFunctionChecked(NAME_UGameplayQuestBase_StartQuest),NULL);
	}
	void UGameplayQuestBase::StaticRegisterNativesUGameplayQuestBase()
	{
		UClass* Class = UGameplayQuestBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CompleteQuest", &UGameplayQuestBase::execCompleteQuest },
			{ "GetQuestSubsystem", &UGameplayQuestBase::execGetQuestSubsystem },
			{ "ResetQuest", &UGameplayQuestBase::execResetQuest },
			{ "StartQuest", &UGameplayQuestBase::execStartQuest },
			{ "UpdateProgress", &UGameplayQuestBase::execUpdateProgress },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameplayQuestBase_CompleteQuest_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestBase_CompleteQuest_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestBase_CompleteQuest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestBase, nullptr, "CompleteQuest", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestBase_CompleteQuest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestBase_CompleteQuest_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameplayQuestBase_CompleteQuest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestBase_CompleteQuest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics
	{
		struct GameplayQuestBase_eventGetQuestSubsystem_Parms
		{
			UGameplayQuestSubsystem* ReturnValue;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayQuestBase_eventGetQuestSubsystem_Parms, ReturnValue), Z_Construct_UClass_UGameplayQuestSubsystem_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest|Subsystem" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestBase, nullptr, "GetQuestSubsystem", nullptr, nullptr, Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::GameplayQuestBase_eventGetQuestSubsystem_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::GameplayQuestBase_eventGetQuestSubsystem_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameplayQuestBase_ResetQuest_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestBase_ResetQuest_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestBase_ResetQuest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestBase, nullptr, "ResetQuest", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestBase_ResetQuest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestBase_ResetQuest_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameplayQuestBase_ResetQuest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestBase_ResetQuest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameplayQuestBase_StartQuest_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestBase_StartQuest_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Native Events */" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
		{ "ToolTip", "Native Events" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestBase_StartQuest_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestBase, nullptr, "StartQuest", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020C00, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestBase_StartQuest_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestBase_StartQuest_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_UGameplayQuestBase_StartQuest()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestBase_StartQuest_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics
	{
		struct GameplayQuestBase_eventUpdateProgress_Parms
		{
			float NewProgress;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_NewProgress;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::NewProp_NewProgress = { "NewProgress", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(GameplayQuestBase_eventUpdateProgress_Parms, NewProgress), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::NewProp_NewProgress,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::Function_MetaDataParams[] = {
		{ "Category", "Quest|State" },
		{ "Comment", "/** Add to the quest progress (0.0 \xe2\x86\x92 1.0). If >= 1.0, automatically completes the quest */" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
		{ "ToolTip", "Add to the quest progress (0.0 \xe2\x86\x92 1.0). If >= 1.0, automatically completes the quest" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameplayQuestBase, nullptr, "UpdateProgress", nullptr, nullptr, Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::PropPointers), sizeof(Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::GameplayQuestBase_eventUpdateProgress_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020400, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::Function_MetaDataParams), Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::GameplayQuestBase_eventUpdateProgress_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UGameplayQuestBase);
	UClass* Z_Construct_UClass_UGameplayQuestBase_NoRegister()
	{
		return UGameplayQuestBase::StaticClass();
	}
	struct Z_Construct_UClass_UGameplayQuestBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_QuestTag_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_QuestTag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DescriptionRichText_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_DescriptionRichText;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RichTextStyleTable_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_RichTextStyleTable;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CancelQuestTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_CancelQuestTags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RestartQuestTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RestartQuestTags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RelatedQuestTags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_RelatedQuestTags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Source_MetaData[];
#endif
		static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Source;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CurrentProgress_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_CurrentProgress;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameplayQuestBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UObject,
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayQuestSystem,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameplayQuestBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameplayQuestBase_CompleteQuest, "CompleteQuest" }, // 804719895
		{ &Z_Construct_UFunction_UGameplayQuestBase_GetQuestSubsystem, "GetQuestSubsystem" }, // 4251707250
		{ &Z_Construct_UFunction_UGameplayQuestBase_ResetQuest, "ResetQuest" }, // 2409728405
		{ &Z_Construct_UFunction_UGameplayQuestBase_StartQuest, "StartQuest" }, // 1683912467
		{ &Z_Construct_UFunction_UGameplayQuestBase_UpdateProgress, "UpdateProgress" }, // 2500711072
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestBase_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "/**\n * UGameplayQuestBase\n * \n * Base class for all gameplay quests in the system. \n * Designed to be subclassed in Blueprint or C++, allowing flexible quest creation.\n * \n * Key Attributes:\n * - Abstract: Cannot be instantiated directly; intended as a base for derived quest types.\n * - Blueprintable: Can be extended and implemented in Blueprints.\n * - EditInlineNew: Allows creation and editing of instances directly within asset properties.\n * - DefaultToInstanced: Ensures default subobjects are instanced rather than shared references.\n */" },
		{ "IncludePath", "GameplayQuestBase.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
		{ "ToolTip", "UGameplayQuestBase\n\nBase class for all gameplay quests in the system.\nDesigned to be subclassed in Blueprint or C++, allowing flexible quest creation.\n\nKey Attributes:\n- Abstract: Cannot be instantiated directly; intended as a base for derived quest types.\n- Blueprintable: Can be extended and implemented in Blueprints.\n- EditInlineNew: Allows creation and editing of instances directly within asset properties.\n- DefaultToInstanced: Ensures default subobjects are instanced rather than shared references." },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_QuestTag_MetaData[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Core Quest Data (Editable in Class Defaults) */" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
		{ "ToolTip", "Core Quest Data (Editable in Class Defaults)" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_QuestTag = { "QuestTag", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestBase, QuestTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_QuestTag_MetaData), Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_QuestTag_MetaData) }; // 2083603574
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_DescriptionRichText_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_DescriptionRichText = { "DescriptionRichText", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestBase, DescriptionRichText), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_DescriptionRichText_MetaData), Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_DescriptionRichText_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RichTextStyleTable_MetaData[] = {
		{ "Category", "Quest" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RichTextStyleTable = { "RichTextStyleTable", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestBase, RichTextStyleTable), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RichTextStyleTable_MetaData), Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RichTextStyleTable_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CancelQuestTags_MetaData[] = {
		{ "Category", "Quest|Tags" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CancelQuestTags = { "CancelQuestTags", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestBase, CancelQuestTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CancelQuestTags_MetaData), Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CancelQuestTags_MetaData) }; // 405371792
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RestartQuestTags_MetaData[] = {
		{ "Category", "Quest|Tags" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RestartQuestTags = { "RestartQuestTags", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestBase, RestartQuestTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RestartQuestTags_MetaData), Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RestartQuestTags_MetaData) }; // 405371792
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RelatedQuestTags_MetaData[] = {
		{ "Category", "Quest|Tags" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RelatedQuestTags = { "RelatedQuestTags", nullptr, (EPropertyFlags)0x0010000000000015, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestBase, RelatedQuestTags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RelatedQuestTags_MetaData), Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RelatedQuestTags_MetaData) }; // 405371792
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_Source_MetaData[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Who triggered the quest (optional reference) */" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
		{ "ToolTip", "Who triggered the quest (optional reference)" },
	};
#endif
	const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0014000000000004, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestBase, Source), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_Source_MetaData), Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_Source_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CurrentProgress_MetaData[] = {
		{ "Category", "Quest|State" },
		{ "Comment", "/** Internal Progress (0.0 \xe2\x86\x92 1.0) */" },
		{ "ModuleRelativePath", "Public/GameplayQuestBase.h" },
		{ "ToolTip", "Internal Progress (0.0 \xe2\x86\x92 1.0)" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CurrentProgress = { "CurrentProgress", nullptr, (EPropertyFlags)0x0010000000000004, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UGameplayQuestBase, CurrentProgress), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CurrentProgress_MetaData), Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CurrentProgress_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameplayQuestBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_QuestTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_DescriptionRichText,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RichTextStyleTable,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CancelQuestTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RestartQuestTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_RelatedQuestTags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_Source,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameplayQuestBase_Statics::NewProp_CurrentProgress,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameplayQuestBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameplayQuestBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UGameplayQuestBase_Statics::ClassParams = {
		&UGameplayQuestBase::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGameplayQuestBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::PropPointers),
		0,
		0x003010A1u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::Class_MetaDataParams), Z_Construct_UClass_UGameplayQuestBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UGameplayQuestBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UGameplayQuestBase()
	{
		if (!Z_Registration_Info_UClass_UGameplayQuestBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UGameplayQuestBase.OuterSingleton, Z_Construct_UClass_UGameplayQuestBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UGameplayQuestBase.OuterSingleton;
	}
	template<> GAMEPLAYQUESTSYSTEM_API UClass* StaticClass<UGameplayQuestBase>()
	{
		return UGameplayQuestBase::StaticClass();
	}
	UGameplayQuestBase::UGameplayQuestBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameplayQuestBase);
	UGameplayQuestBase::~UGameplayQuestBase() {}
	struct Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UGameplayQuestBase, UGameplayQuestBase::StaticClass, TEXT("UGameplayQuestBase"), &Z_Registration_Info_UClass_UGameplayQuestBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UGameplayQuestBase), 72771066U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_2699080922(TEXT("/Script/GameplayQuestSystem"),
		Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_GameplayQuestBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
