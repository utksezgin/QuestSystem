// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Quest/Quest.h"
#include "NonPlayerCharacter.generated.h"



UCLASS()
class FACILITY_API ANonPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANonPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName NPCName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NpcID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UQuest*> Quests;

	UFUNCTION(BlueprintCallable, Category = "NPC")
	TArray<UQuest*> GetAvailableQuests() const;

	UFUNCTION(BlueprintCallable, Category = "NPC")
	TArray<UQuest*> GetQuestsInProgress() const;

	UFUNCTION(BlueprintCallable, Category = "NPC")
	TArray<UQuest*> GetCompletedQuests() const;

	UFUNCTION(BlueprintCallable, Category = "NPC")
	TArray<UQuest*> GetFinishedQuests() const;

	UFUNCTION(BlueprintCallable, Category = "NPC")
	UReward* CompleteQuest(UQuest* Quest) const;

};
