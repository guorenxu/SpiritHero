// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.generated.h"
/**
 * 
 */


//This is the item struct used to hold information about things in the inventory.

USTRUCT(BlueprintType)
struct FItem
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	int32 Slot;

	FItem()
	{
		ID = 0;
		Quantity = 0;
		Slot = -1;
	}
};

USTRUCT(BlueprintType)
struct FDamage
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	int32 Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage")
	float Timer;

	FDamage()
	{
		Timer = 0.0f;
		Amount = 0;
	}
};

struct ItemInfo
{
	bool IsUsable;
	FString Name;

	ItemInfo(bool isusable, FString name)
	{
		IsUsable = isusable;
		Name = name;
	}
};

struct Announcement
{
	FString Content;
	FLinearColor Color;
	UFont* Font;
	FVector Location;

	Announcement(FString content, FLinearColor color, UFont* font, FVector startinglocation)
	{
		Content = content;
		Color = color;
		Font = font;
		Location = startinglocation;
	}
};

USTRUCT(BlueprintType)
struct FQuest
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	FString QuestName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int32 QuestType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int32 ContentID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int32 Amount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int32 Progress;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Quest")
	int32 QuestID;

	FQuest()
	{
		QuestID = 0;
		QuestType = 0;
		ContentID = 0;
		QuestName = "";
		Amount = 0;
		Progress = 0;
	}
};

USTRUCT(BlueprintType)
struct FAbility
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		FString AbilityName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		float CurrentCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		float BaseCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		float WindupTime;

	FAbility()
	{
		AbilityName = "";
		BaseCooldown = 0.0f;
		CurrentCooldown = 0.0f;
		WindupTime = 0.0f;
	}
};