// Fill out your copyright notice in the Description page of Project Settings.


#include "QuestManager.h"
#include "Quest.h"
#include "../System/System.h"

// Sets default values
AQuestManager::AQuestManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AQuestManager::BeginPlay()
{
	Super::BeginPlay();

	InitQuests();
	
	MLOG(Quests[0]->NextQuest->QuestDesc.ToString());

}

void AQuestManager::InitQuests() {
	TArray<FQuestTable*> QuestData;
	QUESTDATA->GetAllRows<FQuestTable>(FString(""), QuestData);
	for (auto row : QuestData) {
		UQuest* quest = NewObject<UQuest>();
		quest->InitQuest(*row);
		Quests.Add(quest);
	}

	MatchChainQuests();
}

void AQuestManager::MatchChainQuests() {
	for (auto quest : Quests) {
		quest->NextQuest = Quests[quest->NextQuestID];
	}
}

UQuest* AQuestManager::GetQuestByID(int ID) {
	if (ID < Quests.Num()) 
		return Quests[ID];

	return nullptr;
}

