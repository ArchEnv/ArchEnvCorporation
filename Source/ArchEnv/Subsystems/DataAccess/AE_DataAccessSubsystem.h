// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AE_DataAccessSubsystem.generated.h"

class UAE_MaterialDAOManager;
class UAE_ImageDAOManager;

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_DataAccessSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UPROPERTY()
	UAE_MaterialDAOManager* MaterialDAOManager;

	UPROPERTY()
	UAE_ImageDAOManager* ImagesDAOManager;
	
public:

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable)
	UAE_MaterialDAOManager* GetMaterialsDAOManager() const;

	UFUNCTION(BlueprintCallable)
	UAE_ImageDAOManager* GetImagesDAOManager() const;
};
