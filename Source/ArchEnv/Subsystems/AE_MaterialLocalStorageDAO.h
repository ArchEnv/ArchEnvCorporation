// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/DataAccess/AE_MaterialDAO.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AE_MaterialLocalStorageDAO.generated.h"

class UAE_Material;

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_MaterialLocalStorageDAO : public UGameInstanceSubsystem
{
public:
	

private:
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<UAE_Material*> Materials;

};
