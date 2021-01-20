// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Kismet/GameplayStatics.h" 
#include "DrawDebugHelpers.h" 

#include "System.generated.h"

#define MLOG(TXT) GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::White, TXT, false);
#define SYS ASystem::GetInst(GetWorld())
#define QUESTDATA SYS->QuestDataTable

UCLASS()
class FACILITY_API ASystem : public AActor
{
	GENERATED_BODY()
private:
	static ASystem* sys;
	
public:	
	// Sets default values for this actor's properties
	ASystem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = "true"))
	class UDataTable* QuestDataTable;

	UPROPERTY(BlueprintReadWrite)
	class AQuestManager* QuestManager;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	static ASystem* GetInst(const UObject* worldContextObject);
};
