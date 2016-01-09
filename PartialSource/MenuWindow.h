// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WindowBase.h"

/**
*
*/
class INDIEPROJECT_API MenuWindow : public WindowBase
{
public:
	MenuWindow() : WindowBase()
	{
		Location = FVector(20.0f, 20.0f, 0.0f);

		Size = FVector(1602.0f, 80.0f, 0.0f);

		IsActive = true;

		IsClosing = false;
		ClosingAlpha = 1.0f;

		IsBeingMoved = false;

		IsTrueWindow = false;

		WindowType = NOWINDOW;

		WindowName = "Main Menu";
	}

	ImageWindowPart* InventoryButtonComponent;
	ImageWindowPart* QuestsButtonComponent;
	ImageWindowPart* HelpButtonComponent;

	void Draw();

	void Init();

	void Update();
};