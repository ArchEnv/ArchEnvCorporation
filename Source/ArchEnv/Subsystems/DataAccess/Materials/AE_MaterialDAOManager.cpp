// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_MaterialDAOManager.h"

void UAE_MaterialDAOManager::CreateMaterial_Implementation(UAE_Material* Material)
{
	IAE_MaterialDAO::CreateMaterial_Implementation(Material);
}

void UAE_MaterialDAOManager::DeleteMaterial_Implementation(UAE_Material* Material)
{
	IAE_MaterialDAO::DeleteMaterial_Implementation(Material);
}

TArray<UAE_Material*> UAE_MaterialDAOManager::GetAllMaterials_Implementation()
{
	return IAE_MaterialDAO::GetAllMaterials_Implementation();
}

void UAE_MaterialDAOManager::UpdateMaterial_Implementation(UAE_Material* Material)
{
	IAE_MaterialDAO::UpdateMaterial_Implementation(Material);
}

TArray<UObject*> UAE_MaterialDAOManager::GetItems_Implementation()
{
	return TArray<UObject*>(Materials);
}

void UAE_MaterialDAOManager::OnItemClicked_Implementation(UObject* Item)
{
	IAE_GenericViewControl::OnItemClicked_Implementation(Item);
}

TArray<UObject*> UAE_MaterialDAOManager::FilterItemsByString_Implementation(const FString& String)
{
	return IAE_GenericViewControl::FilterItemsByString_Implementation(String);
}
