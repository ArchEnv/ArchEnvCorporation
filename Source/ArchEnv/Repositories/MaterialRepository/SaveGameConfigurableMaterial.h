// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Materials/AE_ConfigurableMaterial.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameConfigurableMaterial.generated.h"

/**
 * 
 */
UCLASS()
class ARCHENV_API USaveGameConfigurableMaterial : public USaveGame
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<UAE_ConfigurableMaterial*> ConfigurableMaterials;
	
};
