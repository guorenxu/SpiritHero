// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "MonsterSpawner.h"
#include "GameFramework/Character.h"
#include "MonsterBase.generated.h"

/**
 * 
 */
UCLASS()
class INDIEPROJECT_API AMonsterBase : public ACharacter
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float MaxHPBase;
	
	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float CurrentHPBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	int32 DamageBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	FString NameBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool IsAliveBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool IsTargetBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool IsDestinationBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool IsControlTarget;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool HasGivenQuestCredit;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool IsAggro;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float BaseAggroTimer;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float CurrentAggroTimer;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float LeashRange;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float AggroRange;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float BaseAggroCooldown;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float CurrentAggroCooldown;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float CameraDistance;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float CurrentAttackDelay;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float BaseAttackDelay;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float BonusAttackRange;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	int32 GolemAttackMode;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool AggroFlag;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	AMonsterSpawner* SpawnerBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	int32 IDBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	TArray<FDamage> DamageArray;

	AMonsterBase(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float deltatime) OVERRIDE;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = MyCharacter)
	int32 GenerateDamage(int32 variation);
};
