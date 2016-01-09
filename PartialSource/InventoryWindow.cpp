// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "InventoryWindow.h"
#include "StatusHUDTest.h"

void InventoryWindow::Init()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			ImageWindowPart* newimagecomponent = new ImageWindowPart();
			newimagecomponent->IsHoverable = true;
			newimagecomponent->SizeToDraw = FVector(50.0f, 50.0f, 0.0f);
			newimagecomponent->Location = FVector(1.0f + (51.0f * j), 31.0f + (51.0f * i), 0.0f);
			newimagecomponent->TextureToDraw = HUDManager->NothingItemTex;

			ImageComponents.push_back(newimagecomponent);

			TextWindowPart* newtextcomponent = new TextWindowPart();
			newtextcomponent->Location = FVector(6.0f + (51.0f * j), 32.0f + (51.0f * i), 0.0f);
			newtextcomponent->TextColor = FLinearColor(1.0f, 1.0f, 1.0f);
			newtextcomponent->Font = HUDManager->VerdanaFont;

			TextComponents.push_back(newtextcomponent);
		}
	}

	ItemTextures.push_back(HUDManager->NothingItemTex);
	ItemTextures.push_back(HUDManager->CoinItemTex);
	ItemTextures.push_back(HUDManager->WoodItemTex);
	ItemTextures.push_back(HUDManager->PotionItemTex);

	vector<Tooltip*> NothingTooltips;

	vector<Tooltip*> CoinTooltips;
	CoinTooltips.push_back(new Tooltip("Ancient Coin", FLinearColor::White));
	CoinTooltips.push_back(new Tooltip("Common Item", FLinearColor(0.5f, 0.5f, 0.5f)));

	vector<Tooltip*> WoodTooltips;
	WoodTooltips.push_back(new Tooltip("Oak Logs", FLinearColor::White));
	WoodTooltips.push_back(new Tooltip("Uncommon Item", FLinearColor(0.7f, 0.7f, 0.7f)));

	vector<Tooltip*> PotionTooltips;
	PotionTooltips.push_back(new Tooltip("Small HP Potion", FLinearColor::White));
	PotionTooltips.push_back(new Tooltip("Consumable Item", FLinearColor(1.0f, 1.0f, 1.0f)));
	PotionTooltips.push_back(new Tooltip("Restores 40 HP", FLinearColor::Red));

	ItemTooltips.push_back(NothingTooltips);
	ItemTooltips.push_back(CoinTooltips);
	ItemTooltips.push_back(WoodTooltips);
	ItemTooltips.push_back(PotionTooltips);

	vector<FString*> NothingDescription;

	vector<FString*> CoinDescription;
	CoinDescription.push_back(new FString("An old looking coin."));
	CoinDescription.push_back(new FString("Perhaps someone might"));
	CoinDescription.push_back(new FString("have a use for it."));

	vector<FString*> WoodDescription;
	WoodDescription.push_back(new FString("Some common log pieces."));
	WoodDescription.push_back(new FString("I might be able to craft"));
	WoodDescription.push_back(new FString("something out of these."));

	vector<FString*> PotionDescription;
	PotionDescription.push_back(new FString("This is a simple potion"));
	PotionDescription.push_back(new FString("that heals 40 HP when"));
	PotionDescription.push_back(new FString("used."));

	ItemDescriptions.push_back(NothingDescription);
	ItemDescriptions.push_back(CoinDescription);
	ItemDescriptions.push_back(WoodDescription);
	ItemDescriptions.push_back(PotionDescription);

	ItemInfoVector.push_back(new ItemInfo(false, ""));
	ItemInfoVector.push_back(new ItemInfo(false, "Ancient Coin"));
	ItemInfoVector.push_back(new ItemInfo(false, "Oak Logs"));
	ItemInfoVector.push_back(new ItemInfo(true, "Small HP Potion"));
}

void InventoryWindow::Draw()
{
	for (int i = 0; i < 4; i++)
	{
		HUDManager->DrawRect(Location.X + 51.0f + (i * 51.0f),
			Location.Y + 30.0f,
			1.0f,
			203.0f, FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));

		HUDManager->DrawRect(Location.X + 1.0f,
			Location.Y + 30.0f + (i * 51.0f),
			203.0f,
			1.0f, FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
	}
}

