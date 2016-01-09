// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "QuestObject.h"
#include "StatusHUDTest.h"
#include "QuickbarWindow.h"

AQuestObject::AQuestObject(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	IsComplete = false;
	IsActive = false;
	QuestName = "A Small Task";
}

void AQuestObject::GiveQuestCredit(AAlistair* playercharacter)
{
	for (int i = 0; i < playercharacter->QuestList.Num(); i++)
	{
		if (playercharacter->QuestList[i].QuestName == QuestName)
		{
			playercharacter->QuestList[i].Progress++;
		}
	}

	IsComplete = true;
}

void AQuestObject::DrawMessage(AAlistair* playercharacter)
{
	bool hasquest = false;

	for (int i = 0; i < playercharacter->QuestList.Num(); i++)
	{
		if (playercharacter->QuestList[i].QuestName == QuestName)
		{
			hasquest = true;
		}
	}

	if (hasquest)
	{
		GiveQuestCredit(playercharacter);

		FString questtext = "You water the plant...";

		playercharacter->PlayerHUD->HUDAnnouncements.push_back(
			new Announcement(questtext,
			FLinearColor(0.8f, 0.8f, 1.0f),
			playercharacter->PlayerHUD->DamageFont,
			FVector(200.0f, 250.0f, 0.0f)));

		for (int i = 0; i < playercharacter->PlayerHUD->WindowVector.size(); i++)
		{
			if (playercharacter->PlayerHUD->WindowVector[i]->WindowName == "Quickbar Window")
			{
				((QuickbarWindow*)playercharacter->PlayerHUD->WindowVector[i])->WaterPlant();
			}
		}
	}
}