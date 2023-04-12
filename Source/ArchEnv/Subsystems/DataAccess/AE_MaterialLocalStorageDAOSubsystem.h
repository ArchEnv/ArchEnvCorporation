// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AE_MaterialDAOSubsystem.h"
#include "ArchEnv/Interfaces/DataAccess/AE_MaterialDAO.h"
#include "AE_MaterialLocalStorageDAOSubsystem.generated.h"

class UAE_Material;

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_MaterialLocalStorageDAOSubsystem : public UAE_MaterialDAOSubsystem
{
	GENERATED_BODY()
public:
	UAE_MaterialLocalStorageDAOSubsystem();
	
	virtual void CreateMaterial_Implementation(UAE_Material* Material) override;
	virtual void DeleteMaterial_Implementation(UAE_Material* Material) override;
	virtual TArray<UAE_Material*> GetAllMaterials_Implementation() override;
	virtual void UpdateMaterial_Implementation(UAE_Material* Material) override;
	
};