void InventoryWindow::Update()
{
	//Do special hovering update for hacking right click state
	for (int i = 0; i < PlayerCharacter->Inventory.Num(); i++)
	{
		if (ImageComponents[i + 1]->IsBeingHovered && PlayerCharacter->RightClickState == FREE)
		{
			PlayerCharacter->RightClickState = HOVERINGBUTTON;
		}
	}

	for (int i = 0; i < PlayerCharacter->Inventory.Num(); i++)
	{
		ImageComponents[i + 1]->TextureToDraw = ItemTextures[PlayerCharacter->Inventory[i].ID];
		ImageComponents[i + 1]->Tooltips = ItemTooltips[PlayerCharacter->Inventory[i].ID];

		if (PlayerCharacter->Inventory[i].Quantity != 0)
		{
			TextComponents[i]->TextContent = FString::FromInt(PlayerCharacter->Inventory[i].Quantity);
		}
		else
		{
			TextComponents[i]->TextContent = "";
		}
	}

	for (int i = 0; i < PlayerCharacter->Inventory.Num(); i++)
	{
		if (ImageComponents[i + 1]->IsBeingHovered && HUDManager->ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickState == FREE && PlayerCharacter->Inventory[i].ID != NOTHING)
		{
			bool windowexists = false;
			for (int j = 0; j < HUDManager->WindowVector.size(); j++)
			{
				if (HUDManager->WindowVector[j]->WindowName == ItemTooltips[PlayerCharacter->Inventory[i].ID][0]->Content)
				{
					windowexists = true;
				}
			}

			if (!windowexists)
			{
				PlayerCharacter->LeftClickState = CLICKINGBUTTON;

				ItemPopupWindow* newwindow = new ItemPopupWindow(ItemInfoVector[PlayerCharacter->Inventory[i].ID]->IsUsable);

				newwindow->BaseInit(XButtonComponent->TextureToDraw, HUDManager, PlayerCharacter);
				newwindow->Init();

				newwindow->WindowName = ItemTooltips[PlayerCharacter->Inventory[i].ID][0]->Content;
				newwindow->Location = FVector(HUDManager->MouseLocation.X + 100.0f, HUDManager->MouseLocation.Y, 0.0f);

				ImageWindowPart* itemimagepart = new ImageWindowPart();
				itemimagepart->Location = FVector((newwindow->Size.X / 2.0f) - 25.0f, 40.0f, 0.0f);
				itemimagepart->SizeToDraw = FVector(50.0f, 50.0f, 0.0f);
				itemimagepart->IsHoverable = false;
				itemimagepart->TextureToDraw = ImageComponents[i + 1]->TextureToDraw;

				newwindow->ImageComponents.push_back(itemimagepart);

				float largestsizex = 0.0f;

				for (int j = 0; j < ItemDescriptions[PlayerCharacter->Inventory[i].ID].size(); j++)
				{
					float sizex;
					float sizey;
					HUDManager->GetTextSize(*ItemDescriptions[PlayerCharacter->Inventory[i].ID][j],
						sizex,
						sizey,
						HUDManager->VerdanaFont);

					if (sizex > largestsizex)
					{
						largestsizex = sizex;
					}
				}

				for (int j = 0; j < ItemDescriptions[PlayerCharacter->Inventory[i].ID].size(); j++)
				{
					TextWindowPart* itemdescpart = new TextWindowPart();
					itemdescpart->Font = HUDManager->VerdanaFont;
					itemdescpart->TextColor = FLinearColor::White;
					itemdescpart->Location = FVector((newwindow->Size.X / 2.0f) - (largestsizex / 2.0f), 100.0f + j * 21.0f, 0.0f);
					itemdescpart->TextContent = *ItemDescriptions[PlayerCharacter->Inventory[i].ID][j];

					newwindow->TextComponents.push_back(itemdescpart);
				}

				if (newwindow->IsUsable)
				{
					ImageWindowPart* usebuttonpart = new ImageWindowPart();
					usebuttonpart->Location = FVector((newwindow->Size.X / 2.0f) - 30.0f, 190.0f, 0.0f);
					usebuttonpart->SizeToDraw = FVector(60.0f, 30.0f, 0.0f);
					usebuttonpart->IsHoverable = true;
					usebuttonpart->TextureToDraw = HUDManager->UseButtonTex;

					newwindow->ImageComponents.push_back(usebuttonpart);

					newwindow->UseButtonComponent = usebuttonpart;
				}

				newwindow->PlayerInventory = this;

				newwindow->ToMoveToTop = true;

				HUDManager->WindowVector.push_back(newwindow);
			}
		}

		if (ImageComponents[i + 1]->IsBeingHovered && HUDManager->ThePC->IsInputKeyDown(EKeys::RightMouseButton) && PlayerCharacter->Inventory[i].ID != NOTHING)
		{
			if (PlayerCharacter->RightClickState == FREE || PlayerCharacter->RightClickState == HOVERINGBUTTON && PlayerCharacter->IsAliveBase)
			{
				HandleItemUse(PlayerCharacter->Inventory[i].ID, i);
				PlayerCharacter->RightClickState = CLICKINGBUTTON;
			}
		}
	}

	ProcessInventory();

	QuestUpdate();
}

