// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "QuestWindow.h"
#include "StatusHUDTest.h"

vector<FString*> QuestWindow::MonsterNames;

vector<ItemInfo*> QuestWindow::ItemInfoVector;

void QuestWindow::Draw()
{
}

void QuestWindow::Init()
{
	for (int i = 0; i < 4; i++)
	{
		TextWindowPart* questtitlecomponent = new TextWindowPart();
		questtitlecomponent->Font = HUDManager->VerdanaFont;
		questtitlecomponent->TextColor = FLinearColor::White;
		questtitlecomponent->Location = FVector(10.0f, 40.0f + (i * 60.0f), 0.0f);
		questtitlecomponent->TextContent = "";

		TextWindowPart* questdirectioncomponent = new TextWindowPart();
		questdirectioncomponent->Font = HUDManager->VerdanaFont;
		questdirectioncomponent->TextColor = FLinearColor(1.0f, 1.0f, 0.1f);
		questdirectioncomponent->Location = FVector(20.0f, 61.0f + (i * 60.0f), 0.0f);
		questdirectioncomponent->TextContent = "";

		float sizex;
		float sizey;
		HUDManager->GetTextSize(questdirectioncomponent->TextContent,
			sizex,
			sizey,
			HUDManager->VerdanaFont);

		TextWindowPart* questprogresscomponent = new TextWindowPart();
		questprogresscomponent->Font = HUDManager->VerdanaFont;
		questprogresscomponent->TextColor = FLinearColor(0.1f, 1.0f, 0.1f);
		questprogresscomponent->Location = FVector(20.0f + sizex + 3.0f, 61.0f + (i * 60.0f), 0.0f);
		questprogresscomponent->TextContent = "";

		TextComponents.push_back(questtitlecomponent);
		TextComponents.push_back(questdirectioncomponent);
		TextComponents.push_back(questprogresscomponent);
	}

	MonsterNames.push_back(new FString(""));
	MonsterNames.push_back(new FString("Forest Sprite"));
	MonsterNames.push_back(new FString("Forest Elder"));
	MonsterNames.push_back(new FString("Tainted Sprite"));
	MonsterNames.push_back(new FString("Ancient Golem"));
}

