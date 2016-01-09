// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "ItemPopupWindow.h"
#include "StatusHUDTest.h"
#include "InventoryWindow.h"

void ItemPopupWindow::Draw()
{
}

void ItemPopupWindow::Init()
{
}

void ItemPopupWindow::Update()
{
	if (!IsActive && ClosingAlpha <= 0.0f)
	{
		for (vector<WindowBase*>::iterator it = HUDManager->WindowVector.begin(); it != HUDManager->WindowVector.end(); ++it) {
			if ((*it) == this) {
				HUDManager->WindowVector.erase(it);
				break;
			}
		}
	}

	if (IsActive && IsUsable)
	{
		if (UseButtonComponent->IsBeingHovered && HUDManager->ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickState == FREE)
		{
			for (int i = 0; i < PlayerCharacter->Inventory.Num(); i++)
			{
				if (PlayerInventory->ItemInfoVector[PlayerCharacter->Inventory[i].ID]->Name == WindowName && PlayerCharacter->IsAliveBase)
				{
					PlayerInventory->HandleItemUse(PlayerCharacter->Inventory[i].ID, PlayerCharacter->Inventory[i].Slot);
				}
			}
		}
	}
}