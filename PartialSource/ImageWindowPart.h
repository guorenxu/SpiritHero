// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tooltip.h"
#include <vector>

using namespace std;

/**
*
*/
class INDIEPROJECT_API ImageWindowPart
{
public:
	ImageWindowPart()
	{
		Location = FVector(0.0f, 0.0f, 0.0f);

		IsActive = true;

		IsClosing = false;
		ClosingAlpha = 1.0f;

		IsCentered = false;

		IsHoverable = false;
		IsBeingHovered = false;

		TextureToDraw = NULL;
		SizeToDraw = FVector(0.0f, 0.0f, 0.0f);
		DrawFull = false;
	}

	FVector Location;		//The Top-Left location of the window on the screen

	bool IsActive;			//Is the window active, can the buttons be clicked and should it be drawn

	bool IsClosing;			//Is the window currently being closed
	float ClosingAlpha;		//Current alpha to draw during closing

	bool IsCentered;		//Draw at 0,0 or center of texture

	bool IsHoverable;		//Does it glow if you hover mouse over it
	bool IsBeingHovered;	//Is the mouse hovering over it now? Only works with ishoverable true

	vector<Tooltip*> Tooltips;	//The tooltips

	UTexture2D* TextureToDraw;	//The texture to draw
	FVector SizeToDraw;			//How large should we draw
	bool DrawFull;				//Ignore SizeToDraw and just draw full
};
