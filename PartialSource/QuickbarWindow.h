// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "WindowBase.h"
#include "MonsterBase.h"
#include "Item.h"
#include <Vector.h>

using namespace std;

/**
*
*/
class INDIEPROJECT_API QuickbarWindow : public WindowBase
{
public:
	QuickbarWindow() : WindowBase()
	{
		Location = FVector(530.0f, 700.0f, 0.0f);

		Size = FVector(542.0f, 56.0f, 0.0f);

		IsActive = true;

		IsClosing = false;
		ClosingAlpha = 1.0f;

		IsBeingMoved = false;

		IsTrueWindow = false;

		WindowType = BOXWINDOW;

		WindowName = "Quickbar Window";
	}

	vector<FAbility> AbilityVector;

	bool IsCastingSpell;
	int SpellID;
	float CurrentCastTime;
	float BaseCastTime;
	AMonsterBase* Target;

	void Draw();

	void Init();

	void Update();

	void WaterPlant();

	void CastSpell(int id);
};