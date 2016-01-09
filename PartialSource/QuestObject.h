// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Alistair.h"
#include "QuestObject.generated.h"

/**
 * 
 */
UCLASS()
class INDIEPROJECT_API AQuestObject : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, Category = Quest)
	bool IsActive;

	UPROPERTY(BlueprintReadWrite, Category = Quest)
	bool IsComplete;

	UPROPERTY(BlueprintReadWrite, Category = Quest)
	FString QuestName;

	UFUNCTION(BlueprintCallable, Category = MyCharacter)
	void GiveQuestCredit(AAlistair* playercharacter);

	UFUNCTION(BlueprintCallable, Category = MyCharacter)
	void DrawMessage(AAlistair* playercharacter);

	AQuestObject(const FObjectInitializer& ObjectInitializer);
};
