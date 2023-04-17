// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_MaterialLocalStorageDAOManager.h"

#include "AE_MaterialSGO.h"
#include "ArchEnv/UE5Environment/AE_HUD.h"
#include "Kismet/GameplayStatics.h"

UAE_MaterialLocalStorageDAOManager::UAE_MaterialLocalStorageDAOManager()
{
}

void UAE_MaterialLocalStorageDAOManager::CreateMaterial_Implementation(UAE_Material* Material)
{
	Materials.Add(Material);
	AsyncMaterialSaveToDisk(Material);
}

void UAE_MaterialLocalStorageDAOManager::DeleteMaterial_Implementation(UAE_Material* Material)
{
	Materials.Remove(Material);
	//Delete material file
	UGameplayStatics::DeleteGameInSlot(Material->GetMaterialId(), 0);
}

TArray<UAE_Material*> UAE_MaterialLocalStorageDAOManager::GetAllMaterials_Implementation()
{
	return Materials;
}

void UAE_MaterialLocalStorageDAOManager::UpdateMaterial_Implementation(UAE_Material* Material)
{
	const int32 index = Materials.Find(Material);
	Materials[index] = Material;
	AsyncMaterialSaveToDisk(Material);
}

TArray<UObject*> UAE_MaterialLocalStorageDAOManager::GetItems_Implementation()
{
	return TArray<UObject*>(Materials);
}

void UAE_MaterialLocalStorageDAOManager::OnItemClicked_Implementation(UObject* Item)
{
	if (const APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		const AAE_HUD* HUD = PC->GetHUD<AAE_HUD>();
		HUD->GetSelectedEntity()->SetConfigurableMaterial(Cast<UAE_Material>(Item));
	}
}

TArray<UObject*> UAE_MaterialLocalStorageDAOManager::FilterItemsByString_Implementation(const FString& String)
{
	TArray<UObject*> FilteredArray;
	for (const auto Material : Materials)
	{
		if (Material->GetName().Contains(String))
		{
			FilteredArray.Add(Material);
		}
	}
	return FilteredArray;
}

void UAE_MaterialLocalStorageDAOManager::AsyncMaterialSaveToDisk(const UAE_Material* SaveMaterial)
{
	if (UAE_MaterialSGO* MaterialSaveGameInstance = Cast<UAE_MaterialSGO>(UGameplayStatics::CreateSaveGameObject(UAE_MaterialSGO::StaticClass())))
	{
		// Set data on the savegame object.
		MaterialSaveGameInstance->SetSaveMaterial(SaveMaterial);

		// Start async save process.
		UGameplayStatics::AsyncSaveGameToSlot(MaterialSaveGameInstance, MaterialSaveGameInstance->SaveSlotName, MaterialSaveGameInstance->UserIndex);
	}
}
