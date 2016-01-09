/// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "QuickbarWindow.h"

#include "StatusHUDTest.h"
#include "Alistair.h"

void QuickbarWindow::Draw()
{
	for (int i = 0; i < 10; i++)
	{
		if (AbilityVector[i].BaseCooldown > 0.1f)
		{
			HUDManager->DrawRect(Location.X + 3.0f + (54.0f * i), Location.Y + 3.0f, 50.0f, AbilityVector[i].CurrentCooldown / AbilityVector[i].BaseCooldown * 50.0f, FLinearColor(0.0f, 0.0f, 0.0f, 0.4f));

			if (AbilityVector[i].CurrentCooldown > 0)
			{
				HUDManager->DrawRect(Location.X + 3.0f + (54.0f * i), Location.Y + 3.0f, 50.0f, 50.0f, FLinearColor(0.0f, 0.0f, 0.0f, 0.2f));
			}
		}
	}
}

void QuickbarWindow::Init()
{
	for (int i = 0; i < 10; i++)
	{
		ImageWindowPart* newimagecomponent = new ImageWindowPart();
		newimagecomponent->IsHoverable = false;
		newimagecomponent->SizeToDraw = FVector(50.0f, 50.0f, 0.0f);
		newimagecomponent->Location = FVector(3.0f + (54.0f * i), 3.0f, 0.0f);
		newimagecomponent->TextureToDraw = HUDManager->NothingItemTex;

		if (i == 0)
		{
			newimagecomponent->Tooltips.push_back(new Tooltip("Blink Attack", FLinearColor::White));
		}
		else if (i == 1)
		{
			newimagecomponent->Tooltips.push_back(new Tooltip("Wind Slash", FLinearColor::White));
		}

		ImageComponents.push_back(newimagecomponent);

		TextWindowPart* newtextcomponent = new TextWindowPart();
		newtextcomponent->Location = FVector(8.0f + (54.0f * i), 5.0f, 0.0f);
		newtextcomponent->TextColor = FLinearColor(1.0f, 1.0f, 1.0f);
		newtextcomponent->Font = HUDManager->VerdanaFont;
		newtextcomponent->TextContent = FString::FromInt(i + 1);

		if (i == 9)
		{
			newtextcomponent->TextContent = FString::FromInt(0);
		}

		TextComponents.push_back(newtextcomponent);
	}

	for (int i = 0; i < 10; i++)
	{
		AbilityVector.push_back(FAbility());
	}

	AbilityVector[0].BaseCooldown = 10.0f;
	AbilityVector[0].WindupTime = 0.5f;

	AbilityVector[1].BaseCooldown = 25.0f;
	AbilityVector[1].WindupTime = 1.5f;

	IsCastingSpell = false;
	SpellID = 0;
	CurrentCastTime = 0.0f;
	BaseCastTime = 0.0f;
}

void QuickbarWindow::Update()
{
	if (!PlayerCharacter->SkillsUnlocked)
	{
		IsActive = false;
		ClosingAlpha = 0.0f;
	}
	else
	{
		if (PlayerCharacter->IsAliveBase)
		{
			IsActive = true;
			ClosingAlpha = 1.0f;

			for (int i = 0; i < 10; i++)
			{
				AbilityVector[i].CurrentCooldown -= WindowBase::DeltaTime;

				if (AbilityVector[i].CurrentCooldown < 0.0f)
				{
					AbilityVector[i].CurrentCooldown = 0.0f;
				}
			}

			if (!IsCastingSpell && PlayerCharacter->PlayerStunDurationBase <= 0.0f)
			{
				if (HUDManager->ThePC->IsInputKeyDown(EKeys::One) && AbilityVector[0].CurrentCooldown <= 0.0f)
				{
					if (PlayerCharacter->TargetBase != NULL)
					{
						if ((PlayerCharacter->GetActorLocation() - PlayerCharacter->TargetBase->GetActorLocation()).Size() <= 3200.0f)
						{
							IsCastingSpell = true;
							PlayerCharacter->UsingAbility = true;
							SpellID = 1;
							CurrentCastTime = AbilityVector[0].WindupTime;
							BaseCastTime = AbilityVector[0].WindupTime;
							Target = PlayerCharacter->TargetBase;
							PlayerCharacter->SpellTargetBase = Target;
						}
					}
				}

				if (HUDManager->ThePC->IsInputKeyDown(EKeys::Two) && AbilityVector[1].CurrentCooldown <= 0.0f)
				{
					if (PlayerCharacter->TargetBase != NULL)
					{
						if ((PlayerCharacter->GetActorLocation() - PlayerCharacter->TargetBase->GetActorLocation()).Size() <= 3200.0f)
						{
							IsCastingSpell = true;
							PlayerCharacter->UsingAbility = true;
							SpellID = 2;
							CurrentCastTime = AbilityVector[1].WindupTime;
							BaseCastTime = AbilityVector[1].WindupTime;
							Target = PlayerCharacter->TargetBase;
							PlayerCharacter->SpellTargetBase = Target;

							PlayerCharacter->AnimationFlag = 4;
						}
					}
				}
			}
		}
	}

	if (IsCastingSpell)
	{
		CurrentCastTime -= DeltaTime;

		if (CurrentCastTime <= 0.0f && PlayerCharacter->IsAliveBase)
		{
			CastSpell(SpellID);

			SpellID = 0;
			BaseCastTime = 0.0f;
			CurrentCastTime = 0.0f;
			IsCastingSpell = false;
			PlayerCharacter->UsingAbility = false;
		}

		if (PlayerCharacter->PlayerStunDurationBase >= 0.0f)
		{
			SpellID = 0;
			BaseCastTime = 0.0f;
			CurrentCastTime = 0.0f;
			IsCastingSpell = false;
			PlayerCharacter->UsingAbility = false;
		}
	}
}

void QuickbarWindow::WaterPlant()
{
	IsCastingSpell = true;
	PlayerCharacter->UsingAbility = true;
	SpellID = 100;
	CurrentCastTime = 1.5f;
	BaseCastTime = 1.5f;
	PlayerCharacter->AnimationFlag = 2;
	PlayerCharacter->SpellTargetBase = NULL;
}

void QuickbarWindow::CastSpell(int id)
{
	if (id == 1)
	{
		AbilityVector[0].CurrentCooldown = AbilityVector[0].BaseCooldown;

		PlayerCharacter->MoveTargetBase = Target;

		Target->IsDestinationBase = true;

		PlayerCharacter->TargetBase = Target;

		PlayerCharacter->StateChangeFlag = true;

		PlayerCharacter->GetCharacterMovement()->MaxWalkSpeed = 12000.0f;
		PlayerCharacter->GetCharacterMovement()->MaxAcceleration = 200000.0f;

		PlayerCharacter->AnimationFlag = 3;

		//FVector directiondifference = Target->GetActorLocation() - PlayerCharacter->GetActorLocation();

		//directiondifference.Normalize();

		//FVector newlocation = Target->GetActorLocation() - 160.0f * directiondifference;
		//newlocation.Z = Target->GetActorLocation().Z;

		//PlayerCharacter->SetActorLocation(newlocation);
	}
	else if (id == 2)
	{
		AbilityVector[1].CurrentCooldown = AbilityVector[1].BaseCooldown;

		PlayerCharacter->SpawnProjectileFlag = true;

		PlayerCharacter->AnimationFlag = 1;

		PlayerCharacter->PlaySoundAtLocation(HUDManager->SwooshSound, PlayerCharacter->GetActorLocation());
	}
	else if (id == 100)
	{
		PlayerCharacter->AnimationFlag = 1;
	}
}