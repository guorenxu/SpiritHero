// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tooltip.h"
#include <vector>

using namespace std;
/**
*
*/
class INDIEPROJECT_API TextWindowPart
{
public:
	TextWindowPart()
	{
		Location = FVector(0.0f, 0.0f, 0.0f);

		IsActive = true;

		IsClosing = false;
		ClosingAlpha = 1.0f;

		TextContent = "";
		TextColor = FLinearColor::White;

		IsCentered = false;
	}

	FVector Location;			//The Top-Left location of the window on the screen

	UFont* Font;

	bool IsActive;				//Is the window active, can the buttons be clicked and should it be drawn

	bool IsClosing;				//Is the window currently being closed
	float ClosingAlpha;			//Current alpha to draw during closing

	bool IsCentered;

	vector<Tooltip*> Tooltips;	//The tooltips

	FString TextContent;		//What does the text say
	FLinearColor TextColor;		//The color of the text
};
