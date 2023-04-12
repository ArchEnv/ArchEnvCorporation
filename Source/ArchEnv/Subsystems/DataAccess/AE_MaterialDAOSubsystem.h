// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/DataAccess/AE_MaterialDAO.h"
#include "AE_MaterialDAOSubsystem.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ARCHENV_API UAE_MaterialDAOSubsystem : public UObject, public IAE_MaterialDAO
{
	GENERATED_BODY()

protected:

	UPROPERTY()
	TArray<UAE_Material*> Materials;
	
public:
	
	virtual void CreateMaterial_Implementation(UAE_Material* Material) override PURE_VIRTUAL(IAE_MaterialDAO::CreateMaterial,);
	virtual void DeleteMaterial_Implementation(UAE_Material* Material) override PURE_VIRTUAL(IAE_MaterialDAO::DeleteMaterial,);
	virtual TArray<UAE_Material*> GetAllMaterials_Implementation() override	PURE_VIRTUAL(IAE_MaterialDAO::GetAllMaterials, return Materials; ); 
	virtual void UpdateMaterial_Implementation(UAE_Material* Material) override PURE_VIRTUAL(IAE_MaterialDAO::UpdateMaterial,);
	
};
