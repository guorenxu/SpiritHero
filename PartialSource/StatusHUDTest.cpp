// Fill out your copyright notice in the Description page of Project Settings.

#include "IndieProject.h"
#include "StatusHUDTest.h"
#include "MonsterBase.h"

// Colors 
const FColor AStatusHUDTest::FColorBlack = FColor(0, 0, 0, 255);
const FColor AStatusHUDTest::FColorRed = FColor(255, 0, 0, 255);
const FColor AStatusHUDTest::FColorYellow = FColor(255, 255, 0, 255);
const FColor AStatusHUDTest::FColorBlue = FColor(0, 0, 255, 255);
const FColor AStatusHUDTest::FColor_White = FColor(255, 255, 255, 255);
// Backgrounds 
const FLinearColor AStatusHUDTest::LC_Black = FLinearColor(0, 0, 0, 1);
const FLinearColor AStatusHUDTest::LC_Pink = FLinearColor(1, 0, 1, 1);
const FLinearColor AStatusHUDTest::LC_Red = FLinearColor(1, 0, 0, 1);
const FLinearColor AStatusHUDTest::LC_Yellow = FLinearColor(1, 1, 0, 1);

AStatusHUDTest::AStatusHUDTest(const class FPostConstructInitializeProperties& PCIP) : Super(PCIP)
{
	DefaultFontScale = 0.7;   //scaling down a size 36 font

	ConstructorHelpers::FObjectFinder<UFont> FontObject(TEXT("Font'/Game/Fonts/SegoeUIWhite16.SegoeUIWhite16'"));
	if (FontObject.Object)
	{
		VerdanaFont = FontObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UFont> DamageFontObject(TEXT("Font'/Game/Fonts/DamageFont.DamageFont'"));
	if (DamageFontObject.Object)
	{
		DamageFont = DamageFontObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> RedArrowObject(TEXT("Texture2D'/Game/ImportedStuffs/ArrowRed.ArrowRed'"));
	if (RedArrowObject.Object)
	{
		RedArrowTex = RedArrowObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> YellowArrowObject(TEXT("Texture2D'/Game/ImportedStuffs/YellowArrow.YellowArrow'"));
	if (YellowArrowObject.Object)
	{
		YellowArrowTex = YellowArrowObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> WhiteArrowObject(TEXT("Texture2D'/Game/ImportedStuffs/WhiteArrow.WhiteArrow'"));
	if (WhiteArrowObject.Object)
	{
		WhiteArrowTex = WhiteArrowObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> XButtonObject(TEXT("Texture2D'/Game/GUITextures/XButton.XButton'"));
	if (XButtonObject.Object)
	{
		XButtonTex = XButtonObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> NothingItemObject(TEXT("Texture2D'/Game/GUITextures/Nothing.Nothing'"));
	if (NothingItemObject.Object)
	{
		NothingItemTex = NothingItemObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> CoinItemObject(TEXT("Texture2D'/Game/GUITextures/Coin.Coin'"));
	if (CoinItemObject.Object)
	{
		CoinItemTex = CoinItemObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> WoodItemObject(TEXT("Texture2D'/Game/GUITextures/Wood.Wood'"));
	if (WoodItemObject.Object)
	{
		WoodItemTex = WoodItemObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> PotionItemObject(TEXT("Texture2D'/Game/GUITextures/Potion.Potion'"));
	if (PotionItemObject.Object)
	{
		PotionItemTex = PotionItemObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> UseButtonObject(TEXT("Texture2D'/Game/GUITextures/UseButton.UseButton'"));
	if (UseButtonObject.Object)
	{
		UseButtonTex = UseButtonObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> QuestAvailableObject(TEXT("Texture2D'/Game/GUITextures/QuestAvailable.QuestAvailable'"));
	if (QuestAvailableObject.Object)
	{
		QuestAvailableTex = QuestAvailableObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> QuestInProgressObject(TEXT("Texture2D'/Game/GUITextures/QuestAccepted.QuestAccepted'"));
	if (QuestInProgressObject.Object)
	{
		QuestInProgressTex = QuestInProgressObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D> QuestCompletableObject(TEXT("Texture2D'/Game/GUITextures/QuestCompletable.QuestCompletable'"));
	if (QuestCompletableObject.Object)
	{
		QuestCompletableTex = QuestCompletableObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>InventoryButtonObject(TEXT("Texture2D'/Game/GUITextures/Inventory.Inventory'"));
	if (InventoryButtonObject.Object)
	{
		InventoryButtonTex = InventoryButtonObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>QuestsButtonObject(TEXT("Texture2D'/Game/GUITextures/Quests.Quests'"));
	if (QuestsButtonObject.Object)
	{
		QuestsButtonTex = QuestsButtonObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>HelpButtonObject(TEXT("Texture2D'/Game/GUITextures/Help.Help'"));
	if (HelpButtonObject.Object)
	{
		HelpButtonTex = HelpButtonObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>AlistairFaceObject(TEXT("Texture2D'/Game/GUITextures/Alistair.Alistair'"));
	if (AlistairFaceObject.Object)
	{
		AlistairFaceTex = AlistairFaceObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>ChargeIconObject(TEXT("Texture2D'/Game/GUITextures/Charge.Charge'"));
	if (ChargeIconObject.Object)
	{
		ChargeIconTex = ChargeIconObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>WindSlashIconObject(TEXT("Texture2D'/Game/GUITextures/WindSlash.WindSlash'"));
	if (WindSlashIconObject.Object)
	{
		WindSlashIconTex = WindSlashIconObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>WaterPlantObject(TEXT("Texture2D'/Game/GUITextures/PlantWaterIcon.PlantWaterIcon'"));
	if (WaterPlantObject.Object)
	{
		WaterPlantTex = WaterPlantObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>TargetTRObject(TEXT("Texture2D'/Game/GUITextures/TargetTR.TargetTR'"));
	if (TargetTRObject.Object)
	{
		TargetTRTex = TargetTRObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>TargetTLObject(TEXT("Texture2D'/Game/GUITextures/TargetTL.TargetTL'"));
	if (TargetTLObject.Object)
	{
		TargetTLTex = TargetTLObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>TargetBLObject(TEXT("Texture2D'/Game/GUITextures/TargetBL.TargetBL'"));
	if (TargetBLObject.Object)
	{
		TargetBLTex = TargetBLObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>TargetBRObject(TEXT("Texture2D'/Game/GUITextures/TargetBR.TargetBR'"));
	if (TargetBRObject.Object)
	{
		TargetBRTex = TargetBRObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>AttackTRObject(TEXT("Texture2D'/Game/GUITextures/AttackTR.AttackTR'"));
	if (AttackTRObject.Object)
	{
		AttackTRTex = AttackTRObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>AttackTLObject(TEXT("Texture2D'/Game/GUITextures/AttackTL.AttackTL'"));
	if (AttackTLObject.Object)
	{
		AttackTLTex = AttackTLObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>AttackBLObject(TEXT("Texture2D'/Game/GUITextures/AttackBL.AttackBL'"));
	if (AttackBLObject.Object)
	{
		AttackBLTex = AttackBLObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>AttackBRObject(TEXT("Texture2D'/Game/GUITextures/AttackBR.AttackBR'"));
	if (AttackBRObject.Object)
	{
		AttackBRTex = AttackBRObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>QuestChoiceObject(TEXT("Texture2D'/Game/GUITextures/QuestChoice.QuestChoice'"));
	if (QuestChoiceObject.Object)
	{
		QuestChoiceTex = QuestChoiceObject.Object;
	}

	ConstructorHelpers::FObjectFinder<UTexture2D>ExclamationObject(TEXT("Texture2D'/Game/GUITextures/Exclamation.Exclamation'"));
	if (ExclamationObject.Object)
	{
		ExclamationTex = ExclamationObject.Object;
	}

	ConstructorHelpers::FObjectFinder<USoundCue> SSClass(TEXT("SoundCue'/Game/Sounds/144939__thesoundcatcher__swoosh-02-01__1__Cue.144939__thesoundcatcher__swoosh-02-01__1__Cue'"));

	if (SSClass.Object)
	{
		SwooshSound = SSClass.Object;
	}

	ConstructorHelpers::FObjectFinder<USoundCue> QCClass(TEXT("SoundCue'/Game/Sounds/Transcendia_Window_Close_Cue.Transcendia_Window_Close_Cue'"));

	if (QCClass.Object)
	{
		QuestCloseSound = QCClass.Object;
	}

	ConstructorHelpers::FObjectFinder<USoundCue> QOClass(TEXT("SoundCue'/Game/Sounds/Transcendia_Open_Quest_List_Cue.Transcendia_Open_Quest_List_Cue'"));

	if (QOClass.Object)
	{
		QuestOpenSound = QOClass.Object;
	}

	RandomSin = 0.0f;

	MouseDelta = FVector(0.0f, 0.0f, 0.0f);

	DeltaTime = 0.0f;

	TooltipCooldown = 1.2f;

	HasInitWindows = false;
}

void AStatusHUDTest::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	//Establish the PC
	ThePC = GetOwningPlayerController();

	HPBarWidth = 120.0f;
	HPBarHeight = 15.0f;

	int screenwidth;
	int screenheight;

	ThePC->GetViewportSize(screenwidth, screenheight);

	ScreenWidth = screenwidth;
	ScreenHeight = screenheight;

	//GEngine);

	//PlayerCharacter = Cast<AMonsterBase>(ThePC->GetControlledPawn());

	//PlayerCharacter = Cast<AMonsterBase>(GetOwningPawn());

	//How to get a ref to your custom PC
	//AYourPlayerController* YourChar = Cast<AYourPlayerController>(ThePC);
}

void AStatusHUDTest::InitWindows()
{
	PlayerStatusWindow = new StatusWindow();
	PlayerStatusWindow->BaseInit(XButtonTex, this, PlayerCharacter);
	PlayerStatusWindow->Init();
	WindowVector.push_back(PlayerStatusWindow);

	PlayerInventoryWindow = new InventoryWindow();
	PlayerInventoryWindow->BaseInit(XButtonTex, this, PlayerCharacter);
	PlayerInventoryWindow->Init();
	WindowVector.push_back(PlayerInventoryWindow);

	PlayerQuestWindow = new QuestWindow();
	PlayerQuestWindow->Location = FVector(ScreenWidth - 200.0f, 300.0f, 0.0f);

	PlayerQuestWindow->BaseInit(XButtonTex, this, PlayerCharacter);
	PlayerQuestWindow->Init();
	WindowVector.push_back(PlayerQuestWindow);

	QuestWindow::ItemInfoVector = PlayerInventoryWindow->ItemInfoVector;

	PlayerMenuWindow = new MenuWindow();
	PlayerMenuWindow->Location = FVector(-1.0f, 846.0f, 0.0f);
	PlayerMenuWindow->BaseInit(XButtonTex, this, PlayerCharacter);
	PlayerMenuWindow->Init();
	WindowVector.push_back(PlayerMenuWindow);

	PlayerHelpWindow = new HelpWindow();
	PlayerHelpWindow->BaseInit(XButtonTex, this, PlayerCharacter);
	PlayerHelpWindow->Init();
	WindowVector.push_back(PlayerHelpWindow);

	PlayerQuickbarWindow = new QuickbarWindow();
	PlayerQuickbarWindow->BaseInit(XButtonTex, this, PlayerCharacter);
	PlayerQuickbarWindow->Init();
	PlayerQuickbarWindow->ImageComponents[0]->TextureToDraw = ChargeIconTex;
	PlayerQuickbarWindow->ImageComponents[1]->TextureToDraw = WindSlashIconTex;
	WindowVector.push_back(PlayerQuickbarWindow);
}

void AStatusHUDTest::DrawHUD_Reset()
{
}

void AStatusHUDTest::PlayerInputChecks()
{
}

void AStatusHUDTest::DrawEnemyNameplates()
{
	FMinimalViewInfo viewinfo;

	GetOwningPawn()->CalcCamera(5, viewinfo);

	FVector CameraLocation = viewinfo.Location;

	FVector PlayerLocation = GetOwningPawn()->GetActorLocation();

	FVector CameraDirection = (PlayerLocation - CameraLocation);
	CameraDirection.Normalize();

	for (TActorIterator<AMonsterBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr)
		{
			if (ActorItr->IsAliveBase && FVector::Dist(ActorItr->GetActorLocation(), PlayerCharacter->GetActorLocation()) <= 4000.0f)
			{
				FVector temp = ActorItr->GetActorLocation() - CameraLocation;
				temp.Normalize();

				if (FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(temp, CameraDirection))) < 80.0f)
				{
					FVector BoxExtent;
					FVector Origin;
					ActorItr->GetActorBounds(false, Origin, BoxExtent);

					FVector TextWorldPosition = ActorItr->GetActorLocation();

					TextWorldPosition.Z += BoxExtent.Z;

					if (ActorItr->NameBase == "Ancient Golem")
					{
						TextWorldPosition.Z += 0.6f * BoxExtent.Z;
					}

					FVector TextScreenPosition = this->Project(TextWorldPosition);

					TextScreenPosition.Y -= 25.0f;

					if (ActorItr->NameBase != "Alistair")
					{
						float sizex;
						float sizey;

						GetTextSize(FString::FromInt(ActorItr->CurrentHPBase) + " / " + FString::FromInt(ActorItr->MaxHPBase),
							sizex,
							sizey,
							VerdanaFont, 0.9f);

						sizex = floorf(sizex);

						if (ActorItr->NameBase == "Ancient Golem")
						{
							TextScreenPosition.Y -= 25.0f;
						}

						DrawRect(int(TextScreenPosition.X - ((HPBarWidth + 2.0f) / 2.0f)), int(TextScreenPosition.Y - 21.0f), HPBarWidth + 2.0f, HPBarHeight + 2.0f, FLinearColor(0.0f, 0.0f, 0.0f, 1.0f));

						DrawRect(int(TextScreenPosition.X - ((HPBarWidth) / 2.0f)), int(TextScreenPosition.Y - 20.0f), HPBarWidth * (ActorItr->CurrentHPBase / ActorItr->MaxHPBase), HPBarHeight, FLinearColor(1.0f, 0.0f, 0.0f, 1.0f));

						DrawText(VerdanaFont, FString::FromInt(ActorItr->CurrentHPBase) + " / " + FString::FromInt(ActorItr->MaxHPBase), int(TextScreenPosition.X - (int(sizex) / 2)), int(TextScreenPosition.Y - 21.0f), FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), 0.9f);

						GetTextSize(ActorItr->NameBase,
							sizex,
							sizey,
							VerdanaFont, 0.9f);

						sizex = floorf(sizex);

						DrawText(VerdanaFont, ActorItr->NameBase, int(TextScreenPosition.X - (0.5f * sizex)), int(TextScreenPosition.Y - 41.0f), FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), 0.9f);
					}
					else
					{
						float sizex;
						float sizey;

						GetTextSize(FString::FromInt(ActorItr->CurrentHPBase) + " / " + FString::FromInt(ActorItr->MaxHPBase),
							sizex,
							sizey,
							VerdanaFont, 0.9f);

						sizex = floorf(sizex);

						TextWorldPosition = ActorItr->GetActorLocation();
						TextWorldPosition.Z += 220.0f;
						TextScreenPosition = this->Project(TextWorldPosition);

						if (ActorItr->CurrentHPBase < ActorItr->MaxHPBase)
						{
							DrawRect(TextScreenPosition.X - (int)((HPBarWidth + 2.0f) / 2.0f), TextScreenPosition.Y - 36.0f, HPBarWidth + 2.0f, HPBarHeight + 2.0f, FLinearColor(0.0f, 0.0f, 0.0f, 1.0f));

							DrawRect(TextScreenPosition.X - (int)((HPBarWidth) / 2.0f), TextScreenPosition.Y - 35.0f, HPBarWidth * (ActorItr->CurrentHPBase / ActorItr->MaxHPBase), HPBarHeight, FLinearColor(1.0f, 0.0f, 0.0f, 1.0f));

							DrawText(VerdanaFont, FString::FromInt(ActorItr->CurrentHPBase) + " / " + FString::FromInt(ActorItr->MaxHPBase), int(TextScreenPosition.X - (int(sizex) / 2)), int(TextScreenPosition.Y - 36.0f), FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), 0.9f); 
						}

						DrawText(VerdanaFont, ActorItr->NameBase, TextScreenPosition.X - 19.0f, TextScreenPosition.Y - 56.0f, FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), 0.9f);

						if (PlayerQuickbarWindow->IsCastingSpell)
						{
							DrawRect(TextScreenPosition.X - 50.0f, TextScreenPosition.Y - 65.0f, 100.0f, 10.0f, FLinearColor::Black);

							DrawRect(TextScreenPosition.X - 49.0f, TextScreenPosition.Y - 64.0f, 98.0f * (PlayerQuickbarWindow->CurrentCastTime / PlayerQuickbarWindow->BaseCastTime), 8.0f, FLinearColor::Gray);
						}
					}
				}
			}
		}
	}
}

void AStatusHUDTest::DrawTargetReticles()
{
	FMinimalViewInfo viewinfo;

	GetOwningPawn()->CalcCamera(5, viewinfo);

	FVector CameraLocation = viewinfo.Location;

	FVector PlayerLocation = GetOwningPawn()->GetActorLocation();

	FVector CameraDirection = (PlayerLocation - CameraLocation);
	CameraDirection.Normalize();

	for (TActorIterator<AMonsterBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr)
		{
			if (ActorItr->IsAliveBase && ActorItr->NameBase != "Alistair")
			{
				if (ActorItr->IsDestinationBase || ActorItr->IsTargetBase)
				{
					FVector temp = ActorItr->GetActorLocation() - CameraLocation;
					temp.Normalize();

					if (FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(temp, CameraDirection))) < 80.0f)
					{
						FVector BoxExtent;
						FVector Origin;
						PlayerCharacter->TargetBase->GetActorBounds(false, Origin, BoxExtent);

						FVector TextWorldPosition = PlayerCharacter->TargetBase->GetActorLocation();

						TextWorldPosition.Z += BoxExtent.Z / 1.8f;

						FVector TextScreenPosition = this->Project(TextWorldPosition);

						if (ActorItr->NameBase == "Ancient Golem")
						{
							TextScreenPosition.Y -= 20.0f;
						}

						TextScreenPosition.Y -= 13.0f;

						float BaseSeparation = 20.0f;

						float Separation = BaseSeparation;

						if (PlayerCharacter->TargetBase->CameraDistance < 5000.0f)
						{
							Separation = BaseSeparation + (((5000.0f - PlayerCharacter->TargetBase->CameraDistance) / 5000.0f) * 90.0f);
						}

						if (ActorItr->NameBase == "Ancient Golem")
						{
							Separation += 60.0f;

							Separation *= 1.2f;
						}

						if (PlayerCharacter->AttackUnlocked)
						{
							VDrawTile(AttackTLTex, (int)(TextScreenPosition.X - 15.0f - (Separation / 2.0f)), (int)(TextScreenPosition.Y - (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
							VDrawTile(AttackTRTex, (int)(TextScreenPosition.X + (Separation / 2.0f)), (int)(TextScreenPosition.Y - (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
							VDrawTile(AttackBLTex, (int)(TextScreenPosition.X - 15.0f - (Separation / 2.0f)), (int)(TextScreenPosition.Y + 20.0f + (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
							VDrawTile(AttackBRTex, (int)(TextScreenPosition.X + (Separation / 2.0f)), (int)(TextScreenPosition.Y + 20.0f + (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
						}
						else
						{
							VDrawTile(TargetTLTex, (int)(TextScreenPosition.X - 15.0f - (Separation / 2.0f)), (int)(TextScreenPosition.Y - (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
							VDrawTile(TargetTRTex, (int)(TextScreenPosition.X + (Separation / 2.0f)), (int)(TextScreenPosition.Y - (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
							VDrawTile(TargetBLTex, (int)(TextScreenPosition.X - 15.0f - (Separation / 2.0f)), (int)(TextScreenPosition.Y + 20.0f + (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
							VDrawTile(TargetBRTex, (int)(TextScreenPosition.X + (Separation / 2.0f)), (int)(TextScreenPosition.Y + 20.0f + (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
						}
					}
				}
			}
		}
	}

	if (PlayerCharacter->TargetBase != NULL)
	{
		if (!PlayerCharacter->TargetBase->IsAliveBase)
		{
			PlayerCharacter->TargetBase = NULL;
		}
		else
		{
			FVector temp = PlayerCharacter->TargetBase->GetActorLocation() - CameraLocation;
			temp.Normalize();

			if (FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(temp, CameraDirection))) < 80.0f)
			{
				FVector BoxExtent;
				FVector Origin;
				PlayerCharacter->TargetBase->GetActorBounds(false, Origin, BoxExtent);

				FVector TextWorldPosition = PlayerCharacter->TargetBase->GetActorLocation();

				TextWorldPosition.Z += BoxExtent.Z / 1.8f;

				FVector TextScreenPosition = this->Project(TextWorldPosition);

				if (PlayerCharacter->TargetBase->NameBase == "Ancient Golem")
				{
					TextScreenPosition.Y -= 20.0f;
				}

				TextScreenPosition.Y -= 13.0f;

				float BaseSeparation = 20.0f;

				float Separation = BaseSeparation;

				if (PlayerCharacter->TargetBase->CameraDistance < 5000.0f)
				{
					Separation = BaseSeparation + (((5000.0f - PlayerCharacter->TargetBase->CameraDistance) / 5000.0f) * 90.0f);
				}

				if (PlayerCharacter->TargetBase->NameBase == "Ancient Golem")
				{
					Separation += 60.0f;

					Separation *= 1.2f;
				}

				if (!PlayerCharacter->TargetBase->IsDestinationBase && !PlayerCharacter->TargetBase->IsTargetBase)
				{
					VDrawTile(TargetTLTex, (int)(TextScreenPosition.X - 15.0f - (Separation / 2.0f)), (int)(TextScreenPosition.Y - (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
					VDrawTile(TargetTRTex, (int)(TextScreenPosition.X + (Separation / 2.0f)), (int)(TextScreenPosition.Y - (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
					VDrawTile(TargetBLTex, (int)(TextScreenPosition.X - 15.0f - (Separation / 2.0f)), (int)(TextScreenPosition.Y + 20.0f + (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
					VDrawTile(TargetBRTex, (int)(TextScreenPosition.X + (Separation / 2.0f)), (int)(TextScreenPosition.Y + 20.0f + (1.2f * Separation / 2.0f)), 15.0f, 20.0f, FColor::White);
				}
			}
		}
	}
}

void AStatusHUDTest::DrawAggroIndicators()
{
	FMinimalViewInfo viewinfo;

	GetOwningPawn()->CalcCamera(5, viewinfo);

	FVector CameraLocation = viewinfo.Location;

	FVector PlayerLocation = GetOwningPawn()->GetActorLocation();

	FVector CameraDirection = (PlayerLocation - CameraLocation);
	CameraDirection.Normalize();

	for (TActorIterator<AMonsterBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr)
		{
			if (ActorItr->IsAliveBase && ActorItr->NameBase != "Alistair")
			{
				FVector temp = ActorItr->GetActorLocation() - CameraLocation;
				temp.Normalize();

				if (FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(temp, CameraDirection))) < 80.0f)
				{
					FVector BoxExtent;
					FVector Origin;
					ActorItr->GetActorBounds(false, Origin, BoxExtent);

					FVector TextWorldPosition = ActorItr->GetActorLocation();

					TextWorldPosition.Z += BoxExtent.Z;

					if (ActorItr->NameBase == "Ancient Golem")
					{
						TextWorldPosition.Z += 0.6f * BoxExtent.Z;
					}

					FVector TextScreenPosition = this->Project(TextWorldPosition);

					TextScreenPosition.Y -= 25.0f;

					if (ActorItr->CurrentAggroTimer >= 0.01f)
					{
						VDrawTile(ExclamationTex, TextScreenPosition.X + 10.0f, TextScreenPosition.Y, 50.0f, 36.0f, FLinearColor::White);
					}
				}
			}
		}
	}
}

void AStatusHUDTest::DrawControlIndicators()
{
	if (ThePC->IsInputKeyDown(EKeys::LeftControl))
	{
		AMonsterBase* controltarget = NULL;
		float closestscreendistance = 10000.0f;

		for (TActorIterator<AMonsterBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			if (ActorItr)
			{
				if (ActorItr->IsAliveBase && ActorItr->NameBase != "Alistair" && FVector::Dist(ActorItr->GetActorLocation(), PlayerCharacter->GetActorLocation()) <= 6000.0f)
				{
					FVector BoxExtent;
					FVector Origin;
					ActorItr->GetActorBounds(false, Origin, BoxExtent);

					FVector TextWorldPosition = ActorItr->GetActorLocation();

					TextWorldPosition.Z += BoxExtent.Z;

					FVector TextScreenPosition = this->Project(TextWorldPosition);

					TextScreenPosition.Y -= 10.0f;

					if (controltarget == NULL)
					{
						if (IsOnScreen(TextScreenPosition))
						{
							controltarget = *ActorItr;
							closestscreendistance = FVector::Dist(MouseLocation, TextScreenPosition);

							for (TActorIterator<AMonsterBase> ActorItrr(GetWorld()); ActorItrr; ++ActorItrr)
							{
								ActorItrr->IsControlTarget = false;
							}

							controltarget->IsControlTarget = true;
						}
					}
					else
					{
						if (IsOnScreen(TextScreenPosition))
						{
							if (FVector::Dist(MouseLocation, TextScreenPosition) < closestscreendistance)
							{
								for (TActorIterator<AMonsterBase> ActorItrr(GetWorld()); ActorItrr; ++ActorItrr)
								{
									ActorItrr->IsControlTarget = false;
								}

								controltarget = *ActorItr;
								controltarget->IsControlTarget = true;
								closestscreendistance = FVector::Dist(MouseLocation, TextScreenPosition);
							}
						}
					}
				}
			}
		}

		int count = 0;
		for (TActorIterator<AMonsterBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			if (ActorItr->IsControlTarget)
			{
				count++;
			}
		}

		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, FString::FromInt(count));

		if (controltarget)
		{
			FVector BoxExtent;
			FVector Origin;
			controltarget->GetActorBounds(false, Origin, BoxExtent);

			FVector TextWorldPosition = controltarget->GetActorLocation();

			TextWorldPosition.Z += BoxExtent.Z;

			FVector TextScreenPosition = this->Project(TextWorldPosition);

			TextScreenPosition.Y -= 10.0f;

			if (!controltarget->IsDestinationBase && !controltarget->IsTargetBase)
			{
				VDrawTile(WhiteArrowTex, TextScreenPosition.X - 25.0f, TextScreenPosition.Y - 115.0f + (FMath::Sin(RandomSin) * 9.0f), 50.0f, 50.0f, FColor::White);
			}

			FVector modifiedpos(TextScreenPosition.X, TextScreenPosition.Y + 25.0f, 0);
			
			DrawLine(FVector2D(MouseLocation), FVector2D(modifiedpos), FLinearColor::White, 1.0f);
		}
	}
	else
	{
		for (TActorIterator<AMonsterBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
		{
			if (ActorItr)
			{
				if (ActorItr->IsAliveBase && ActorItr->NameBase != "Alistair")
				{
					ActorItr->IsControlTarget = false;
				}
			}
		}
	}
}

void AStatusHUDTest::DrawQuestIndicators()
{
	FMinimalViewInfo viewinfo;

	GetOwningPawn()->CalcCamera(5, viewinfo);

	FVector CameraLocation = viewinfo.Location;

	FVector PlayerLocation = GetOwningPawn()->GetActorLocation();

	FVector CameraDirection = (PlayerLocation - CameraLocation);
	CameraDirection.Normalize();

	for (TActorIterator<AQuestGiver> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr && FVector::Dist(ActorItr->GetActorLocation(), PlayerCharacter->GetActorLocation()) <= 5000.0f)
		{
			FVector temp = ActorItr->GetActorLocation() - CameraLocation;
			temp.Normalize();

			if (FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(temp, CameraDirection))) < 80.0f)
			{
				FVector BoxExtent;
				FVector Origin;
				ActorItr->GetActorBounds(false, Origin, BoxExtent);

				FVector TextWorldPosition = ActorItr->GetActorLocation();

				TextWorldPosition.Z += BoxExtent.Z + 100.0f;

				FVector TextScreenPosition = this->Project(TextWorldPosition);

				TextScreenPosition.Y -= 10.0f;

				float sizex;
				float sizey;

				GetTextSize(ActorItr->GameName,
					sizex,
					sizey,
					VerdanaFont, 0.9f);

				sizex = floorf(sizex);

				DrawText(VerdanaFont, ActorItr->GameName, int(TextScreenPosition.X - (0.5f * sizex)), int(TextScreenPosition.Y - 10.0f), FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), 0.9f);

				for (int i = 0; i < PlayerCharacter->QuestList.Num(); i++)
				{
					if (ActorItr->QuestState != COMPLETED && ActorItr->QuestState != LOCKED)
					{
						if (!ActorItr->HasGivenQuest)
						{
							VDrawTile(QuestAvailableTex, TextScreenPosition.X - 25.0f, TextScreenPosition.Y - 60.0f, 50.0f, 50.0f, FColor::White);
						}

						if (PlayerCharacter->QuestList[i].QuestName == ActorItr->QuestToGive.QuestName)
						{
							if (PlayerCharacter->QuestList[i].Progress < PlayerCharacter->QuestList[i].Amount)
							{
								VDrawTile(QuestInProgressTex, TextScreenPosition.X - 25.0f, TextScreenPosition.Y - 60.0f, 50.0f, 50.0f, FColor::White);
							}
							else
							{
								VDrawTile(QuestCompletableTex, TextScreenPosition.X - 25.0f, TextScreenPosition.Y - 60.0f, 50.0f, 50.0f, FColor::White);
							}
						}
					}
				}
			}
		}
	}

	for (TActorIterator<AQuestObject> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr && FVector::Dist(ActorItr->GetActorLocation(), PlayerCharacter->GetActorLocation()) <= 5000.0f)
		{
			FVector temp = ActorItr->GetActorLocation() - CameraLocation;
			temp.Normalize();

			if (FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(temp, CameraDirection))) < 80.0f)
			{
				FVector BoxExtent;
				FVector Origin;
				ActorItr->GetActorBounds(false, Origin, BoxExtent);

				FVector TextWorldPosition = ActorItr->GetActorLocation();

				TextWorldPosition.Z += BoxExtent.Z + 200.0f;

				FVector TextScreenPosition = this->Project(TextWorldPosition);

				TextScreenPosition.Y -= 10.0f;

				bool found = false;

				for (int i = 0; i < PlayerCharacter->QuestList.Num(); i++)
				{
					if (PlayerCharacter->QuestList[i].QuestName == ActorItr->QuestName)
					{
						ActorItr->IsActive = true;
						found = true;
					}
				}

				if (!found)
				{
					ActorItr->IsActive = false;
				}

				if (ActorItr->IsActive && !ActorItr->IsComplete)
				{
					VDrawTile(WaterPlantTex, TextScreenPosition.X - 32.0f, TextScreenPosition.Y - 95.0f, 64.0f, 64.0f, FColor::White);
				}
			}
		}
	}
}

void AStatusHUDTest::DrawDamageText()
{
	FMinimalViewInfo viewinfo;

	GetOwningPawn()->CalcCamera(5, viewinfo);

	FVector CameraLocation = viewinfo.Location;

	FVector PlayerLocation = GetOwningPawn()->GetActorLocation();

	FVector CameraDirection = (PlayerLocation - CameraLocation);
	CameraDirection.Normalize();

	for (TActorIterator<AMonsterBase> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr)
		{
			FVector temp = ActorItr->GetActorLocation() - CameraLocation;
			temp.Normalize();

			if (FMath::RadiansToDegrees(FMath::Acos(FVector::DotProduct(temp, CameraDirection))) < 80.0f)
			{
				FVector BoxExtent;
				FVector Origin;
				ActorItr->GetActorBounds(false, Origin, BoxExtent);

				FVector TextWorldPosition = ActorItr->GetActorLocation();

				TextWorldPosition.Z += BoxExtent.Z;

				FVector TextScreenPosition = this->Project(TextWorldPosition);

				TextScreenPosition.Y -= 10.0f;

				if (ActorItr->NameBase != "Alistair")
				{
					for (int i = 0; i < ActorItr->DamageArray.Num(); i++)
					{
						DrawText(DamageFont,
							FString::FromInt(ActorItr->DamageArray[i].Amount),
							TextScreenPosition.X - 14.0f,
							TextScreenPosition.Y - 100.0f - (ActorItr->DamageArray[i].Timer * 65.0f),
							FLinearColor(1.0f, 1.0f, 1.0f, 1.0f - (ActorItr->DamageArray[i].Timer * 0.5f)),
							1.0f);
					}
				}
				else
				{
					TextWorldPosition = ActorItr->GetActorLocation();
					TextWorldPosition.Z += 220.0f;
					TextScreenPosition = this->Project(TextWorldPosition);

					for (int i = 0; i < ActorItr->DamageArray.Num(); i++)
					{
						DrawText(DamageFont,
							FString::FromInt(ActorItr->DamageArray[i].Amount),
							TextScreenPosition.X - 14.0f,
							TextScreenPosition.Y - 100.0f - (ActorItr->DamageArray[i].Timer * 65.0f),
							FLinearColor(1.0f, 1.0f, 1.0f, 1.0f - (ActorItr->DamageArray[i].Timer * 0.5f)),
							1.0f);
					}
				}
			}
		}
	}
}

void AStatusHUDTest::DrawHUD()
{
	if (!HasInitWindows)
	{
		PlayerCharacter = Cast<AAlistair>(GetOwningPawn());

		PlayerCharacter->PlayerHUD = this;

		HasInitWindows = true;
		InitWindows();

		//PlayerQuestWindow->Location = FVector(800.0f, 300.0f, 0.0f);
		//PlayerQuestWindow->Location = FVector(0, 0.0f, 0.0f);

		int screenwidth;
		int screenheight;

		ThePC->GetViewportSize(screenwidth, screenheight);

		ScreenWidth = screenwidth;
		ScreenHeight = screenheight;

		PlayerQuestWindow->Location = FVector(ScreenWidth - 200.0f, 300.0f, 0.0f);
		PlayerMenuWindow->Location = FVector(-1.0f, ScreenHeight - 54.0f, 0.0f);
	}

	int screenwidth;
	int screenheight;

	ThePC->GetViewportSize(screenwidth, screenheight);

	ScreenWidth = screenwidth;
	ScreenHeight = screenheight;

	DeltaTime = GetWorld()->TimeSeconds - LastHUDRenderTime;

	WindowBase::DeltaTime = DeltaTime;

	FVector newmouselocation(0.0f, 0.0f, 0.0f);

	ThePC->GetMousePosition(newmouselocation.X, newmouselocation.Y);

	MouseDelta = newmouselocation - MouseLocation;

	MouseLocation = newmouselocation;

	PlayerMenuWindow->Location = FVector(-1.0f, ScreenHeight - 54.0f, 0.0f);

	RefreshMouseState();

	DrawEnemyNameplates();

	DrawAggroIndicators();

	DrawQuestIndicators();

	DrawTargetReticles();

	DrawControlIndicators();

	DrawDamageText();

	CheckWindowDrag();

	CalculateWindowDrag();

	UpdateWindows();

	MoveActiveWindowToTop();

	DrawWindows();

	DrawTooltips();

	DrawAnnouncements();

	RandomSin += (GetWorld()->TimeSeconds - LastHUDRenderTime) * 8.0f;

	//DrawRect(Canvas->SizeX / 2.0f, Canvas->SizeY / 2.0f, 100.0f, 100.0f, FLinearColor(1.0f, 1.0f, 1.0f, 1.0f));

	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, FString::FromInt(PlayerCharacter->LeftClickState));

	//Unfree mouse clicks

	if (ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickState == FREE)
	{
		PlayerCharacter->LeftClickState = USED;
	}

	if (ThePC->IsInputKeyDown(EKeys::RightMouseButton) && PlayerCharacter->RightClickState == FREE)
	{
		PlayerCharacter->RightClickState = USED;
	}
}

void AStatusHUDTest::DrawWindows()
{
	for (int i = WindowVector.size() - 1; i >= 0; --i)
	{
		if (WindowVector[i]->IsActive || WindowVector[i]->ClosingAlpha > 0.0f)
		{
			if (WindowVector[i]->WindowType == TRUEWINDOW || WindowVector[i]->WindowType == BOXWINDOW || WindowVector[i]->WindowType == NOWINDOW)
			{
				//Draw the outline
				DrawRect((int)WindowVector[i]->Location.X,
					(int)WindowVector[i]->Location.Y,
					(int)WindowVector[i]->Size.X,
					(int)WindowVector[i]->Size.Y,
					FLinearColor(0.95f, 0.95f, 0.95f, WindowVector[i]->ClosingAlpha));

				//Draw the inner color
				DrawRect((int)WindowVector[i]->Location.X + 1,
					(int)WindowVector[i]->Location.Y + 1,
					(int)WindowVector[i]->Size.X - 2,
					(int)WindowVector[i]->Size.Y - 2,
					FLinearColor(0.03f, 0.03f, 0.03f, WindowVector[i]->ClosingAlpha));
			}

			//If it's a true window...
			if (WindowVector[i]->WindowType == TRUEWINDOW)
			{
				//Draw the divider line
				DrawRect((int)WindowVector[i]->Location.X,
					(int)WindowVector[i]->Location.Y + 30,
					(int)WindowVector[i]->Size.X,
					1,
					FLinearColor(0.95f, 0.95f, 0.95f, WindowVector[i]->ClosingAlpha));

				//Color the top bar depending on if its the top window
				FLinearColor barcolor = FLinearColor(0.03f, 0.03f, 0.03f, WindowVector[i]->ClosingAlpha);

				if (i == 0)
				{
					barcolor = FLinearColor(0.002f, 0.002f, 0.002f, WindowVector[i]->ClosingAlpha);
				}

				//Draw the top bar
				DrawRect((int)WindowVector[i]->Location.X + 1,
					(int)WindowVector[i]->Location.Y + 1,
					(int)WindowVector[i]->Size.X - 2,
					29,
					barcolor);

				float sizex;
				float sizey;

				GetTextSize(WindowVector[i]->WindowName,
					sizex,
					sizey,
					VerdanaFont);
				
				//Draw the window name text
				DrawText(VerdanaFont,
					WindowVector[i]->WindowName,
					(int)WindowVector[i]->Location.X + (int)(WindowVector[i]->Size.X / 2) - (int)(sizex / 2),
					(int)WindowVector[i]->Location.Y + 4,
					FLinearColor(1.0f, 1.0f, 1.0f, WindowVector[i]->ClosingAlpha),
					1.0f);
			}

			for (int j = 0; j < WindowVector[i]->ImageComponents.size(); j++)
			{
				if (WindowVector[i]->ImageComponents[j]->IsActive)
				{
					//Color the component darker if it is being hovered over (testing...)
					FLinearColor imagecolor(1.0f, 1.0f, 1.0f, WindowVector[i]->ClosingAlpha);

					if (WindowVector[i]->ImageComponents[j]->IsBeingHovered && WindowVector[i]->ImageComponents[j]->IsHoverable)
					{
						imagecolor = FLinearColor(0.7f, 0.7f, 0.7f, WindowVector[i]->ClosingAlpha);
					}

					if (WindowVector[i]->ImageComponents[j]->DrawFull)
					{
						DrawFullSizeTile(WindowVector[i]->ImageComponents[j]->TextureToDraw,
							(int)WindowVector[i]->Location.X + (int)WindowVector[i]->ImageComponents[j]->Location.X,
							(int)WindowVector[i]->Location.Y + (int)WindowVector[i]->ImageComponents[j]->Location.Y,
							imagecolor);
					}
					else
					{
						VDrawTile(WindowVector[i]->ImageComponents[j]->TextureToDraw, 
							(int)WindowVector[i]->Location.X + (int)WindowVector[i]->ImageComponents[j]->Location.X,
							(int)WindowVector[i]->Location.Y + (int)WindowVector[i]->ImageComponents[j]->Location.Y,
							(int)WindowVector[i]->ImageComponents[j]->SizeToDraw.X,
							(int)WindowVector[i]->ImageComponents[j]->SizeToDraw.Y,
							imagecolor);
					}
				}
			}

			for (int j = 0; j < WindowVector[i]->TextComponents.size(); j++)
			{
				if (WindowVector[i]->TextComponents[j]->IsActive)
				{
					if (WindowVector[i]->TextComponents[j]->IsCentered)
					{
						float sizex;
						float sizey;

						GetTextSize(WindowVector[i]->TextComponents[j]->TextContent,
							sizex,
							sizey,
							WindowVector[i]->TextComponents[j]->Font);

						FLinearColor textcolor = FLinearColor(WindowVector[i]->TextComponents[j]->TextColor);
						textcolor.A = WindowVector[i]->ClosingAlpha;

						DrawText(WindowVector[i]->TextComponents[j]->Font,
							WindowVector[i]->TextComponents[j]->TextContent,
							(int)WindowVector[i]->Location.X + (int)WindowVector[i]->TextComponents[j]->Location.X - (int)(sizex / 2),
							(int)WindowVector[i]->Location.Y + (int)WindowVector[i]->TextComponents[j]->Location.Y, // - (sizey / 2),
							textcolor,
							1.0f);
					}
					else
					{
						FLinearColor textcolor = FLinearColor(WindowVector[i]->TextComponents[j]->TextColor);
						textcolor.A = WindowVector[i]->ClosingAlpha;

						DrawText(WindowVector[i]->TextComponents[j]->Font,
							WindowVector[i]->TextComponents[j]->TextContent,
							(int)WindowVector[i]->Location.X + (int)WindowVector[i]->TextComponents[j]->Location.X,
							(int)WindowVector[i]->Location.Y + (int)WindowVector[i]->TextComponents[j]->Location.Y,
							textcolor,
							1.0f);
					}
				}
			}

			WindowVector[i]->Draw();
		}
	}
}

bool AStatusHUDTest::CheckWindowDrag()
{
	//If mouse not being pressed, clear all being moved stuff
	if (!ThePC->IsInputKeyDown(EKeys::LeftMouseButton))
	{
		for (int i = 0; i < WindowVector.size(); i++)
		{
			WindowVector[i]->IsBeingMoved = false;
		}
	}

	//If is already dragging something and mouse is still down, do nothing and just post the message
	if (PlayerCharacter->LeftClickState == DRAGGINGWINDOW && ThePC->IsInputKeyDown(EKeys::LeftMouseButton))
	{
		//Send message to character or whatever class communicates with the blueprint to prevent movement
	}
	else //if not dragging something
	{
		//Only do something if the mouse is down
		if (ThePC->IsInputKeyDown(EKeys::LeftMouseButton))
		{
			//Check all the windows
			for (int i = 0; i < WindowVector.size(); i++)
			{
				//Only allow one window to be dragged at one time
				if (PlayerCharacter->LeftClickState == FREE)
				{
					if (WindowVector[i]->IsActive)
					{
						if (WindowVector[i]->WindowType == TRUEWINDOW)
						{
							if (!WindowVector[i]->ImageComponents[0]->IsBeingHovered)
							{
								FVector topleft = WindowVector[i]->Location;
								FVector bottomright(WindowVector[i]->Location.X + WindowVector[i]->Size.X, WindowVector[i]->Location.Y + 30, 0);
								if (IsInArea(MouseLocation, topleft, bottomright))
								{
									PlayerCharacter->LeftClickState = DRAGGINGWINDOW;
									WindowVector[i]->IsBeingMoved = true;
									WindowVector[i]->ToMoveToTop = true;
								}
							}
						}
						else if (WindowVector[i]->WindowType == BOXWINDOW)
						{
							FVector topleft = WindowVector[i]->Location;
							FVector bottomright(WindowVector[i]->Location.X + WindowVector[i]->Size.X, WindowVector[i]->Location.Y + WindowVector[i]->Size.Y, 0);
							if (IsInArea(MouseLocation, topleft, bottomright))
							{
								PlayerCharacter->LeftClickState = DRAGGINGWINDOW;
								WindowVector[i]->IsBeingMoved = true;
								WindowVector[i]->ToMoveToTop = true;
							}
						}
					}
				}
			}

			//PlayerCharacter->LeftClickState = DRAGGINGWINDOW;
		}
	}

	return true;
}

void AStatusHUDTest::DrawTooltips()
{
	if (TooltipCooldown <= 0.0f)
	{
		for (int i = 0; i < WindowVector.size(); i++)
		{
			if (WindowVector[i]->IsActive)
			{
				for (int j = 0; j < WindowVector[i]->ImageComponents.size(); j++)
				{
					if (WindowVector[i]->ImageComponents[j]->IsActive && WindowVector[i]->ImageComponents[j]->IsBeingHovered && WindowVector[i]->ImageComponents[j]->Tooltips.size() >= 1)
					{
						float largesttextwidth = 0.0f;
						for (int k = 0; k < WindowVector[i]->ImageComponents[j]->Tooltips.size(); k++)
						{
							float temptextwidth;
							float temptextheight;

							GetTextSize(WindowVector[i]->ImageComponents[j]->Tooltips[k]->Content, temptextwidth, temptextheight, VerdanaFont, 1.0f);

							if (temptextwidth > largesttextwidth)
							{
								largesttextwidth = temptextwidth;
							}
						}

						DrawRect(MouseLocation.X + 20.0f,
							MouseLocation.Y,
							largesttextwidth + 20.0f,
							20.0f + WindowVector[i]->ImageComponents[j]->Tooltips.size() * 30.0f,
							FLinearColor(0.03f, 0.03f, 0.03f, 0.8f));

						for (int32 k = 0; k < WindowVector[i]->ImageComponents[j]->Tooltips.size(); k++)
						{
							float temptextwidth;
							float temptextheight;

							GetTextSize(WindowVector[i]->ImageComponents[j]->Tooltips[k]->Content, temptextwidth, temptextheight, VerdanaFont, 1.0f);

							DrawText(VerdanaFont,
								WindowVector[i]->ImageComponents[j]->Tooltips[k]->Content,
								MouseLocation.X + (0.5f * largesttextwidth) - (0.5f * temptextwidth) + 30.0f,
								MouseLocation.Y + (k * 30.0f) + 5.0f,
								WindowVector[i]->ImageComponents[j]->Tooltips[k]->Color,
								1.0f,
								false);
						}
					}
				}
			}
		}
	}
}

void AStatusHUDTest::DrawAnnouncements()
{
	for (int i = 0; i < HUDAnnouncements.size(); i++)
	{
		HUDAnnouncements[i]->Location.Y -= DeltaTime * 100.0f;
		HUDAnnouncements[i]->Color.A -= DeltaTime * 0.4f;

		float sizex;
		float sizey;

		GetTextSize(HUDAnnouncements[i]->Content, sizex, sizey, HUDAnnouncements[i]->Font);

		HUDAnnouncements[i]->Location.X = (ScreenWidth / 2.0f) - (sizex / 2.0f);
	}

	for (int i = 0; i < HUDAnnouncements.size();)
	{
		if (HUDAnnouncements[i]->Color.A <= 0.0f)
		{
			HUDAnnouncements.erase(HUDAnnouncements.begin() + i);
		}
		else
		{
			++i;
		}
	}

	for (int i = 0; i < HUDAnnouncements.size(); i++)
	{
		DrawText(HUDAnnouncements[i]->Font,
			HUDAnnouncements[i]->Content,
			HUDAnnouncements[i]->Location.X,
			HUDAnnouncements[i]->Location.Y,
			HUDAnnouncements[i]->Color,
			1.0f,
			false);
	}
}

void AStatusHUDTest::CalculateWindowDrag()
{
	for (int i = 0; i < WindowVector.size(); i++)
	{
		if (WindowVector[i]->IsBeingMoved)
		{
			WindowVector[i]->Location += MouseDelta;
		}
	}
}

void AStatusHUDTest::MoveActiveWindowToTop()
{
	for (int i = 0; i < WindowVector.size(); i++)
	{
		if (WindowVector[i]->ToMoveToTop)
		{
			WindowVector[i]->ToMoveToTop = false;
			WindowBase* temp = WindowVector[i];
			WindowVector.erase(WindowVector.begin() + i);
			WindowVector.insert(WindowVector.begin(), temp);
		}
	}
}

void AStatusHUDTest::UpdateWindows()
{
	for (int i = 0; i < WindowVector.size(); i++)
	{
		WindowVector[i]->BaseUpdate(DeltaTime);
		WindowVector[i]->Update();
	}
}

void AStatusHUDTest::RefreshMouseState()
{
	PlayerCharacter->LeftClickCooldown -= DeltaTime;
	PlayerCharacter->RightClickCooldown -= DeltaTime;

	if (PlayerCharacter->LeftClickCooldown <= 0.0f)
	{
		PlayerCharacter->LeftClickCooldown = 0.0f;
	}

	if (PlayerCharacter->RightClickCooldown <= 0.0f)
	{
		PlayerCharacter->RightClickCooldown = 0.0f;
	}

	if (!ThePC->IsInputKeyDown(EKeys::LeftMouseButton) && PlayerCharacter->LeftClickCooldown <= 0.0f)
	{
		PlayerCharacter->LeftClickState = FREE;
	}

	if (!ThePC->IsInputKeyDown(EKeys::RightMouseButton) && PlayerCharacter->RightClickCooldown <= 0.0f)
	{
		PlayerCharacter->RightClickState = FREE;
	}

	TooltipCooldown -= DeltaTime;

	if (MouseDelta.Size() != 0.0f)
	{
		TooltipCooldown = 0.7f;
	}
}

bool AStatusHUDTest::IsOnScreen(FVector testvector)
{
	if (testvector.X >= 0 && testvector.X <= ScreenWidth && testvector.Y >= 0 && testvector.Y <= ScreenHeight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool AStatusHUDTest::IsInArea(FVector testvector, FVector topleft, FVector bottomright)
{
	if (testvector.X >= topleft.X && testvector.X <= bottomright.X && testvector.Y >= topleft.Y && testvector.Y <= bottomright.Y)
	{
		return true;
	}
	else
	{
		return false;
	}
}