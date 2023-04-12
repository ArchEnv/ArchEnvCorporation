// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_MaterialLocalStorageDAOSubsystem.h"

UAE_MaterialLocalStorageDAOSubsystem::UAE_MaterialLocalStorageDAOSubsystem()
{
}

void UAE_MaterialLocalStorageDAOSubsystem::CreateMaterial_Implementation(UAE_Material* Material)
{
	Materials.Add(Material);
}

void UAE_MaterialLocalStorageDAOSubsystem::DeleteMaterial_Implementation(UAE_Material* Material)
{
	Materials.Remove(Material);
}

TArray<UAE_Material*> UAE_MaterialLocalStorageDAOSubsystem::GetAllMaterials_Implementation()
{
	return Materials;
}

void UAE_MaterialLocalStorageDAOSubsystem::UpdateMaterial_Implementation(UAE_Material* Material)
{
	const int32 index = Materials.Find(Material);
	Materials[index] = Material;
}
