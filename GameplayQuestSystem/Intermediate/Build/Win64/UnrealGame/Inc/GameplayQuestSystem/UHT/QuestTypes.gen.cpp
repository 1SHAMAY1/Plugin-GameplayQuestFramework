// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameplayQuestSystem/Public/QuestTypes.h"
#include "GameplayTagContainer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeQuestTypes() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	GAMEPLAYQUESTSYSTEM_API UEnum* Z_Construct_UEnum_GameplayQuestSystem_EQuestState();
	GAMEPLAYQUESTSYSTEM_API UScriptStruct* Z_Construct_UScriptStruct_FQuestPayload();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTag();
	GAMEPLAYTAGS_API UScriptStruct* Z_Construct_UScriptStruct_FGameplayTagContainer();
	UPackage* Z_Construct_UPackage__Script_GameplayQuestSystem();
// End Cross Module References
	static FEnumRegistrationInfo Z_Registration_Info_UEnum_EQuestState;
	static UEnum* EQuestState_StaticEnum()
	{
		if (!Z_Registration_Info_UEnum_EQuestState.OuterSingleton)
		{
			Z_Registration_Info_UEnum_EQuestState.OuterSingleton = GetStaticEnum(Z_Construct_UEnum_GameplayQuestSystem_EQuestState, (UObject*)Z_Construct_UPackage__Script_GameplayQuestSystem(), TEXT("EQuestState"));
		}
		return Z_Registration_Info_UEnum_EQuestState.OuterSingleton;
	}
	template<> GAMEPLAYQUESTSYSTEM_API UEnum* StaticEnum<EQuestState>()
	{
		return EQuestState_StaticEnum();
	}
	struct Z_Construct_UEnum_GameplayQuestSystem_EQuestState_Statics
	{
		static const UECodeGen_Private::FEnumeratorParam Enumerators[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[];
#endif
		static const UECodeGen_Private::FEnumParams EnumParams;
	};
	const UECodeGen_Private::FEnumeratorParam Z_Construct_UEnum_GameplayQuestSystem_EQuestState_Statics::Enumerators[] = {
		{ "EQuestState::None", (int64)EQuestState::None },
		{ "EQuestState::Started", (int64)EQuestState::Started },
		{ "EQuestState::Completed", (int64)EQuestState::Completed },
		{ "EQuestState::Failed", (int64)EQuestState::Failed },
		{ "EQuestState::Abandoned", (int64)EQuestState::Abandoned },
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UEnum_GameplayQuestSystem_EQuestState_Statics::Enum_MetaDataParams[] = {
		{ "Abandoned.DisplayName", "Abandoned" },
		{ "Abandoned.Name", "EQuestState::Abandoned" },
		{ "BlueprintType", "true" },
		{ "Completed.DisplayName", "Completed" },
		{ "Completed.Name", "EQuestState::Completed" },
		{ "Failed.DisplayName", "Failed" },
		{ "Failed.Name", "EQuestState::Failed" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
		{ "None.DisplayName", "None" },
		{ "None.Name", "EQuestState::None" },
		{ "Started.DisplayName", "Started" },
		{ "Started.Name", "EQuestState::Started" },
	};
#endif
	const UECodeGen_Private::FEnumParams Z_Construct_UEnum_GameplayQuestSystem_EQuestState_Statics::EnumParams = {
		(UObject*(*)())Z_Construct_UPackage__Script_GameplayQuestSystem,
		nullptr,
		"EQuestState",
		"EQuestState",
		Z_Construct_UEnum_GameplayQuestSystem_EQuestState_Statics::Enumerators,
		RF_Public|RF_Transient|RF_MarkAsNative,
		UE_ARRAY_COUNT(Z_Construct_UEnum_GameplayQuestSystem_EQuestState_Statics::Enumerators),
		EEnumFlags::None,
		(uint8)UEnum::ECppForm::EnumClass,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UEnum_GameplayQuestSystem_EQuestState_Statics::Enum_MetaDataParams), Z_Construct_UEnum_GameplayQuestSystem_EQuestState_Statics::Enum_MetaDataParams)
	};
	UEnum* Z_Construct_UEnum_GameplayQuestSystem_EQuestState()
	{
		if (!Z_Registration_Info_UEnum_EQuestState.InnerSingleton)
		{
			UECodeGen_Private::ConstructUEnum(Z_Registration_Info_UEnum_EQuestState.InnerSingleton, Z_Construct_UEnum_GameplayQuestSystem_EQuestState_Statics::EnumParams);
		}
		return Z_Registration_Info_UEnum_EQuestState.InnerSingleton;
	}
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_QuestPayload;
class UScriptStruct* FQuestPayload::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_QuestPayload.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_QuestPayload.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FQuestPayload, (UObject*)Z_Construct_UPackage__Script_GameplayQuestSystem(), TEXT("QuestPayload"));
	}
	return Z_Registration_Info_UScriptStruct_QuestPayload.OuterSingleton;
}
template<> GAMEPLAYQUESTSYSTEM_API UScriptStruct* StaticStruct<FQuestPayload>()
{
	return FQuestPayload::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FQuestPayload_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EventTag_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_EventTag;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_QuestMessage_MetaData[];
#endif
		static const UECodeGen_Private::FTextPropertyParams NewProp_QuestMessage;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Tags_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_Tags;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Magnitude_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Magnitude;
		static const UECodeGen_Private::FObjectPtrPropertyParams NewProp_AdditionalObjectReferences_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AdditionalObjectReferences_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_AdditionalObjectReferences;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Instigator_MetaData[];
#endif
		static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Instigator;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Source_MetaData[];
#endif
		static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Source;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Target_MetaData[];
#endif
		static const UECodeGen_Private::FWeakObjectPropertyParams NewProp_Target;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestPayload_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FQuestPayload_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FQuestPayload>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_EventTag_MetaData[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Tag for the related event */" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
		{ "ToolTip", "Tag for the related event" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_EventTag = { "EventTag", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestPayload, EventTag), Z_Construct_UScriptStruct_FGameplayTag, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_EventTag_MetaData), Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_EventTag_MetaData) }; // 2083603574
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_QuestMessage_MetaData[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** General message or description for the quest event */" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
		{ "ToolTip", "General message or description for the quest event" },
	};
