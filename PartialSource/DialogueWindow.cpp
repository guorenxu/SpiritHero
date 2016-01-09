// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "DialogueWindow.h"
#include "StatusHUDTest.h"

void DialogueWindow::Draw()
{
	HUDManager->DrawRect(Location.X + 1.0f,
		Location.Y + 420.0f,
		Size.X - 1.0f,
		1.0f, FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));
}

void DialogueWindow::Init()
{
}

void DialogueWindow::Update()
{
	if (!IsActive && ClosingAlpha <= 0.0f)
	{
		for (vector<WindowBase*>::iterator it = HUDManager->WindowVector.begin(); it != HUDManager->WindowVector.end(); ++it) {
			if ((*it) == this) {
				HUDManager->WindowVector.erase(it);
				break;
			}
		}
	}

	if ((PlayerCharacter->GetActorLocation() - TheQuestGiver->GetActorLocation()).Size() >= 1000.0f)
	{
		IsActive = false;
		ClosingAlpha = 0.0f;
	}

	if (IsActive)
	{
		if (ImageComponents[1]->IsBeingHovered && HUDManager->ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickState == FREE)
		{
			IsActive = false;
			ClosingAlpha = 0.0f;

			TheQuestGiver->GiveQuest(PlayerCharacter, true);
		}

		if (ImageComponents[2]->IsBeingHovered && HUDManager->ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickState == FREE)
		{
			IsActive = false;
			ClosingAlpha = 0.0f;
		}
	}
}