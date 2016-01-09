// F// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WindowBase.h"
#include "ImageWindowPart.h"
#include "TextWindowPart.h"
#include "ItemPopupWindow.h"
#include "Alistair.h"
#include <vector>

using namespace std;

class INDIEPROJECT_API InventoryWindow : public WindowBase
{
public:
	InventoryWindow() : WindowBase()
	{
		Location = FVector(20.0f, 500.0f, 0.0f);

		Size = FVector(205.0f, 235.0f, 0.0f);

		IsActive = false;

		IsClosing = false;
		ClosingAlpha = 0.0f;

		IsBeingMoved = false;

		IsTrueWindow = true;

		WindowType = TRUEWINDOW;

		WindowName = "Inventory";
	}

	vector<UTexture2D*> ItemTextures;

	vector<vector<Tooltip*>> ItemTooltips;

	vector<vector<FString*>> ItemDescriptions;

	vector<ItemInfo*> ItemInfoVector;

	void Draw();

	void Init();

	void Update();

	void HandleItemUse(int id, int slot);

	void ProcessInventory();

	void QuestUpdate();
};