void InventoryWindow::HandleItemUse(int id, int slot)
{
	if (ItemInfoVector[id]->IsUsable == true)
	{
		switch (id)
		{
		case POTION:
			if (PlayerCharacter->CurrentHPBase != PlayerCharacter->MaxHPBase)
			{
				PlayerCharacter->Inventory[slot].Quantity--;
				PlayerCharacter->CurrentHPBase += 40.0f;
				if (PlayerCharacter->CurrentHPBase > PlayerCharacter->MaxHPBase)
				{
					PlayerCharacter->CurrentHPBase = PlayerCharacter->MaxHPBase;
				}
				float sizex;
				float sizey;

				HUDManager->GetTextSize("Used an HP Potion : +40 HP", sizex, sizey, HUDManager->DamageFont);

				HUDManager->HUDAnnouncements.push_back(new Announcement("Used an HP Potion : +40 HP",
					FLinearColor(0.7f, 1.0f, 0.7f, 1.0f),
					HUDManager->DamageFont,
					FVector((HUDManager->ScreenWidth / 2.0f) - (sizex / 2.0f), 250.0f, 0.0f)));
			}
			else
			{
				float sizex;
				float sizey;

				HUDManager->GetTextSize("Your HP is already full", sizex, sizey, HUDManager->DamageFont);

				HUDManager->HUDAnnouncements.push_back(new Announcement("Your HP is already full",
					FLinearColor(1.0f, 0.8f, 0.8f, 1.0f),
					HUDManager->DamageFont,
					FVector((HUDManager->ScreenWidth / 2.0f) - (sizex / 2.0f), 250.0f, 0.0f)));
			}
			break;
		default:
			break;
		}
	}
}

void InventoryWindow::ProcessInventory()
{
	bool isclear = false;

	while (!isclear)
	{
		for (int i = 0; i < PlayerCharacter->Inventory.Num(); i++)
		{
			if (PlayerCharacter->Inventory[i].Quantity == 0 && PlayerCharacter->Inventory[i].ID != NOTHING)
			{
				FItem newitem = FItem();
				newitem.Slot = PlayerCharacter->Inventory.Num();

				PlayerCharacter->Inventory.RemoveAt(i);
				PlayerCharacter->Inventory.Push(newitem);

				break;
			}

			if (i == PlayerCharacter->Inventory.Num() - 1)
			{
				isclear = true;
			}
		}
	}
}

void InventoryWindow::QuestUpdate()
{
	//Compare all quests with items in the inventory
	for (int i = 0; i < PlayerCharacter->QuestList.Num(); i++)
	{
		if (PlayerCharacter->QuestList[i].QuestType == COLLECTQUEST)
		{
			int total = 0;

			for (int j = 0; j < PlayerCharacter->Inventory.Num(); j++)
			{
				//If match is found, add to the total in case of multiple stacks of the item
				if (PlayerCharacter->QuestList[i].ContentID == PlayerCharacter->Inventory[j].ID)
				{
					total += PlayerCharacter->Inventory[j].Quantity;
				}
			}

			//Set the progress as total
			PlayerCharacter->QuestList[i].Progress = total;
		}
	}
}