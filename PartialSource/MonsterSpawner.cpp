// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "MonsterSpawner.h"
#include "MonsterBase.h"

AMonsterSpawner::AMonsterSpawner(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	MonsterCount = 0;

	PrimaryActorTick.bCanEverTick = true;
}

void AMonsterSpawner::Tick(float deltatime)
{
	Super::Tick(deltatime);

	MonsterCount = 0;

	for (TActorIterator<AMonsterBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr && ActorItr->NameBase == MonsterName && ActorItr->SpawnerBase == this)
		{
			MonsterCount++;
		}
	}
}