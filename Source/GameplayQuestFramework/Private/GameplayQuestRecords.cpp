// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestRecords.h"
#include "GameplayQuestManagerComponent.h"
#include "GameplayQuestTags.h"

FGameplayQuestRecord::FGameplayQuestRecord()
{
	StatusTag = GameplayQuestTags::TAG_Quest_Status_Active_InProgress.GetTag();
	CurrentStageIndex = 0;
}

void FGameplayQuestRecord::PostReplicatedAdd(const FGameplayQuestRecordList& InArraySerializer)
{
	if (InArraySerializer.OwnerComponent)
	{
		InArraySerializer.OwnerComponent->HandleQuestRecordAdded(*this);
	}
}

void FGameplayQuestRecord::PostReplicatedChange(const FGameplayQuestRecordList& InArraySerializer)
{
	if (InArraySerializer.OwnerComponent)
	{
		InArraySerializer.OwnerComponent->HandleQuestRecordChanged(*this);
	}
}

void FGameplayQuestRecord::PreReplicatedRemove(const FGameplayQuestRecordList& InArraySerializer)
{
	if (InArraySerializer.OwnerComponent)
	{
		InArraySerializer.OwnerComponent->HandleQuestRecordRemoved(*this);
	}
}

FGameplayObjectiveRecord* FGameplayQuestRecord::FindObjectiveRecord(const FGameplayTag& InObjectiveTag)
{
	if (!InObjectiveTag.IsValid())
	{
		return nullptr;
	}

	for (FGameplayObjectiveRecord& Record : ObjectiveRecords)
	{
		if (Record.ObjectiveTag == InObjectiveTag)
		{
			return &Record;
		}
	}

	return nullptr;
}

const FGameplayObjectiveRecord* FGameplayQuestRecord::FindObjectiveRecord(const FGameplayTag& InObjectiveTag) const
{
	if (!InObjectiveTag.IsValid())
	{
		return nullptr;
	}

	for (const FGameplayObjectiveRecord& Record : ObjectiveRecords)
	{
		if (Record.ObjectiveTag == InObjectiveTag)
		{
			return &Record;
		}
	}

	return nullptr;
}

bool FGameplayQuestRecord::AreStageObjectivesCompleted() const
{
	if (ObjectiveRecords.Num() == 0)
	{
		return true;
	}

	for (const FGameplayObjectiveRecord& ObjRecord : ObjectiveRecords)
	{
		if (!ObjRecord.IsCompleted())
		{
			return false;
		}
	}

	return true;
}

// ----------------------------------------------------------------------------
// FGameplayQuestRecordList
// ----------------------------------------------------------------------------

FGameplayQuestRecordList::FGameplayQuestRecordList()
{
}

FGameplayQuestRecord* FGameplayQuestRecordList::AddQuestRecord(const FGameplayTag& QuestTag, const FGameplayTag& InitialStatusTag, int32 StageIndex)
{
	if (!QuestTag.IsValid())
	{
		return nullptr;
	}

	if (FGameplayQuestRecord* Existing = FindQuestRecord(QuestTag))
	{
		return Existing;
	}

	FGameplayQuestRecord& NewItem = Items.AddDefaulted_GetRef();
	NewItem.QuestTag = QuestTag;
	NewItem.StatusTag = InitialStatusTag.IsValid() ? InitialStatusTag : GameplayQuestTags::TAG_Quest_Status_Active_InProgress.GetTag();
	NewItem.CurrentStageIndex = StageIndex;

	MarkItemDirty(NewItem);
	return &NewItem;
}

bool FGameplayQuestRecordList::RemoveQuestRecord(const FGameplayTag& QuestTag)
{
	for (int32 Index = 0; Index < Items.Num(); ++Index)
	{
		if (Items[Index].QuestTag == QuestTag)
		{
			Items.RemoveAt(Index);
			MarkArrayDirty();
			return true;
		}
	}

	return false;
}

FGameplayQuestRecord* FGameplayQuestRecordList::FindQuestRecord(const FGameplayTag& QuestTag)
{
	if (!QuestTag.IsValid())
	{
		return nullptr;
	}

	for (FGameplayQuestRecord& Item : Items)
	{
		if (Item.QuestTag == QuestTag)
		{
			return &Item;
		}
	}

	return nullptr;
}

const FGameplayQuestRecord* FGameplayQuestRecordList::FindQuestRecord(const FGameplayTag& QuestTag) const
{
	if (!QuestTag.IsValid())
	{
		return nullptr;
	}

	for (const FGameplayQuestRecord& Item : Items)
	{
		if (Item.QuestTag == QuestTag)
		{
			return &Item;
		}
	}

	return nullptr;
}

void FGameplayQuestRecordList::MarkQuestDirty(FGameplayQuestRecord& Record)
{
	MarkItemDirty(Record);
}
