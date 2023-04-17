// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_DeleteMaterialCommand.h"
#include "ArchEnv/Interfaces/DataAccess/AE_MaterialDAO.h"
#include "ArchEnv/Subsystems/DataAccess/Materials/AE_MaterialsSubsystem.h"
#include "ArchEnv/Materials/AE_Material.h"
#include "ArchEnv/Subsystems/DataAccess/Materials/LocalStorage/AE_MaterialLocalStorageDAOManager.h"
#include "Kismet/GameplayStatics.h"

void UAE_DeleteMaterialCommand::Execute_Implementation()
{
	const UAE_MaterialsSubsystem* MaterialsSubsystem = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UAE_MaterialsSubsystem>();

	if (Cast<IAE_MaterialDAO>(MaterialsSubsystem->GetMaterialDaoManager()))
	{
		IAE_MaterialDAO::Execute_DeleteMaterial(MaterialsSubsystem->GetMaterialDaoManager(), Cast<UAE_Material>(Object));
	}
}
