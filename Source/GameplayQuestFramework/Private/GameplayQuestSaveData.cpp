// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestSaveData.h"
#include "GameplayQuestSettings.h"
#include "GameplayQuestModule.h"
#include "Serialization/MemoryWriter.h"
#include "Serialization/MemoryReader.h"
#include "JsonObjectConverter.h"

FGameplayQuestSaveData::FGameplayQuestSaveData()
{
	if (const UGameplayQuestSettings* Settings = UGameplayQuestSettings::Get())
	{
		SchemaVersion = Settings->SaveSchemaVersion;
	}
	else
	{
		SchemaVersion = 1;
	}
}

void FGameplayQuestSaveData::ExportToBinary(TArray<uint8>& OutBytes) const
{
	OutBytes.Reset();
	FMemoryWriter MemoryWriter(OutBytes, true);

	// 1. Header: SchemaVersion & CharacterGuid
	int32 WrittenSchema = SchemaVersion;
	MemoryWriter << WrittenSchema;

	FGuid GuidCopy = CharacterGuid;
	MemoryWriter << GuidCopy;

	// 2. Active Quests
	int32 ActiveCount = ActiveQuests.Num();
	MemoryWriter << ActiveCount;

	for (const FGameplayQuestSaveRecord& QuestRec : ActiveQuests)
	{
		FString QuestTagStr = QuestRec.QuestTag.ToString();
		FString StatusTagStr = QuestRec.StatusTag.ToString();
		int32 StageIdx = QuestRec.CurrentStageIndex;

		MemoryWriter << QuestTagStr;
		MemoryWriter << StatusTagStr;
		MemoryWriter << StageIdx;

		int32 ObjCount = QuestRec.Objectives.Num();
		MemoryWriter << ObjCount;

		for (const FGameplayObjectiveSaveRecord& ObjRec : QuestRec.Objectives)
		{
			FString ObjTagStr = ObjRec.ObjectiveTag.ToString();
			FString ObjStatusStr = ObjRec.StatusTag.ToString();
			int32 CurProg = ObjRec.CurrentProgress;
			int32 ReqCount = ObjRec.RequiredCount;

			MemoryWriter << ObjTagStr;
			MemoryWriter << ObjStatusStr;
			MemoryWriter << CurProg;
			MemoryWriter << ReqCount;
		}
	}

	// 3. Completed Quests
	int32 CompletedNum = CompletedQuests.Num();
	MemoryWriter << CompletedNum;
	for (auto It = CompletedQuests.CreateConstIterator(); It; ++It)
	{
		FString TagStr = It->ToString();
		MemoryWriter << TagStr;
	}

	// 4. Failed Quests
	int32 FailedNum = FailedQuests.Num();
	MemoryWriter << FailedNum;
	for (auto It = FailedQuests.CreateConstIterator(); It; ++It)
	{
		FString TagStr = It->ToString();
		MemoryWriter << TagStr;
	}
}

bool FGameplayQuestSaveData::ImportFromBinary(const TArray<uint8>& InBytes)
{
	if (InBytes.Num() == 0)
	{
		return false;
	}

	FMemoryReader MemoryReader(InBytes, true);

	// 1. Header
	int32 ReadSchema = 0;
	MemoryReader << ReadSchema;

	// Migration check
	const UGameplayQuestSettings* Settings = UGameplayQuestSettings::Get();
	const int32 ExpectedSchema = Settings ? Settings->SaveSchemaVersion : 1;
	if (ReadSchema > ExpectedSchema)
	{
		UE_LOG(LogGameplayQuest, Error, TEXT("ImportFromBinary failed: Save schema version %d exceeds engine version %d"),
			ReadSchema, ExpectedSchema);
		return false;
	}
	SchemaVersion = ReadSchema;

	MemoryReader << CharacterGuid;

	// 2. Active Quests
	int32 ActiveCount = 0;
	MemoryReader << ActiveCount;
	ActiveQuests.Empty(ActiveCount);

	for (int32 i = 0; i < ActiveCount; ++i)
	{
		FString QuestTagStr;
		FString StatusTagStr;
		int32 StageIdx = 0;

		MemoryReader << QuestTagStr;
		MemoryReader << StatusTagStr;
		MemoryReader << StageIdx;

		FGameplayQuestSaveRecord QuestRec;
		QuestRec.QuestTag = FGameplayTag::RequestGameplayTag(FName(*QuestTagStr), false);
		QuestRec.StatusTag = FGameplayTag::RequestGameplayTag(FName(*StatusTagStr), false);
		QuestRec.CurrentStageIndex = StageIdx;

		int32 ObjCount = 0;
		MemoryReader << ObjCount;
		QuestRec.Objectives.Empty(ObjCount);

		for (int32 j = 0; j < ObjCount; ++j)
		{
			FString ObjTagStr;
			FString ObjStatusStr;
			int32 CurProg = 0;
			int32 ReqCount = 1;

			MemoryReader << ObjTagStr;
			MemoryReader << ObjStatusStr;
			MemoryReader << CurProg;
			MemoryReader << ReqCount;

			FGameplayObjectiveSaveRecord ObjRec;
			ObjRec.ObjectiveTag = FGameplayTag::RequestGameplayTag(FName(*ObjTagStr), false);
			ObjRec.StatusTag = FGameplayTag::RequestGameplayTag(FName(*ObjStatusStr), false);
			ObjRec.CurrentProgress = CurProg;
			ObjRec.RequiredCount = ReqCount;

			QuestRec.Objectives.Add(ObjRec);
		}

		ActiveQuests.Add(QuestRec);
	}

	// 3. Completed Quests
	int32 CompletedNum = 0;
	MemoryReader << CompletedNum;
	CompletedQuests.Reset();
	for (int32 i = 0; i < CompletedNum; ++i)
	{
		FString TagStr;
		MemoryReader << TagStr;
		CompletedQuests.AddTag(FGameplayTag::RequestGameplayTag(FName(*TagStr), false));
	}

	// 4. Failed Quests
	int32 FailedNum = 0;
	MemoryReader << FailedNum;
	FailedQuests.Reset();
	for (int32 i = 0; i < FailedNum; ++i)
	{
		FString TagStr;
		MemoryReader << TagStr;
		FailedQuests.AddTag(FGameplayTag::RequestGameplayTag(FName(*TagStr), false));
	}

	return true;
}

bool FGameplayQuestSaveData::ExportToJson(FString& OutJsonString) const
{
	return FJsonObjectConverter::UStructToJsonObjectString(*this, OutJsonString, 0, 0);
}

bool FGameplayQuestSaveData::ImportFromJson(const FString& InJsonString)
{
	if (InJsonString.IsEmpty())
	{
		return false;
	}

	if (!FJsonObjectConverter::JsonObjectStringToUStruct(InJsonString, this, 0, 0))
	{
		return false;
	}

	// Validate schema version
	const UGameplayQuestSettings* Settings = UGameplayQuestSettings::Get();
	const int32 ExpectedSchema = Settings ? Settings->SaveSchemaVersion : 1;
	if (SchemaVersion > ExpectedSchema)
	{
		UE_LOG(LogGameplayQuest, Error, TEXT("ImportFromJson failed: Save schema version %d exceeds expected %d"),
			SchemaVersion, ExpectedSchema);
		return false;
	}

	return true;
}
