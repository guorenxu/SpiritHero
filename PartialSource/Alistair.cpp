// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "Alistair.h"

AAlistair::AAlistair(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	LeftClickState = FREE;
	RightClickState = FREE;

	LeftClickCooldown = 0.0f;
	RightClickCooldown = 0.0f;

	for (int i = 0; i < 16; i++)
	{
		FItem newitem = FItem();
		newitem.Slot = i;
		Inventory.Add(newitem);
	}

	Inventory[0].ID = POTION;
	Inventory[0].Quantity = 5;

	Inventory[1].ID = WOOD;
	Inventory[1].Quantity = 1;

	Inventory[2].ID = COIN;
	Inventory[2].Quantity = 10;

	CurrentHPBase = 97.0f;
	MaxHPBase = 97.0f;

	UsingAbility = false;
	SpawnProjectileFlag = false;

	StateChangeFlag = false;

	PlayerStunDurationBase = 0.0f;

	QuestsCompleted = 0;

	AnimationFlag = 0;

	AttackUnlocked = false;
	SkillsUnlocked = false;

	IsQuestWindowOpen = false;

	for (int i = 0; i < 4; i++)
	{
		QuestList.Add(FQuest());
	}
}

void AAlistair::Tick(float deltatime)
{
	Super::Tick(deltatime);

	if (CurrentHPBase <= 0.0f)
	{
		CurrentHPBase = 0.0f;
	}

	for (int i = 0; i < QuestList.Num(); i++)
	{
		if (QuestList[i].QuestType == NOQUEST)
		{
			QuestList.RemoveAt(i);
			QuestList.Add(FQuest());
		}
	}
}