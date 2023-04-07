// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_FirstPersonGameMode.h"
#include "UObject/ConstructorHelpers.h"

ATP_FirstPersonGameMode::ATP_FirstPersonGameMode()
	: Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
}
