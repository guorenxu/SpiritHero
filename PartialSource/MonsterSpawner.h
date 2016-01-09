// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MonsterSpawner.generated.h"

/**
 * 
 */
UCLASS()
class INDIEPROJECT_API AMonsterSpawner : public AActor
{
	GENERATED_BODY()
	
public:

	AMonsterSpawner(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float deltatime) OVERRIDE;

	UPROPERTY(BlueprintReadWrite, Category = MonsterSpawner)
	int32 MonsterCount;

	UPROPERTY(BlueprintReadWrite, Category = MonsterSpawner)
	FString MonsterName;
};
