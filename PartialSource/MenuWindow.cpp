// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "MenuWindow.h"
#include "StatusHUDTest.h"

void MenuWindow::Draw()
{
}

void MenuWindow::Init()
{
	InventoryButtonComponent = new ImageWindowPart();
	InventoryButtonComponent->SizeToDraw = FVector(136.0f, 40.0f, 0.0f);
	InventoryButtonComponent->Location = FVector(20.0f, 7.0f, 0.0f);
	InventoryButtonComponent->TextureToDraw = HUDManager->InventoryButtonTex;
	InventoryButtonComponent->IsHoverable = true;

	ImageComponents.push_back(InventoryButtonComponent);

	QuestsButtonComponent = new ImageWindowPart();
	QuestsButtonComponent->SizeToDraw = FVector(136.0f, 40.0f, 0.0f);
	QuestsButtonComponent->Location = FVector(176.0f, 7.0f, 0.0f);
	QuestsButtonComponent->TextureToDraw = HUDManager->QuestsButtonTex;
	QuestsButtonComponent->IsHoverable = true;

	ImageComponents.push_back(QuestsButtonComponent);

	HelpButtonComponent = new ImageWindowPart();
	HelpButtonComponent->SizeToDraw = FVector(136.0, 40.0f, 0.0f);
	HelpButtonComponent->Location = FVector(332.0f, 7.0f, 0.0f);
	HelpButtonComponent->TextureToDraw = HUDManager->HelpButtonTex;
	HelpButtonComponent->IsHoverable = true;

	ImageComponents.push_back(HelpButtonComponent);
}

void MenuWindow::Update()
{
	if (IsActive)
	{
		if (InventoryButtonComponent->IsBeingHovered && HUDManager->ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickState == FREE)
		{
			for (int i = 0; i < HUDManager->WindowVector.size(); i++)
			{
				if (HUDManager->WindowVector[i]->WindowName == "Inventory")
				{
					HUDManager->WindowVector[i]->IsActive = true;
					HUDManager->WindowVector[i]->ClosingAlpha = 1.0f;
				}
			}
		}

		if (QuestsButtonComponent->IsBeingHovered && HUDManager->ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickState == FREE)
		{
			for (int i = 0; i < HUDManager->WindowVector.size(); i++)
			{
				if (HUDManager->WindowVector[i]->WindowName == "Quests")
				{
					HUDManager->WindowVector[i]->IsActive = true;
					HUDManager->WindowVector[i]->ClosingAlpha = 1.0f;
				}
			}
		}

		if (HelpButtonComponent->IsBeingHovered && HUDManager->ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickState == FREE)
		{
			for (int i = 0; i < HUDManager->WindowVector.size(); i++)
			{
				if (HUDManager->WindowVector[i]->WindowName == "Help")
				{
					HUDManager->WindowVector[i]->IsActive = true;
					HUDManager->WindowVector[i]->ClosingAlpha = 1.0f;
				}
			}
		}
	}
}