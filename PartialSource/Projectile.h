// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MonsterBase.h"

#include "Projectile.generated.h"

/**
 * 
 */
UCLASS()
class INDIEPROJECT_API AProjectile : public ACharacter
{
	GENERATED_BODY()
	
public:

	AProjectile(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	AMonsterBase* Target;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	UParticleSystem* WindSlashParticle;

	virtual void Tick(float deltatime) OVERRIDE;
};
