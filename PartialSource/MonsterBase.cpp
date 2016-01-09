// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "MonsterBase.h"
#include "Alistair.h"
#include "QuestWindow.h"

AMonsterBase::AMonsterBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	IsControlTarget = false;

	DamageBase = 0;

	IDBase = 0;

	HasGivenQuestCredit = false;

	IsAggro = false;

	BaseAggroTimer = 2.0f;
	CurrentAggroTimer = -0.0f;

	CameraDistance = 0.0f;

	BaseAttackDelay = 0.5f;
	CurrentAttackDelay = BaseAttackDelay;

	GolemAttackMode = 0;

	BonusAttackRange = 0.0f;

	AggroFlag = false;
}

void AMonsterBase::Tick(float deltatime)
{
	Super::Tick(deltatime);

	for (int i = 0; i < this->DamageArray.Num(); i++)
	{
		DamageArray[i].Timer += deltatime;
	}

	bool isdamageover = true;

	for (int i = 0; i < this->DamageArray.Num(); i++)
	{
		if (DamageArray[i].Timer < 2.0f)
		{
			isdamageover = false;
		}
	}

	if (isdamageover)
	{
		DamageArray.Empty();
	}

	//If dead and did not give quest credit yet, give quest credit
	if (!IsAliveBase)
	{
		if (!HasGivenQuestCredit)
		{
			for (TActorIterator<AAlistair> ActorItr(GetWorld()); ActorItr; ++ActorItr)
			{
				if (ActorItr)
				{
					for (int i = 0; i < ActorItr->QuestList.Num(); i++)
					{
						if (ActorItr->QuestList[i].QuestType == KILLQUEST)
						{
							if (ActorItr->QuestList[i].ContentID == IDBase)
							{
								ActorItr->QuestList[i].Progress++;
								HasGivenQuestCredit = true;
							}
						}
					}
				}
			}
		}
	}
}

int32 AMonsterBase::GenerateDamage(int32 variation)
{
	return DamageBase + FMath::RandRange(-variation, variation);
}