// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/AE_GenericViewControl.h"
#include "ArchEnv/Interfaces/DataAccess/AE_MaterialDAO.h"
#include "AE_MaterialDAOManager.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ARCHENV_API UAE_MaterialDAOManager : public UObject, public IAE_MaterialDAO, public IAE_GenericViewControl
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<UAE_Material*> Materials;
};
