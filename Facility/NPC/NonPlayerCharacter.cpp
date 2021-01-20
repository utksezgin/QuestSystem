// Fill out your copyright notice in the Description page of Project Settings.

#include "NonPlayerCharacter.h"
#include "../Quest/Reward.h"
#include "../Quest/Quest.h"
#include "../Quest/QuestManager.h"
#include "../System/System.h"

// Sets default values
ANonPlayerCharacter::ANonPlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANonPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	for (auto quest : SYS->QuestManager->Quests) {
		if (quest->NpcID == NpcID) {
			Quests.Add(quest);
		}
	}
	
}

// Called every frame
void ANonPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANonPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TArray<UQuest*> ANonPlayerCharacter::GetAvailableQuests() const{
	TArray<UQuest*> AvailableQuests;

	for (auto Quest : Quests) {
		if(Quest->eQuestStatus == EQuestStatus::E_Available)
			AvailableQuests.Add(Quest);
	}

	return AvailableQuests;
}

TArray<UQuest*> ANonPlayerCharacter::GetQuestsInProgress() const{
	TArray<UQuest*> QuestsInProgress;

	for (auto Quest : Quests) {
		if (Quest->eQuestStatus == EQuestStatus::E_InProgress)
			QuestsInProgress.Add(Quest);
	}

	return QuestsInProgress;
}

TArray<UQuest*> ANonPlayerCharacter::GetCompletedQuests() const{
	TArray<UQuest*> CompletedQuests;

	for (auto Quest : Quests) {
		if (Quest->eQuestStatus == EQuestStatus::E_Completed)
			CompletedQuests.Add(Quest);
	}

	return CompletedQuests;
}

TArray<UQuest*> ANonPlayerCharacter::GetFinishedQuests() const{
	TArray<UQuest*> FinishedQuests;

	for (auto Quest : Quests) {
		if (Quest->eQuestStatus == EQuestStatus::E_Delivered)
			FinishedQuests.Add(Quest);
	}

	return FinishedQuests;
}


UReward* ANonPlayerCharacter::CompleteQuest(UQuest* Quest) const {
	return Quest->DeliverQuest();
}
