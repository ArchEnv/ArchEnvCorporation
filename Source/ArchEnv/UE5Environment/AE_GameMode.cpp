// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_GameMode.h"

AAE_GameMode::AAE_GameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}
