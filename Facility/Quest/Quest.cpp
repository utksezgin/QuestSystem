// Fill out your copyright notice in the Description page of Project Settings.

#include "Quest.h"
#include "Reward.h"

// Sets default values
UQuest::UQuest()
{
}


void UQuest::InitQuest(const FQuestTable& DataRow) {
	QuestName = DataRow.QuestName;
	QuestDesc = DataRow.QuestDesc;
	NextQuestID = DataRow.NextQuestID;
	QuestReward = NewObject<UReward>();
	QuestReward->Experience = DataRow.RewardExperience;
	QuestReward->Gold = DataRow.RewardGold;
	for(auto item : DataRow.QuestRewardItems)
		QuestReward->Items.Add(item);
	eQuestStatus = DataRow.eQuestStatus;
	
	for (auto enemy : DataRow.TargetEnemies)
		QuestEssentials.TargetEnemies.Add(enemy);

	for (auto count : DataRow.KillCounts) {
		QuestEssentials.KillCounts.Add(count);
		QuestEssentials.CurrentKillCounts.Add(0);
	}

	for (auto item : DataRow.GatherItems)
		QuestEssentials.GatherItems.Add(item);

	for (auto count : DataRow.GatherCounts) {
		QuestEssentials.GatherCounts.Add(count);
		QuestEssentials.CurrentGatherCounts.Add(0);
	}

	Target.bIsTargetAoE = DataRow.bIsTargetAoE;
	Target.TargetLocation = DataRow.TargetLocation;
	Target.TargetRadius = DataRow.TargetRadius;


}

void UQuest::UnlockQuest() {
	eQuestStatus = EQuestStatus::E_Available;
}

void UQuest::TakeOnQuest() {
	eQuestStatus = EQuestStatus::E_InProgress;
}

bool UQuest::CompleteQuest() {
	if (CheckQuestComplete() == EQuestStatus::E_Completed) {
		eQuestStatus = EQuestStatus::E_Completed;
		return true;
	}
	else
		return false;
}

UReward* UQuest::DeliverQuest() {
	if (eQuestStatus == EQuestStatus::E_Completed) {
		eQuestStatus = EQuestStatus::E_Delivered;
		if (NextQuest) {
			NextQuest->eQuestStatus = EQuestStatus::E_Available;
		}
		return QuestReward;
	}
	else
		return nullptr;
}

