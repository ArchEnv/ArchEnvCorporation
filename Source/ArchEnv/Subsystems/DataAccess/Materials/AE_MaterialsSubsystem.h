// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AE_MaterialsSubsystem.generated.h"

class UAE_MaterialDAOManager;
/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_MaterialsSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	UAE_MaterialsSubsystem();

	UFUNCTION(BlueprintCallable)
	UAE_MaterialDAOManager* GetMaterialDaoManager() const;
	
protected:

	UPROPERTY()
	UAE_MaterialDAOManager* MaterialDAOManager;
};
