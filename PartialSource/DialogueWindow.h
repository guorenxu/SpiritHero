// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WindowBase.h"
#include "QuestGiver.h"

/**
*
*/
class INDIEPROJECT_API DialogueWindow : public WindowBase
{
public:
	DialogueWindow() : WindowBase()
	{
		Location = FVector(300.0f, 200.0f, 0.0f);

		Size = FVector(650.0f, 510.0f, 0.0f);

		IsActive = true;

		IsClosing = false;
		ClosingAlpha = 1.0f;

		IsBeingMoved = false;

		IsTrueWindow = true;

		WindowType = TRUEWINDOW;

		WindowName = "Dialogue";
	}

	AQuestGiver* TheQuestGiver;

	void Draw();

	void Init();

	void Update();
};
