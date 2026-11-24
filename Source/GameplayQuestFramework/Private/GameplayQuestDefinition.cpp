// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameplayQuestDefinition.h"
#include "GameplayQuestTags.h"

#if WITH_EDITOR
#include "Misc/DataValidation.h"
#endif

UGameplayQuestDefinition::UGameplayQuestDefinition(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CategoryTag = GameplayQuestTags::TAG_Quest_Status_Active.GetTag();
	ProgressionFlowTag = GameplayQuestTags::TAG_Quest_Progression_Sequential.GetTag();
}

bool UGameplayQuestDefinition::CanAcceptQuest(const FGameplayTagContainer& PlayerContextTags) const
{
	if (PrerequisiteQuery.IsEmpty())
	{
		return true;
	}

	return PrerequisiteQuery.Matches(PlayerContextTags);
}

void UGameplayQuestDefinition::GetObjectivesForStage(int32 StageIndex, TArray<UGameplayObjectiveDefinition*>& OutObjectives) const
{
	OutObjectives.Reset();

	if (Stages.IsValidIndex(StageIndex))
	{
		for (const TObjectPtr<UGameplayObjectiveDefinition>& ObjDef : Stages[StageIndex].Objectives)
		{
			if (ObjDef)
			{
				OutObjectives.Add(ObjDef.Get());
			}
		}
	}
}

FPrimaryAssetId UGameplayQuestDefinition::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(FPrimaryAssetType(TEXT("GameplayQuest")), GetFName());
}

#if WITH_EDITOR
EDataValidationResult UGameplayQuestDefinition::IsDataValid(FDataValidationContext& Context) const
{
	EDataValidationResult Result = Super::IsDataValid(Context);

	if (!QuestTag.IsValid())
	{
		Context.AddError(FText::FromString(TEXT("QuestTag must be a valid GameplayTag.")));
		Result = EDataValidationResult::Invalid;
	}

	if (Stages.Num() == 0)
	{
		Context.AddError(FText::FromString(TEXT("Quest must have at least one stage defined.")));
		Result = EDataValidationResult::Invalid;
	}

	for (int32 StageIdx = 0; StageIdx < Stages.Num(); ++StageIdx)
	{
		const FGameplayQuestStage& Stage = Stages[StageIdx];
		if (Stage.Objectives.Num() == 0)
		{
			Context.AddError(FText::Format(
				FText::FromString(TEXT("Stage {0} has no objectives defined.")),
				FText::AsNumber(StageIdx)
			));
			Result = EDataValidationResult::Invalid;
		}

		for (const TObjectPtr<UGameplayObjectiveDefinition>& Obj : Stage.Objectives)
		{
			if (!Obj)
			{
				Context.AddError(FText::Format(
					FText::FromString(TEXT("Stage {0} contains a null objective entry.")),
					FText::AsNumber(StageIdx)
				));
				Result = EDataValidationResult::Invalid;
			}
		}
	}

	return Result;
}
#endif
