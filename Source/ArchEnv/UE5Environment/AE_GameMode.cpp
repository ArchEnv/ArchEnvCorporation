// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_GameMode.h"

#include "AE_HUD.h"
#include "AE_PlayerController.h"

AAE_GameMode::AAE_GameMode()
{
	//Set default classes
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/UE5Environment/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	static ConstructorHelpers::FClassFinder<AHUD> HUDClassFinder(TEXT("/Game/Blueprints/UE5Environment/BP_HUD"));
	HUDClass = HUDClassFinder.Class;

	PlayerControllerClass = AAE_PlayerController::StaticClass();
}
