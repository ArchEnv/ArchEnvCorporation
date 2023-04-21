// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/DataAccess/AE_ImageDAO.h"
#include "UObject/NoExportTypes.h"
#include "AE_ImageDAOManager.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ARCHENV_API UAE_ImageDAOManager : public UObject, public IAE_ImageDAO
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<UAE_Image*> Images;
};
