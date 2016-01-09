#pragma once

#include "WindowBase.h"

class InventoryWindow;

class INDIEPROJECT_API ItemPopupWindow : public WindowBase
{
public:
	ItemPopupWindow(bool isusable) : WindowBase()
	{
		Location = FVector(200.0f, 550.0f, 0.0f);

		IsUsable = isusable;

		if (!isusable)
		{
			Size = FVector(180.0f, 200.0f, 0.0f);
		}
		else
		{
			Size = FVector(180.0f, 235.0f, 0.0f);
		}

		IsActive = true;

		IsClosing = false;
		ClosingAlpha = 1.0f;

		IsBeingMoved = false;

		IsTrueWindow = true;

		WindowType = TRUEWINDOW;

		WindowName = "Item Name";
	}

	InventoryWindow* PlayerInventory;

	ImageWindowPart* UseButtonComponent;

	bool IsUsable;

	void Draw();

	void Init();

	void Update();
};