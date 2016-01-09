// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "WindowBase.h"
#include "StatusHUDTest.h"

float WindowBase::DeltaTime;

void WindowBase::BaseInit(UTexture2D* xbuttontex, AStatusHUDTest* hudmanager, AAlistair* playercharacter)
{
	HUDManager = hudmanager;

	PlayerCharacter = playercharacter;

	XButtonComponent = new ImageWindowPart();

	XButtonComponent->Location = FVector((int)(Size.X - 30),
		(int)(2),
		0);

	XButtonComponent->DrawFull = true;

	XButtonComponent->IsHoverable = true;

	XButtonComponent->Tooltips.push_back(new Tooltip("Close the window", FLinearColor(1.0f, 1.0f, 1.0f, 1.0f)));

	XButtonComponent->TextureToDraw = xbuttontex;

	XButtonComponent->SizeToDraw = FVector(XButtonComponent->TextureToDraw->GetSizeX(), XButtonComponent->TextureToDraw->GetSizeY(), 0);

	if (WindowType == TRUEWINDOW)
	{
		ImageComponents.push_back(XButtonComponent);
	}
}

void WindowBase::BaseUpdate(float deltatime)
{
	if (IsActive)
	{
		for (int i = 0; i < ImageComponents.size(); i++)
		{
			if (HUDManager->IsInArea(HUDManager->MouseLocation,
				Location + ImageComponents[i]->Location,
				Location + ImageComponents[i]->Location + ImageComponents[i]->SizeToDraw))
			{
				ImageComponents[i]->IsBeingHovered = true;
			}
			else
			{
				ImageComponents[i]->IsBeingHovered = false;
			}
		}

	}

	if (IsActive && XButtonComponent->IsBeingHovered && HUDManager->ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickState == FREE)
	{
		XButtonComponent->IsBeingHovered = false;

		IsClosing = true;
		IsActive = false;

		PlayerCharacter->LeftClickState = CLICKINGBUTTON;
	}

	if (IsClosing == true)
	{
		ClosingAlpha -= deltatime * 5.0f;
	}

	if (ClosingAlpha <= 0.0f)
	{
		IsClosing = false;
		ClosingAlpha = 0.0f;
	}

	if (!IsActive)
	{
		for (int i = 0; i < HUDManager->HitBoxMap.Num(); i++)
		{
			if (HUDManager->HitBoxMap[i].GetName() == FName(*WindowName))
			{
				HUDManager->HitBoxMap.RemoveAt(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < HUDManager->HitBoxMap.Num(); i++)
		{
			if (HUDManager->HitBoxMap[i].GetName() == FName(*WindowName))
			{
				HUDManager->HitBoxMap.RemoveAt(i);
				HUDManager->HitBoxMap.Insert(FHUDHitBox(FVector2D(Location), FVector2D(Size), FName(*WindowName), true, 0), i);
				break;
			}
		}

		HUDManager->AddHitBox(FVector2D(Location), FVector2D(Size), FName(*WindowName), true);
	}
}