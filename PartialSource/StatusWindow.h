// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WindowBase.h"

/**
 * 
 */
class INDIEPROJECT_API StatusWindow : public WindowBase
{
public:
	StatusWindow() : WindowBase()
	{
		Location = FVector(20.0f, 20.0f, 0.0f);

		Size = FVector(280.0f, 80.0f, 0.0f);

		IsActive = true;

		IsClosing = false;
		ClosingAlpha = 1.0f;

		IsBeingMoved = false;

		IsTrueWindow = false;

		WindowType = BOXWINDOW;

		WindowName = "Character Status";
	}

	void Draw();

	void Init();

	void Update();
};