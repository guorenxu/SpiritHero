// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "TextWindowPart.h"
#include "ImageWindowPart.h"
#include "Alistair.h"
#include "Tooltip.h"

class AStatusHUDTest;

using namespace std;

/**
 * 
 */
class INDIEPROJECT_API WindowBase
{
public:
	WindowBase()
	{
		Location = FVector(0.0f, 0.0f, 0.0f);

		Size = FVector(0.0f, 0.0f, 0.0f);

		IsActive = true;

		IsClosing = false;
		ClosingAlpha = 1.0f;

		IsBeingMoved = false;

		IsTrueWindow = true;

		WindowType = TRUEWINDOW;

		ToMoveToTop = false;

		WindowName = "";
	}

	FVector Location;		//The Top-Left location of the window on the screen

	FVector Size;			//The size of the window

	bool IsActive;			//Is the window active, can the buttons be clicked and should it be drawn

	bool IsClosing;			//Is the window currently being closed
	float ClosingAlpha;		//Current alpha to draw during closing

	bool IsBeingMoved;		//Is the window being moved

	bool IsTrueWindow;		//True == has a top bar and draggable from there
							//False == has no buttons, no top bar, and draggable anywhere

	int WindowType;

	bool ToMoveToTop;		//Flag to move to top of vector for stacking reasons

	static float DeltaTime;

	FString WindowName;		//The name to display on the top bar

	vector<TextWindowPart*> TextComponents;			//A vector of all the text components
	vector<ImageWindowPart*> ImageComponents;		//A vector of all the image components

	ImageWindowPart* XButtonComponent;

	AStatusHUDTest* HUDManager;

	AAlistair* PlayerCharacter;

	void BaseInit(UTexture2D* xbuttontex, AStatusHUDTest* hudmanager, AAlistair* playercharacter);

	void BaseUpdate(float deltatime);

	virtual void Draw(){}

	virtual void Init(){}

	virtual void Update(){}
};
