// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_MaterialController.h"

#include "ArchEnv/Repositories/MaterialRepository/SaveGameConfigurableMaterial.h"
#include "Kismet/GameplayStatics.h"

TArray<UAE_ConfigurableMaterial*> UAE_MaterialController::GetConfigurableMaterials() const
{
	return ConfigurableMaterials;
}

void UAE_MaterialController::SetConfigurableMaterials(const TArray<UAE_ConfigurableMaterial*>& NewConfigurableMaterials)
{
	this->ConfigurableMaterials = NewConfigurableMaterials;
}

void UAE_MaterialController::SaveConfigurableMaterialsInLocalFiles(TArray<UAE_ConfigurableMaterial*> NewConfigurableMaterials)
{
	// Creo instancia del repositorio y seteo el atributo.
	USaveGameConfigurableMaterial* SGMaterial1 = NewObject<USaveGameConfigurableMaterial>();
	SGMaterial1->ConfigurableMaterials = NewConfigurableMaterials;
	
	// UAE_ConfigurableMaterial* Material1 = NewObject<UAE_ConfigurableMaterial>();
	// Material1->SetId("1");
	// Material1->SetName("Material 1");
	// SGMaterial1->ConfigurableMaterials.Add(Material1);
	
	// Guardo el Material
	
	UGameplayStatics::SaveGameToSlot(SGMaterial1, TEXT("ConfigurableMaterials"), 0);

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow,
	 									 TEXT("TEST: Material Saved in local files!"));
}

TArray<UAE_ConfigurableMaterial*> UAE_MaterialController::GetConfigurableMaterialsInLocalFiles()
{
	// Carga el objeto SaveGameExample desde el archivo "MySaveGame.sav"
	if(USaveGameConfigurableMaterial* LoadedSaveGameMaterialInstance = Cast<USaveGameConfigurableMaterial>(UGameplayStatics::LoadGameFromSlot(TEXT("ConfigurableMaterials"), 0)))
	{
		// Verifica si se pudo cargar el objeto SaveGameExample
		if (LoadedSaveGameMaterialInstance)
		{
			// Accede al arreglo de materiales
			//TArray<UAE_ConfigurableMaterial*> LoadedMaterialsArray = LoadedSaveGameMaterialInstance->GetConfigurableMaterials();
			return LoadedSaveGameMaterialInstance->ConfigurableMaterials;
		}
		else
		{
			// Si no se pudo cargar el objeto SaveGameExample, muestra un mensaje de error o realiza una acción alternativa
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow,
											  TEXT("TEST: Cannot get Material in local files!"));
		}
	}
	TArray<UAE_ConfigurableMaterial*> EmptyArray;
	return EmptyArray;
}
