// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "GameFramework/Actor.h"
#include "QuestGiver.generated.h"

class AAlistair;

/**
 * 
 */
UCLASS()
class INDIEPROJECT_API AQuestGiver : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, Category = Quest)
	bool HasGivenQuest;

	UPROPERTY(BlueprintReadWrite, Category = Quest)
	int32 QuestState;

	UPROPERTY(BlueprintReadWrite, Category = Quest)
	int32 NumQuestsNeeded;
	
	UPROPERTY(BlueprintReadWrite, Category = Quest)
	FQuest QuestToGive;

	UPROPERTY(BlueprintReadWrite, Category = Quest)
	FString GameName;

	UFUNCTION(BlueprintCallable, Category = MyCharacter)
	void GiveQuest(AAlistair* playercharacter, bool forcecomplete);

	UFUNCTION(BlueprintCallable, Category = MyCharacter)
	void TakeItems(AAlistair* playercharacter);

	AQuestGiver(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float deltatime) OVERRIDE;
};
