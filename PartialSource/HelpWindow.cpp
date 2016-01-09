// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "HelpWindow.h"
#include "StatusHUDTest.h"

void HelpWindow::Draw()
{
	HUDManager->DrawText(HUDManager->VerdanaFont,
		"Right-click and drag to rotate the camera",
		Location.X + 10.0f,
		Location.Y + 35.0f,
		FLinearColor::White,
		1.0f);

	HUDManager->DrawText(HUDManager->VerdanaFont,
		"Mouse wheel to zoom camera in and out",
		Location.X + 10.0f,
		Location.Y + 55.0f,
		FLinearColor::White,
		1.0f);

	HUDManager->DrawText(HUDManager->VerdanaFont,
		"Left-click on ground to move",
		Location.X + 10.0f,
		Location.Y + 75.0f,
		FLinearColor::White,
		1.0f);

	HUDManager->DrawText(HUDManager->VerdanaFont,
		"Left-click on monsters to target (once unlocked)",
		Location.X + 10.0f,
		Location.Y + 95.0f,
		FLinearColor::White,
		1.0f);

	HUDManager->DrawText(HUDManager->VerdanaFont,
		"Hold CTRL for easier monster targeting",
		Location.X + 10.0f,
		Location.Y + 115.0f,
		FLinearColor::White,
		1.0f);

	HUDManager->DrawText(HUDManager->VerdanaFont,
		"The first click targets, the second orders an attack",
		Location.X + 10.0f,
		Location.Y + 135.0f,
		FLinearColor::White,
		1.0f);

	HUDManager->DrawText(HUDManager->VerdanaFont,
		"Press '1' or '2' to use your skills (once unlocked)",
		Location.X + 10.0f,
		Location.Y + 155.0f,
		FLinearColor::White,
		1.0f);

	HUDManager->DrawText(HUDManager->VerdanaFont,
		"Skills require a target within range",
		Location.X + 10.0f,
		Location.Y + 175.0f,
		FLinearColor::White,
		1.0f);

	HUDManager->DrawText(HUDManager->VerdanaFont,
		"Open the quest window to show quest location indicator",
		Location.X + 10.0f,
		Location.Y + 195.0f,
		FLinearColor::White,
		1.0f);

	HUDManager->DrawText(HUDManager->VerdanaFont,
		"Press 'U' to reload the game if you died or are stuck",
		Location.X + 10.0f,
		Location.Y + 225.0f,
		FLinearColor::White,
		1.0f);
}

void HelpWindow::Init()
{
}

void HelpWindow::Update()
{
}