#endif
	const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_QuestMessage = { "QuestMessage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestPayload, QuestMessage), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_QuestMessage_MetaData), Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_QuestMessage_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Tags_MetaData[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Tags for filtering and categorizing quest events */" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
		{ "ToolTip", "Tags for filtering and categorizing quest events" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Tags = { "Tags", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestPayload, Tags), Z_Construct_UScriptStruct_FGameplayTagContainer, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Tags_MetaData), Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Tags_MetaData) }; // 405371792
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Magnitude_MetaData[] = {
		{ "Category", "Quest" },
		{ "Comment", "/** Generic value (progress, score, damage amount, etc.) */" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
		{ "ToolTip", "Generic value (progress, score, damage amount, etc.)" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Magnitude = { "Magnitude", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestPayload, Magnitude), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Magnitude_MetaData), Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Magnitude_MetaData) };
	const UECodeGen_Private::FObjectPtrPropertyParams Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_AdditionalObjectReferences_Inner = { "AdditionalObjectReferences", nullptr, (EPropertyFlags)0x0004000000000000, UECodeGen_Private::EPropertyGenFlags::Object | UECodeGen_Private::EPropertyGenFlags::ObjectPtr, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_AdditionalObjectReferences_MetaData[] = {
		{ "Category", "Quest|References" },
		{ "Comment", "/** Any additional objects to carry with the quest event */" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
		{ "ToolTip", "Any additional objects to carry with the quest event" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_AdditionalObjectReferences = { "AdditionalObjectReferences", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestPayload, AdditionalObjectReferences), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_AdditionalObjectReferences_MetaData), Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_AdditionalObjectReferences_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Instigator_MetaData[] = {
		{ "Category", "Quest|Actors" },
		{ "Comment", "/** Actor who triggered the event (player, NPC, etc.) */" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
		{ "ToolTip", "Actor who triggered the event (player, NPC, etc.)" },
	};
#endif
	const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Instigator = { "Instigator", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestPayload, Instigator), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Instigator_MetaData), Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Instigator_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Source_MetaData[] = {
		{ "Category", "Quest|Actors" },
		{ "Comment", "/** The source of the quest event (item, system, actor, etc.) */" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
		{ "ToolTip", "The source of the quest event (item, system, actor, etc.)" },
	};
#endif
	const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Source = { "Source", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestPayload, Source), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Source_MetaData), Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Source_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Target_MetaData[] = {
		{ "Category", "Quest|Actors" },
		{ "Comment", "/** The target actor of the quest event */" },
		{ "ModuleRelativePath", "Public/QuestTypes.h" },
		{ "ToolTip", "The target actor of the quest event" },
	};
#endif
	const UECodeGen_Private::FWeakObjectPropertyParams Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Target = { "Target", nullptr, (EPropertyFlags)0x0014000000000005, UECodeGen_Private::EPropertyGenFlags::WeakObject, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestPayload, Target), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Target_MetaData), Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Target_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FQuestPayload_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_EventTag,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_QuestMessage,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Tags,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Magnitude,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_AdditionalObjectReferences_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_AdditionalObjectReferences,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Instigator,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Source,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestPayload_Statics::NewProp_Target,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FQuestPayload_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GameplayQuestSystem,
		nullptr,
		&NewStructOps,
		"QuestPayload",
		Z_Construct_UScriptStruct_FQuestPayload_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::PropPointers),
		sizeof(FQuestPayload),
		alignof(FQuestPayload),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FQuestPayload_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestPayload_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FQuestPayload()
	{
		if (!Z_Registration_Info_UScriptStruct_QuestPayload.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_QuestPayload.InnerSingleton, Z_Construct_UScriptStruct_FQuestPayload_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_QuestPayload.InnerSingleton;
	}
	struct Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h_Statics
	{
		static const FEnumRegisterCompiledInInfo EnumInfo[];
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
	};
	const FEnumRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h_Statics::EnumInfo[] = {
		{ EQuestState_StaticEnum, TEXT("EQuestState"), &Z_Registration_Info_UEnum_EQuestState, CONSTRUCT_RELOAD_VERSION_INFO(FEnumReloadVersionInfo, 3356138650U) },
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h_Statics::ScriptStructInfo[] = {
		{ FQuestPayload::StaticStruct, Z_Construct_UScriptStruct_FQuestPayload_Statics::NewStructOps, TEXT("QuestPayload"), &Z_Registration_Info_UScriptStruct_QuestPayload, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FQuestPayload), 2231514025U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h_2485086505(TEXT("/Script/GameplayQuestSystem"),
		nullptr, 0,
		Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h_Statics::ScriptStructInfo),
		Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h_Statics::EnumInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Plugin_Plugin_GameplayQuestSystem_GameplayQuestSystem_HostProject_Plugins_GameplayQuestSystem_Source_GameplayQuestSystem_Public_QuestTypes_h_Statics::EnumInfo));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
