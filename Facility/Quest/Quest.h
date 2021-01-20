// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Engine/DataTable.h"

#include "../Enemy/Enemy.h"
#include "../Item/Item.h"

#include "Quest.generated.h"

class UReward;

UENUM(BlueprintType)
enum class EQuestStatus : uint8 {
	E_Locked		UMETA(DisplayName = "Locked"),
	E_Available		UMETA(DisplayName = "Available"),
	E_InProgress	UMETA(DisplayName = "In Progress"),
	E_Completed		UMETA(DisplayName = "Completed"),
	E_Delivered		UMETA(DisplayName = "Delivered")
};

UENUM(BlueprintType)
enum class EQuestType : uint8 {
	E_Dialogue		UMETA(DisplayName = "Dialogue"),
	E_Gather		UMETA(DisplayName = "Gather"),
	E_Slay			UMETA(DisplayName = "Slay")
};

USTRUCT(BlueprintType)
struct FQuestEssentials {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<AEnemy>>	TargetEnemies;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int>					KillCounts;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int>					CurrentKillCounts;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<AItem>>	GatherItems;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int>					GatherCounts;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int>					CurrentGatherCounts;

};

USTRUCT(BlueprintType)
struct FTarget {
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool	bIsTargetAoE;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector TargetLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float	TargetRadius;
};

USTRUCT(BlueprintType)
struct FQuestTable : public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (DisplayName = "ID"))
	int								ID = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Quest Name"))
	FName							QuestName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Quest Description"))
	FName							QuestDesc;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Next Quest ID"))
	int								NextQuestID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Quest Reward Experience"))
	float							RewardExperience;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Quest Reward Gold"))
	int								RewardGold;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Quest Reward Items"))
	TArray<TSubclassOf<AItem>>		QuestRewardItems;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Quest Status"))
	EQuestStatus					eQuestStatus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Quest Type"))
	EQuestType						eQuestType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Target Enemies"))
	TArray<TSubclassOf<AEnemy>>		TargetEnemies;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Kill Numbers"))
	TArray<int>						KillCounts;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Gather Items"))
	TArray<TSubclassOf<AItem>>		GatherItems;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Gather Numbers"))
	TArray<int>						GatherCounts;
		
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Is Quest AoE"))
	bool							bIsTargetAoE;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Quest Target Location"))
	FVector							TargetLocation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Quest Target Radius"))
	float							TargetRadius;
};

UCLASS(Blueprintable)
class FACILITY_API UQuest : public UObject
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UQuest();

public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName QuestName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName QuestDesc;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NpcID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int NextQuestID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UQuest* NextQuest;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UReward* QuestReward;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EQuestStatus eQuestStatus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EQuestType eQuestType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FQuestEssentials QuestEssentials;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTarget Target;



	UFUNCTION(BlueprintCallable, Category = "Quest")
	void InitQuest(const FQuestTable& DataRow);

	UFUNCTION(BlueprintCallable, Category = "Quest")
	void UnlockQuest();

	UFUNCTION(BlueprintCallable, Category = "Quest")
	void TakeOnQuest();

	UFUNCTION(BlueprintCallable, Category = "Quest")
	virtual FORCEINLINE EQuestStatus CheckQuestComplete(){ return EQuestStatus::E_InProgress;}

	UFUNCTION(BlueprintCallable, Category = "Quest")
	bool CompleteQuest();

	UFUNCTION(BlueprintCallable, Category = "Quest")
	UReward* DeliverQuest();


};