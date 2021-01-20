// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Reward.generated.h"

class AItem;
UCLASS()
class FACILITY_API UReward : public UObject
{
	GENERATED_BODY()
	

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Experience;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Gold;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<AItem>> Items;

};
