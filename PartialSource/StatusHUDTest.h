// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/HUD.h"
#include "WindowBase.h"
#include "StatusWindow.h"
#include "QuestWindow.h"
#include "InventoryWindow.h"
#include "ItemPopupWindow.h"
#include "MenuWindow.h"
#include "HelpWindow.h"
#include "Alistair.h"
#include "QuestGiver.h"
#include "QuickbarWindow.h"
#include "QuestObject.h"
#include "DialogueWindow.h"

#include <vector>
#include "StatusHUDTest.generated.h"

using namespace std;

/**
*
*/
UCLASS()
class INDIEPROJECT_API AStatusHUDTest : public AHUD
{
	GENERATED_UCLASS_BODY()

	/** Verdana */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UFont* VerdanaFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UFont* DamageFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* RedArrowTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* YellowArrowTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* WhiteArrowTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* XButtonTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* UseButtonTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* WoodItemTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* CoinItemTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* PotionItemTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* NothingItemTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* QuestAvailableTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* QuestInProgressTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* QuestCompletableTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* InventoryButtonTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* QuestsButtonTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* HelpButtonTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* AlistairFaceTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* ChargeIconTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* WindSlashIconTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* WaterPlantTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* TargetTRTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* TargetTLTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* TargetBRTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* TargetBLTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* AttackTRTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* AttackTLTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* AttackBRTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* AttackBLTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* QuestChoiceTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	UTexture2D* ExclamationTex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	USoundCue* SwooshSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	USoundCue* QuestOpenSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
	USoundCue* QuestCloseSound;


	/** Scale */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
		float DefaultFontScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
		float HPBarWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
		float HPBarHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
		float RandomSin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
		float ScreenWidth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MyHUD)
		float ScreenHeight;

public:
	const FLinearColor * ColorPtr;

	//Colors
	static const FColor		FColorBlack;
	static const FColor		FColorRed;
	static const FColor		FColorYellow;
	static const FColor		FColorBlue;
	static const FColor		FColor_White;

	static const FLinearColor LC_Black;
	static const FLinearColor LC_Pink;
	static const FLinearColor LC_Red;
	static const FLinearColor LC_Yellow;

	FORCEINLINE void DrawLine
		(
		const FVector2D& Start,
		const FVector2D& End,
		const FLinearColor& TheColor,
		const float& Thick
		)
	{
		if (!Canvas) return;
		//

		FCanvasLineItem NewLine(Start, End);
		NewLine.SetColor(TheColor);
		NewLine.LineThickness = Thick;
		Canvas->DrawItem(NewLine);
	}

	//~

	FORCEINLINE void DrawRect(
		float X, float Y,
		float Width, float Height,
		const FLinearColor& Color
		)
	{
		if (!Canvas) return;
		//

		FCanvasTileItem RectItem(
			FVector2D(X, Y),
			FVector2D(Width, Height),
			Color
			);

		RectItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(RectItem);
	}

	//~

	//DrawText
	FORCEINLINE void DrawText(
		UFont*	TheFont,
		const FString& TheStr,
		const float& X, const float& Y,
		const FLinearColor& TheColor,
		const float& TheScale,
		bool DrawOutline = false,
		const FLinearColor OutlineColor = FLinearColor(0, 0, 0, 1)
		) {
		if (!Canvas) return;
		//

		//Text and Font
		FCanvasTextItem NewText(
			FVector2D(X, Y),
			FText::FromString(TheStr),
			TheFont,
			TheColor
			);

		//Text Scale
		NewText.Scale.Set(TheScale, TheScale);

		//Outline gets its alpha from the main color
		NewText.bOutlined = true;
		NewText.OutlineColor = OutlineColor;
		NewText.OutlineColor.A = TheColor.A * 2;

		//Draw
		Canvas->DrawItem(NewText);
	}

	//~
	//Draw Full Size Tile
	FORCEINLINE void DrawFullSizeTile(UTexture2D* tex, float x, float y, const FColor& Color)
	{
		if (!Canvas) return;
		if (!tex) return;
		//~~

		Canvas->SetDrawColor(Color);

		//Draw
		Canvas->DrawTile(
			tex, x, y, //z pos
			tex->GetSurfaceWidth(), //screen width
			tex->GetSurfaceHeight(),  //screen height
			0, //texture start width
			0, //texture start height
			tex->GetSurfaceWidth(), //texture width from start
			tex->GetSurfaceHeight(), //texture height from start
			BLEND_Translucent);
	}

	//~

	FORCEINLINE void VDrawTile(UTexture2D* tex, float x, float y, float screenX, float screenY, const FColor& TheColor)
	{
		if (!Canvas) return;
		if (!tex) return;
		//~

		Canvas->SetDrawColor(TheColor);

		//Draw
		Canvas->DrawTile(
			tex, x, y, //z pos
			screenX, //screen width
			screenY,  //screen height
			0, //texture start width
			0, //texture start height
			tex->GetSurfaceWidth(), //texture width from start
			tex->GetSurfaceHeight(), //texture height from start
			BLEND_Translucent
			);
	}

public:
	APlayerController* ThePC;

	vector<WindowBase*> WindowVector;
	StatusWindow* PlayerStatusWindow;
	QuestWindow* PlayerQuestWindow;
	InventoryWindow* PlayerInventoryWindow;
	ItemPopupWindow* TempItemPopupWindow;
	MenuWindow* PlayerMenuWindow;
	HelpWindow* PlayerHelpWindow;
	QuickbarWindow* PlayerQuickbarWindow;

	AAlistair* PlayerCharacter;

	FVector MouseLocation;
	FVector MouseDelta;

	bool HasInitWindows;

	float TooltipCooldown;

	float DeltaTime;

	void PlayerInputChecks();

	void DrawEnemyNameplates();
	void DrawTargetReticles();

	void DrawControlIndicators();

	void DrawDamageText();

	void DrawWindows();

	void DrawTooltips();

	void DrawQuestIndicators();

	void InitWindows();

	void UpdateWindows();

	bool CheckWindowDrag();

	void CalculateWindowDrag();

	void MoveActiveWindowToTop();	//Calculate the move to top flags for windows

	void RefreshMouseState();

	void DrawAnnouncements();

	void DrawAggroIndicators();

	vector<Announcement*> HUDAnnouncements;

	bool IsOnScreen(FVector testvector);
	bool IsInArea(FVector testvector, FVector topleft, FVector bottomright);

protected:
	//Draw HUD
	void DrawHUD_Reset();
	virtual void DrawHUD() OVERRIDE;

	/** after all game elements are created */
	virtual void PostInitializeComponents() OVERRIDE;
};