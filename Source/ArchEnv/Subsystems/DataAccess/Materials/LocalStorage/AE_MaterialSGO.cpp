// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_MaterialSGO.h"

#include "ArchEnv/Materials/AE_Material.h"

void UAE_MaterialSGO::SetSaveMaterial(const UAE_Material* SaveMaterial )
{
	Id = SaveMaterial->GetMaterialId();
	MaterialName = SaveMaterial->GetMaterialName();

	SaveSlotName = SaveMaterial->GetMaterialId();
	UserIndex = 0;
}

FString UAE_MaterialSGO::GetId() const
{
	return Id;
}

FString UAE_MaterialSGO::GetMaterialName() const
{
	return MaterialName;
}
