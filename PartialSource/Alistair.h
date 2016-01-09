// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "GameFramework/Character.h"
#include "MonsterBase.h"
#include "Alistair.generated.h"

class AStatusHUDTest;

/**
*
*/
UCLASS()
class INDIEPROJECT_API AAlistair : public AMonsterBase
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	int32 LeftClickState;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	int32 RightClickState;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	int32 LeftMouseStatus;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float LeftClickCooldown;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float RightClickCooldown;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	float PlayerStunDurationBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool StateChangeFlag;

	AAlistair(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	TArray<FItem> Inventory;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	TArray<FQuest> QuestList;

	AStatusHUDTest* PlayerHUD;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	AMonsterBase* MoveTargetBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	AMonsterBase* TargetBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	AMonsterBase* SpellTargetBase;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool UsingAbility;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool IsQuestWindowOpen;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool SpawnProjectileFlag;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	int32 QuestsCompleted;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool AttackUnlocked;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	bool SkillsUnlocked;

	UPROPERTY(BlueprintReadWrite, Category = MyCharacter)
	int32 AnimationFlag;

	virtual void Tick(float deltatime) OVERRIDE;
};