void QuestWindow::Update()
{
	for (int i = 0; i < PlayerCharacter->QuestList.Num(); i++)
	{
		switch (PlayerCharacter->QuestList[i].QuestType)
		{
		case KILLQUEST:
		{
			TextComponents[i * 3]->TextContent = PlayerCharacter->QuestList[i].QuestName;
			FString temp = "Kill " + *MonsterNames[PlayerCharacter->QuestList[i].ContentID];
			TextComponents[i * 3 + 1]->TextContent = temp;

			//If progress is greater than requirement, mark quest as completable
			if (PlayerCharacter->QuestList[i].Progress >= PlayerCharacter->QuestList[i].Amount)
			{
				TextComponents[i * 3 + 1]->TextContent = "COMPLETE";
				TextComponents[i * 3 + 2]->TextContent = "";
			}
			else
			{
				TextComponents[i * 3 + 2]->TextContent = "(" + FString::FromInt(PlayerCharacter->QuestList[i].Progress) + "/" + FString::FromInt(PlayerCharacter->QuestList[i].Amount) + ")";
			}

			float sizex;
			float sizey;
			HUDManager->GetTextSize(TextComponents[i * 3 + 1]->TextContent,
				sizex,
				sizey,
				HUDManager->VerdanaFont);

			TextComponents[i * 3 + 2]->Location = FVector(20.0f + sizex + 3.0f, 61.0f + (i * 60.0f), 0.0f);
		}
		break;
		case COLLECTQUEST:
		{
			TextComponents[i * 3]->TextContent = PlayerCharacter->QuestList[i].QuestName;
			FString temp = "Collect " + ItemInfoVector[PlayerCharacter->QuestList[i].ContentID]->Name;
			TextComponents[i * 3 + 1]->TextContent = temp;

			if (PlayerCharacter->QuestList[i].Progress >= PlayerCharacter->QuestList[i].Amount)
			{
				TextComponents[i * 3 + 1]->TextContent = "COMPLETE";
				TextComponents[i * 3 + 2]->TextContent = "";
			}
			else
			{
				TextComponents[i * 3 + 2]->TextContent = "(" + FString::FromInt(PlayerCharacter->QuestList[i].Progress) + "/" + FString::FromInt(PlayerCharacter->QuestList[i].Amount) + ")";
			}

			float sizex;
			float sizey;
			HUDManager->GetTextSize(TextComponents[i * 3 + 1]->TextContent,
				sizex,
				sizey,
				HUDManager->VerdanaFont);

			TextComponents[i * 3 + 2]->Location = FVector(20.0f + sizex + 3.0f, 61.0f + (i * 60.0f), 0.0f);
		}
		break;
		case SPECIALQUEST:
		{
			TextComponents[i * 3]->TextContent = PlayerCharacter->QuestList[i].QuestName;
			FString temp = "Water the plants";
			TextComponents[i * 3 + 1]->TextContent = temp;

			if (PlayerCharacter->QuestList[i].Progress >= PlayerCharacter->QuestList[i].Amount)
			{
				TextComponents[i * 3 + 1]->TextContent = "COMPLETE";
				TextComponents[i * 3 + 2]->TextContent = "";
			}
			else
			{
				TextComponents[i * 3 + 2]->TextContent = "(" + FString::FromInt(PlayerCharacter->QuestList[i].Progress) + "/" + FString::FromInt(PlayerCharacter->QuestList[i].Amount) + ")";
			}

			float sizex;
			float sizey;
			HUDManager->GetTextSize(TextComponents[i * 3 + 1]->TextContent,
				sizex,
				sizey,
				HUDManager->VerdanaFont);

			TextComponents[i * 3 + 2]->Location = FVector(20.0f + sizex + 3.0f, 61.0f + (i * 60.0f), 0.0f);
		}
		break;
		case GOTOQUEST:
		{
			TextComponents[i * 3]->TextContent = PlayerCharacter->QuestList[i].QuestName;
			FString temp = "Get to the outpost";
			TextComponents[i * 3 + 1]->TextContent = temp;

			if (PlayerCharacter->QuestList[i].Progress >= PlayerCharacter->QuestList[i].Amount)
			{
				TextComponents[i * 3 + 1]->TextContent = "COMPLETE";
				TextComponents[i * 3 + 2]->TextContent = "";
			}
			else
			{
				TextComponents[i * 3 + 2]->TextContent = "(0/1)";
			}

			float sizex;
			float sizey;
			HUDManager->GetTextSize(TextComponents[i * 3 + 1]->TextContent,
				sizex,
				sizey,
				HUDManager->VerdanaFont);

			TextComponents[i * 3 + 2]->Location = FVector(20.0f + sizex + 3.0f, 61.0f + (i * 60.0f), 0.0f);
		}
		break;
		case NOQUEST:
		{
			TextComponents[i * 3]->TextContent = "";
			TextComponents[i * 3 + 1]->TextContent = "";
			TextComponents[i * 3 + 2]->TextContent = "";
		}
		break;
		default:
			break;
		};
	}

	//Quick hack for time's sake
	for (TActorIterator<AQuestObject> ActorItr(HUDManager->GetWorld()); ActorItr; ++ActorItr)
	{
		if ((ActorItr->GetActorLocation() - PlayerCharacter->GetActorLocation()).Size() <= 200.0f && !ActorItr->IsComplete)
		{
			ActorItr->GiveQuestCredit(PlayerCharacter);

			FString questtext = "You water the plant...";

			PlayerCharacter->PlayerHUD->HUDAnnouncements.push_back(
				new Announcement(questtext,
				FLinearColor(0.8f, 0.8f, 1.0f),
				PlayerCharacter->PlayerHUD->DamageFont,
				FVector(200.0f, 250.0f, 0.0f)));
			break;
		}
	}

	if (IsActive)
	{
		PlayerCharacter->IsQuestWindowOpen = true;
	}
	else
	{
		PlayerCharacter->IsQuestWindowOpen = false;
	}
}