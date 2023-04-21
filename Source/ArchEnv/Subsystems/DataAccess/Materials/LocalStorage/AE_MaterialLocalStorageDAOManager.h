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

	virtual void Initialize() override;
	virtual void CreateMaterial(UAE_Material* Material) override;
	virtual void DeleteMaterial(UAE_Material* Material) override;
	virtual TArray<UAE_Material*> GetAllMaterials() override;
	virtual void UpdateMaterial(UAE_Material* Material) override;

	virtual TArray<UObject*> GetItems() override;
	virtual void OnItemClicked(UObject* Item) override;
	virtual TArray<UObject*> FilterItemsByString(const FString& String) override;

protected:

	void AsyncMaterialSaveToDisk(const UAE_Material* SaveMaterial);
	void LoadMaterialsFromDataTable();
	void LoadTexturesFromImageSubsystem();
};
