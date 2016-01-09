// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WindowBase.h"
#include <vector>

class INDIEPROJECT_API QuestWindow : public WindowBase
{
public:
	QuestWindow() : WindowBase()
	{
		Location = FVector(530.0f, 350.0f, 0.0f);

		Size = FVector(190.0f, 350.0f, 0.0f);

		IsActive = false;

		IsClosing = false;
		ClosingAlpha = 0.0f;

		IsBeingMoved = false;

		IsTrueWindow = true;

		WindowType = TRUEWINDOW;

		WindowName = "Quests";
	}

	static vector<FString*> MonsterNames;

	static vector<ItemInfo*> ItemInfoVector;

	void Draw();

	void Init();

	void Update();
};