// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AE_ImagesSubsystem.generated.h"

class UAE_ImageDAOManager;
/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_ImagesSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UAE_ImagesSubsystem();

	UFUNCTION(BlueprintCallable)
	UAE_ImageDAOManager* GetImageDAOManager();

protected:

	UPROPERTY()
	UAE_ImageDAOManager* ImageDAOManager;
	
};
