// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WindowBase.h"

/**
 * 
 */
class INDIEPROJECT_API HelpWindow : public WindowBase
{
public:
	HelpWindow() : WindowBase()
	{
		Location = FVector(400.0f, 400.0f, 0.0f);

		Size = FVector(350.0f,250.0f, 0.0f);

		IsActive = false;

		IsClosing = false;
		ClosingAlpha = 0.0f;

		IsBeingMoved = false;

		IsTrueWindow = true;

		WindowType = TRUEWINDOW;

		WindowName = "Help";
	}

	void Draw();

	void Init();

	void Update();
};
