// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Materials/AE_Material.h"
#include "UObject/Interface.h"
#include "AE_MaterialDAO.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UAE_MaterialDAO : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARCHENV_API IAE_MaterialDAO
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CreateMaterial(UAE_Material* Material);
	virtual void CreateMaterial_Implementation(UAE_Material* Material) PURE_VIRTUAL(IAE_MaterialDAO::CreateMaterial);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	TArray<UAE_Material*> GetAllMaterials();
	virtual TArray<UAE_Material*> GetAllMaterials_Implementation() PURE_VIRTUAL(IAE_MaterialDAO::GetAllMaterials, return {};);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UpdateMaterial(UAE_Material* Material);
	virtual void UpdateMaterial_Implementation(UAE_Material* Material) PURE_VIRTUAL(IAE_MaterialDAO::UpdateMaterial);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void DeleteMaterial(UAE_Material* Material);
	virtual void DeleteMaterial_Implementation(UAE_Material* Material) PURE_VIRTUAL(IAE_MaterialDAO::DeleteMaterial);
	
};
