// Fill out your copyright notice in the Description page of Project Settings.


#include "System.h"
#include "../Quest/QuestManager.h"

// Sets default values
ASystem::ASystem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASystem::BeginPlay()
{
	Super::BeginPlay();

	sys = nullptr;
	QuestManager = (AQuestManager*)GetWorld()->SpawnActor(AQuestManager::StaticClass(), &FVector::ZeroVector);
}

// Called every frame
void ASystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ASystem* ASystem::GetInst(const UObject* worldContextObject) {
	if (!sys) {
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(worldContextObject, ASystem::StaticClass(), FoundActors);

		if (FoundActors.Num() > 0) {
			sys = dynamic_cast<ASystem*>(FoundActors[0]);
		}
	}
	return sys;
}

ASystem* ASystem::sys = nullptr;