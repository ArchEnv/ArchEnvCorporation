// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_MaterialLocalStorageDAOManager.h"

#include "AE_MaterialSGO.h"
#include "ArchEnv/Settings/AE_DefaultMaterialsSettings.h"
#include "ArchEnv/Subsystems/DataAccess/AE_DataAccessSubsystem.h"
#include "ArchEnv/Subsystems/DataAccess/Images/AE_ImageDAOManager.h"
#include "ArchEnv/UE5Environment/AE_HUD.h"
#include "Kismet/GameplayStatics.h"

void UAE_MaterialLocalStorageDAOManager::Initialize_Implementation()
{
	LoadMaterialsFromDataTable();
	LoadTexturesFromImageSubsystem();
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

void UAE_MaterialLocalStorageDAOManager::LoadMaterialsFromDataTable()
{
	const UAE_DefaultMaterialsSettings* DefaultMaterialsSettings = GetDefault<UAE_DefaultMaterialsSettings>();

	if (const UDataTable* MaterialsDataTable = DefaultMaterialsSettings->DefaultMaterialsPath.LoadSynchronous())
	{
		TArray<FName> RowNames = MaterialsDataTable->GetRowNames();

		for (FName RowName : RowNames)
		{
			UAE_Material* NewMaterial = NewObject<UAE_Material>();
			if (const FAE_MaterialInfo* MaterialInfo = MaterialsDataTable->FindRow<FAE_MaterialInfo>(RowName, ""))
			{
				NewMaterial->SetMaterialId(RowName.ToString());
				NewMaterial->SetMaterialName(MaterialInfo->MaterialName.ToString());
				NewMaterial->SetImageId(MaterialInfo->ImageId);

				Materials.Add(NewMaterial);
			}			
		}
	}
}

void UAE_MaterialLocalStorageDAOManager::LoadTexturesFromImageSubsystem()
{
	if (const UAE_DataAccessSubsystem* DataAccessSubsystem = Cast<UAE_DataAccessSubsystem>(GetOuter()))
	{
		if (DataAccessSubsystem->GetImagesDAOManager()->Implements<UAE_ImageDAO>())
		{
			for (auto Material : Materials)
			{
				if (UAE_Image* ImageFound = IAE_ImageDAO::Execute_GetImageById(DataAccessSubsystem->GetImagesDAOManager(), Material->GetImageId()))
				{
					Material->SetMaterialImage(ImageFound);
				}
			}
		}
	}
}
