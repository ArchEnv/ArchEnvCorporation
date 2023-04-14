// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/DataAccess/AE_MaterialDAO.h"
#include "ArchEnv/Subsystems/DataAccess/Materials/AE_MaterialDAOManager.h"
#include "AE_MaterialLocalStorageDAOManager.generated.h"

class UAE_MaterialLocalStoragePathsSGO;
class UAE_Material;

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_MaterialLocalStorageDAOManager : public UAE_MaterialDAOManager
{
	GENERATED_BODY()
public:
	UAE_MaterialLocalStorageDAOManager();
	
	virtual void CreateMaterial_Implementation(UAE_Material* Material) override;
	virtual void DeleteMaterial_Implementation(UAE_Material* Material) override;
	virtual TArray<UAE_Material*> GetAllMaterials_Implementation() override;
	virtual void UpdateMaterial_Implementation(UAE_Material* Material) override;

	virtual TArray<UObject*> GetItems_Implementation() override;
	virtual void OnItemClicked_Implementation(UObject* Item) override;
	virtual TArray<UObject*> FilterItemsByString_Implementation(const FString& String) override;

protected:

	void AsyncMaterialSaveToDisk(const UAE_Material* SaveMaterial);
	
};
