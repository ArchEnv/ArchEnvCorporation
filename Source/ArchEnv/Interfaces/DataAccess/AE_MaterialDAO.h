// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Materials/AE_Material.h"
#include "UObject/Interface.h"
#include "AE_MaterialDAO.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType, NotBlueprintable)
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

	UFUNCTION(BlueprintCallable)
	virtual void Initialize() PURE_VIRTUAL(IAE_MaterialDAO::Initialize,);

	UFUNCTION(BlueprintCallable)
	virtual void CreateMaterial(UAE_Material* Material) PURE_VIRTUAL(IAE_MaterialDAO::CreateMaterail,);

	UFUNCTION(BlueprintCallable)
	virtual TArray<UAE_Material*> GetAllMaterials() PURE_VIRTUAL(IAE_MaterialDAO::GetAllMaterials, return {};);

	UFUNCTION(BlueprintCallable)
	virtual void UpdateMaterial(UAE_Material* Material) PURE_VIRTUAL(IAE_MaterialDAO::UpdateMaterial,);

	UFUNCTION(BlueprintCallable)
	virtual void DeleteMaterial(UAE_Material* Material) PURE_VIRTUAL(IAE_MaterialDAO::DeleteMaterail,);
	
};
