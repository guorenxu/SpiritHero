// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "StatusWindow.h"

#include "StatusHUDTest.h"
#include "Alistair.h"

void StatusWindow::Draw()
{
	HUDManager->DrawFullSizeTile(HUDManager->AlistairFaceTex,
		Location.X + 5.0f, Location.Y + 5.0f, FColor::White);

	HUDManager->DrawText(HUDManager->DamageFont,
		"Alistair",
		Location.X + 150.0f,
		Location.Y + 2.0f,
		FLinearColor::White,
		0.4f);

	HUDManager->DrawRect(Location.X + 85.0f,
		Location.Y + 48.0f,
		185.0f,
		20.0f,
		FLinearColor::White);

	HUDManager->DrawRect(Location.X + 86.0f,
		Location.Y + 49.0f,
		183.0f,
		18.0f,
		FLinearColor::Black);

	HUDManager->DrawRect(Location.X + 86.0f,
		Location.Y + 49.0f,
		(PlayerCharacter->CurrentHPBase / PlayerCharacter->MaxHPBase) * 183.0f,
		18.0f,
		FLinearColor::Red);

	FString HPString = "";

	HPString += FString::FromInt(int(PlayerCharacter->CurrentHPBase)) + FString(" / ");
	HPString += FString::FromInt(int(PlayerCharacter->MaxHPBase));

	float sizex;
	float sizey;

	HUDManager->GetTextSize(HPString,
		sizex,
		sizey,
		HUDManager->DamageFont, 0.3f);

	HUDManager->DrawText(HUDManager->DamageFont,
		HPString,
		Location.X + 85.0f + 95.0f - (sizex / 2.0f),
		Location.Y + 50.0f,
		FLinearColor::White,
		0.3f);
}

void StatusWindow::Init()
{
}

void StatusWindow::Update()
{
}