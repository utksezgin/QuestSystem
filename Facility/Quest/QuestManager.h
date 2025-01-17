// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "QuestManager.generated.h"

class UQuest;
UCLASS()
class FACILITY_API AQuestManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AQuestManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	TArray<UQuest*> Quests;

	//UFUNCTION(BlueprintCallable)
	void InitQuests();
	void MatchChainQuests();

	UFUNCTION(BlueprintCallable)
	UQuest* GetQuestByID(int ID);
};
