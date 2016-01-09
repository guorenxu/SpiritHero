// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "QuestGiver.h"
#include "Alistair.h"
#include "StatusHUDTest.h"

AQuestGiver::AQuestGiver(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	HasGivenQuest = false;
	QuestState = LOCKED;

	NumQuestsNeeded = 0;

	PrimaryActorTick.bCanEverTick = true;

	GameName = "";
}

void AQuestGiver::Tick(float deltatime)
{
	Super::Tick(deltatime);

	for (TActorIterator<AAlistair> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->QuestsCompleted >= NumQuestsNeeded && QuestState == LOCKED)
		{
			QuestState = NOTTAKEN;
		}
	}
}

void AQuestGiver::GiveQuest(AAlistair* playercharacter, bool forcecomplete)
{
	if (!HasGivenQuest)
	{
		if (!forcecomplete)
		{
			vector<FString> TextBlock;

			FString OptionOne = "Yes, I'm ready for my adventure!";
			FString OptionTwo = "No, I'm going to enjoy the view some more.";

			if (QuestToGive.QuestID == 3)
			{
				OptionOne = "Yes, I'm ready for my adventure!";
				OptionTwo = "No, I'm going to enjoy the view some more.";

				TextBlock.push_back("A brand new day for a brand new adventure! According to this sign, the road leads to a");
				TextBlock.push_back("small outpost ahead. Rumor has it though, that there is a dark evil spreading across the");
				TextBlock.push_back("region. This is a perfect chance! I should go check the outpost out. Maybe the locals");
				TextBlock.push_back("there need help from a brave adventurer like myself!");
			}
			else if (QuestToGive.QuestID == 2)
			{
				OptionOne = "Sure thing! I'll do anything for a shiny weapon!";
				OptionTwo = "No, I'm not ready for it yet.";

				TextBlock.push_back("Alistair: Hi! I'm Alistair!");
				TextBlock.push_back("");
				TextBlock.push_back("Gingerfoot: Waaah! I can't take it anymore! ");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: What's going on? Maybe I can help.");
				TextBlock.push_back("");
				TextBlock.push_back("Gingerfoot: You? Help? Hah! You don't even have a weapon! Who do you think you are?");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: ...");
				TextBlock.push_back("");
				TextBlock.push_back("Gingerfoot: Tell you what, if you help me water some of my royal plants, I'll give you a");
				TextBlock.push_back("sword and shield and consider you for a more important task..");
			}
			else if (QuestToGive.QuestID == 1)
			{
				OptionOne = "Take the quest.";
				OptionTwo = "I don't want to die yet!";

				TextBlock.push_back("The adventurer's board is cluttered with notes indicating various tasks. Most of them have");
				TextBlock.push_back("already been completed. One though, catches your eyes. It is a quest to to end the suffering");
				TextBlock.push_back("of some of the sprites that have been infected with the evil spread across the land.");
				TextBlock.push_back("According to note, anyone who is able to complete the quest will earn attention from the");
				TextBlock.push_back("Sprite King himself.");
			}
			else if (QuestToGive.QuestID == 4)
			{
				OptionOne = "I'm ready to face the golem!";
				OptionTwo = "I don't want to die this young.";

				TextBlock.push_back("Alistair: Phew, that was some tiring training.");
				TextBlock.push_back("");
				TextBlock.push_back("Sprite King: But I'm sure you've learned a lot. In fact, I believe that you are ready for your");
				TextBlock.push_back("greatest challenge yet.");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: Whatever it is, I would definitely like to give it a try!");
				TextBlock.push_back("");
				TextBlock.push_back("Sprite King: My scouts have recently discovered that the evil in our land is caused by the");
				TextBlock.push_back("prescence of an evil ancient golem to the north. I would like you to destroy him.");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: Sounds like a challenge. Anything you want to tell me that can help me in the fight?");
				TextBlock.push_back("");
				TextBlock.push_back("Sprite King: Be careful. He will be like no foe you've faced before. Use everything I have taught");
				TextBlock.push_back("you and you should have a good chance against him.");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: Understood. Wish me luck!");
			}

			DialogueWindow* TheDialogue = new DialogueWindow();

			TheDialogue->WindowName = QuestToGive.QuestName;

			TheDialogue->BaseInit(playercharacter->PlayerHUD->XButtonTex, playercharacter->PlayerHUD, playercharacter);
			TheDialogue->Init();

			ImageWindowPart* newimagecomponent = new ImageWindowPart();
			newimagecomponent->IsHoverable = true;
			newimagecomponent->SizeToDraw = FVector(630.0f, 30.0f, 0.0f);
			newimagecomponent->Location = FVector(10.0f, 430.0f, 0.0f);
			newimagecomponent->TextureToDraw = playercharacter->PlayerHUD->QuestChoiceTex;

			ImageWindowPart* newimagecomponenttwo = new ImageWindowPart();
			newimagecomponenttwo->IsHoverable = true;
			newimagecomponenttwo->SizeToDraw = FVector(630.0f, 30.0f, 0.0f);
			newimagecomponenttwo->Location = FVector(10.0f, 470.0f, 0.0f);
			newimagecomponenttwo->TextureToDraw = playercharacter->PlayerHUD->QuestChoiceTex;

			TheDialogue->ImageComponents.push_back(newimagecomponent);
			TheDialogue->ImageComponents.push_back(newimagecomponenttwo);

			TextWindowPart* newtextcomponent = new TextWindowPart();
			newtextcomponent->Location = FVector(45.0f, 435.0f, 0.0f);
			newtextcomponent->TextColor = FLinearColor(1.0f, 1.0f, 1.0f);
			newtextcomponent->TextContent = OptionOne;
			newtextcomponent->Font = playercharacter->PlayerHUD->VerdanaFont;

			TextWindowPart* newtextcomponenttwo = new TextWindowPart();
			newtextcomponenttwo->Location = FVector(45.0f, 475.0f, 0.0f);
			newtextcomponenttwo->TextColor = FLinearColor(1.0f, 1.0f, 1.0f);
			newtextcomponenttwo->TextContent = OptionTwo;
			newtextcomponenttwo->Font = playercharacter->PlayerHUD->VerdanaFont;

			for (int i = 0; i < TextBlock.size(); i++)
			{
				TextWindowPart* newtext = new TextWindowPart();
				newtext->Location = FVector(12.0f, i * 20.0f + 35.0f, 0.0f);
				newtext->TextColor = FLinearColor(1.0f, 1.0f, 1.0f);
				newtext->TextContent = TextBlock[i];
				newtext->Font = playercharacter->PlayerHUD->VerdanaFont;

				TheDialogue->TextComponents.push_back(newtext);
			}

			TheDialogue->TextComponents.push_back(newtextcomponent);
			TheDialogue->TextComponents.push_back(newtextcomponenttwo);

			TheDialogue->TheQuestGiver = this;

			bool alreadyexists = false;
			int existindex = 0;

			for (int i = 0; i < playercharacter->PlayerHUD->WindowVector.size(); i++)
			{
				if (playercharacter->PlayerHUD->WindowVector[i]->WindowName == QuestToGive.QuestName)
				{
					alreadyexists = true;
					existindex = i;
				}
			}

			if (!alreadyexists)
			{
				playercharacter->PlayerHUD->WindowVector.push_back(TheDialogue);

				PlaySoundAtLocation(playercharacter->PlayerHUD->QuestOpenSound, playercharacter->GetActorLocation());
			}
			else
			{
				playercharacter->PlayerHUD->WindowVector[existindex]->IsActive = true;
				playercharacter->PlayerHUD->WindowVector[existindex]->ClosingAlpha = 1.0f;
				playercharacter->PlayerHUD->WindowVector[existindex]->IsClosing = false;
			}
		}
		else
		{
			for (int i = 0; i < playercharacter->QuestList.Num(); i++)
			{
				if (playercharacter->QuestList[i].QuestType == NOQUEST)
				{
					PlaySoundAtLocation(playercharacter->PlayerHUD->QuestCloseSound, playercharacter->GetActorLocation());

					playercharacter->QuestList[i] = QuestToGive;
					HasGivenQuest = true;
					QuestState = INPROGRESS;

					FString questtext = "You have taken the quest '" + QuestToGive.QuestName + "'!";

					playercharacter->PlayerHUD->HUDAnnouncements.push_back(
						new Announcement(questtext,
						FLinearColor(1.0f, 1.0f, 0.4f),
						playercharacter->PlayerHUD->DamageFont,
						FVector(200.0f, 250.0f, 0.0f)));
					break;
				}
			}
		}
	}
	else
	{
		if (!forcecomplete)
		{
			vector<FString> TextBlock;

			FString OptionOne = "Yes, I'm ready for my adventure!";
			FString OptionTwo = "No, I'm going to enjoy the view some more.";

			if (QuestToGive.QuestID == 0)
			{
			}
			else if (QuestToGive.QuestID == 2)
			{
				OptionOne = "Take the reward. (Unlocks basic attacking)";
				OptionTwo = "I'm not ready for the reward yet.";

				TextBlock.push_back("Gingerfoot: You did it! Thank you for watering my precious plants!");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: That was... Actually much easier than I expected?");
				TextBlock.push_back("");
				TextBlock.push_back("Gingerfoot: I'm eternally grateful for what you've done! Do you have any idea how hard it is");
				TextBlock.push_back("for us sprites to get our tiny arms around a watering can?!");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: I see I see.");
				TextBlock.push_back("");
				TextBlock.push_back("Gingerfoot: Anyhow, here's your sword and shield as promised. I think you should check out the");
				TextBlock.push_back("adventurer's board. Maybe there's something on it for someone of your high caliber!");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: Will do!");
			}
			else if (QuestToGive.QuestID == 1)
			{
				OptionOne = "Take the king's training. (Unlocks skills)";
				OptionTwo = "I'm not ready for the reward yet.";

				TextBlock.push_back("Alistair: All done!");
				TextBlock.push_back("");
				TextBlock.push_back("Sprite King: You there! Are you the brave adventurer who defeated the evil sprites lurking");
				TextBlock.push_back("in our peaceful woods?");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: Yes, I certainly am!");
				TextBlock.push_back("");
				TextBlock.push_back("Sprite King: I can't believe this day has finally come! Maybe you have a chance at freeing us");
				TextBlock.push_back("all. But first, you deserve a reward for all your hard work.");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: Oh Great King, what do you have for the likes of me?");
				TextBlock.push_back("");
				TextBlock.push_back("Sprite King: Personal combat lessons from only the best and greatest, me!");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: Wow! I can't wait!");
			}
			else if (QuestToGive.QuestID == 4)
			{
				OptionOne = "Thanks for playing! (Restart the game)";
				OptionTwo = "I want to stay a while longer...";

				TextBlock.push_back("Alistair: It is done! The golem is dead!");
				TextBlock.push_back("");
				TextBlock.push_back("Sprite King: Hurray! All hail the great hero Alistair! We're finally free! The evil will now start");
				TextBlock.push_back("to dissipate.");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: Thanks for everything you've taught me. I wouldn't have been able to do it without you.");
				TextBlock.push_back("");
				TextBlock.push_back("Sprite King: You're most welcome. It's a small price to pay for our forests to finally be clean. So");
				TextBlock.push_back("what will you do now?");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: I guess I'll continue on my adventures. I feel like my story is just beginning.");
				TextBlock.push_back("");
				TextBlock.push_back("Sprite King: That may be true. I wish you the best of luck on your future journeys! Don't forget me!");
				TextBlock.push_back("");
				TextBlock.push_back("Alistair: I won't. You take care for me too, Great King.");
			}

			DialogueWindow* TheDialogue = new DialogueWindow();

			TheDialogue->WindowName = QuestToGive.QuestName + "(C)";

			TheDialogue->BaseInit(playercharacter->PlayerHUD->XButtonTex, playercharacter->PlayerHUD, playercharacter);
			TheDialogue->Init();

			ImageWindowPart* newimagecomponent = new ImageWindowPart();
			newimagecomponent->IsHoverable = true;
			newimagecomponent->SizeToDraw = FVector(630.0f, 30.0f, 0.0f);
			newimagecomponent->Location = FVector(10.0f, 430.0f, 0.0f);
			newimagecomponent->TextureToDraw = playercharacter->PlayerHUD->QuestChoiceTex;

			ImageWindowPart* newimagecomponenttwo = new ImageWindowPart();
			newimagecomponenttwo->IsHoverable = true;
			newimagecomponenttwo->SizeToDraw = FVector(630.0f, 30.0f, 0.0f);
			newimagecomponenttwo->Location = FVector(10.0f, 470.0f, 0.0f);
			newimagecomponenttwo->TextureToDraw = playercharacter->PlayerHUD->QuestChoiceTex;

			TheDialogue->ImageComponents.push_back(newimagecomponent);
			TheDialogue->ImageComponents.push_back(newimagecomponenttwo);

			TextWindowPart* newtextcomponent = new TextWindowPart();
			newtextcomponent->Location = FVector(45.0f, 435.0f, 0.0f);
			newtextcomponent->TextColor = FLinearColor(1.0f, 1.0f, 1.0f);
			newtextcomponent->TextContent = OptionOne;
			newtextcomponent->Font = playercharacter->PlayerHUD->VerdanaFont;

			TextWindowPart* newtextcomponenttwo = new TextWindowPart();
			newtextcomponenttwo->Location = FVector(45.0f, 475.0f, 0.0f);
			newtextcomponenttwo->TextColor = FLinearColor(1.0f, 1.0f, 1.0f);
			newtextcomponenttwo->TextContent = OptionTwo;
			newtextcomponenttwo->Font = playercharacter->PlayerHUD->VerdanaFont;

			for (int i = 0; i < TextBlock.size(); i++)
			{
				TextWindowPart* newtext = new TextWindowPart();
				newtext->Location = FVector(12.0f, i * 20.0f + 35.0f, 0.0f);
				newtext->TextColor = FLinearColor(1.0f, 1.0f, 1.0f);
				newtext->TextContent = TextBlock[i];
				newtext->Font = playercharacter->PlayerHUD->VerdanaFont;

				TheDialogue->TextComponents.push_back(newtext);
			}

			TheDialogue->TextComponents.push_back(newtextcomponent);
			TheDialogue->TextComponents.push_back(newtextcomponenttwo);

			TheDialogue->TheQuestGiver = this;

			bool alreadyexists = false;
			int existindex = 0;

			for (int i = 0; i < playercharacter->PlayerHUD->WindowVector.size(); i++)
			{
				if (playercharacter->PlayerHUD->WindowVector[i]->WindowName == QuestToGive.QuestName + "(C)")
				{
					alreadyexists = true;
					existindex = i;
				}
			}

			for (int i = 0; i < playercharacter->QuestList.Num(); i++)
			{
				if (playercharacter->QuestList[i].QuestName == QuestToGive.QuestName)
				{
					if (playercharacter->QuestList[i].Progress >= playercharacter->QuestList[0].Amount)
					{
						if (!alreadyexists)
						{
							playercharacter->PlayerHUD->WindowVector.push_back(TheDialogue);

							PlaySoundAtLocation(playercharacter->PlayerHUD->QuestOpenSound, playercharacter->GetActorLocation());
						}
						else
						{
							playercharacter->PlayerHUD->WindowVector[existindex]->IsActive = true;
							playercharacter->PlayerHUD->WindowVector[existindex]->ClosingAlpha = 1.0f;
							playercharacter->PlayerHUD->WindowVector[existindex]->IsClosing = false;
						}
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < playercharacter->QuestList.Num(); i++)
			{
				if (playercharacter->QuestList[i].QuestName == QuestToGive.QuestName)
				{
					if (playercharacter->QuestList[i].Progress >= playercharacter->QuestList[i].Amount)
					{
						QuestState = COMPLETED;

						if (QuestToGive.QuestType == COLLECTQUEST)
						{
							TakeItems(playercharacter);
						}

						playercharacter->QuestList[i] = FQuest();

						FString questtext = "You have completed the quest '" + QuestToGive.QuestName + "'!";

						playercharacter->QuestsCompleted++;

						playercharacter->PlayerHUD->HUDAnnouncements.push_back(
							new Announcement(questtext,
							FLinearColor(1.0f, 1.0f, 0.4f),
							playercharacter->PlayerHUD->DamageFont,
							FVector(200.0f, 250.0f, 0.0f)));

						PlaySoundAtLocation(playercharacter->PlayerHUD->QuestCloseSound, playercharacter->GetActorLocation());

						if (QuestToGive.QuestID == 2)
						{
							playercharacter->AttackUnlocked = true;
						}

						if (QuestToGive.QuestID == 1)
						{
							playercharacter->SkillsUnlocked = true;
						}

						break;
					}
				}
			}
		}
	}
}

void AQuestGiver::TakeItems(AAlistair* playercharacter)
{
	int total = QuestToGive.Amount;

	for (int i = 0; i < playercharacter->Inventory.Num(); i++)
	{
		if (playercharacter->Inventory[i].ID == QuestToGive.ContentID)
		{
			if (playercharacter->Inventory[i].Quantity >= total)
			{
				playercharacter->Inventory[i].Quantity -= total;
				break;
			}
			else
			{
				total -= playercharacter->Inventory[i].Quantity;
				playercharacter->Inventory[i].Quantity = 0;
			}
		}
	}
}