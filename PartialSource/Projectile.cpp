// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "Projectile.h"

AProjectile::AProjectile(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ConstructorHelpers::FObjectFinder<UParticleSystem> PSClass(TEXT("ParticleSystem'/Game/BaronParticles/SwordParticle2.SwordParticle2'"));

	if (PSClass.Object)
	{
		WindSlashParticle = PSClass.Object;
	}
}

void AProjectile::Tick(float deltatime)
{
	Super::Tick(deltatime);
		
	FVector difference = Target->GetActorLocation() - GetActorLocation();

	FaceRotation(difference.Rotation());

	if (difference.Size() <= 50.0f)
	{
		Target->CurrentHPBase -= 50.0f;

		FDamage newdamage;
		newdamage.Amount = 50;

		Target->DamageArray.Add(newdamage);

		Target->AggroFlag = true;

		UGameplayStatics::SpawnEmitterAtLocation(Target, WindSlashParticle, Target->GetActorLocation() + FVector(0.0f, 0.0f, 100.0f));

		this->Destroy();
	}
	else
	{
		difference.Normalize();

		FVector newlocation = GetActorLocation() + difference * 2700.0f * deltatime;

		SetActorLocation(newlocation);
	}
}
