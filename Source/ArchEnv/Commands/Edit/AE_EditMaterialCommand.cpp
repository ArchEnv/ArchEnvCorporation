// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_EditMaterialCommand.h"
#include "ArchEnv/Interfaces/DataAccess/AE_MaterialDAO.h"
#include "ArchEnv/Subsystems/DataAccess/Materials/AE_MaterialsSubsystem.h"
#include "ArchEnv/Materials/AE_Material.h"
#include "ArchEnv/Subsystems/DataAccess/Materials/LocalStorage/AE_MaterialLocalStorageDAOManager.h"
#include "Kismet/GameplayStatics.h"

void UAE_EditMaterialCommand::Execute_Implementation()
{
	const UAE_MaterialsSubsystem* MaterialsSubsystem = UGameplayStatics::GetGameInstance(GetWorld())->GetSubsystem<UAE_MaterialsSubsystem>();

	if (Cast<IAE_MaterialDAO>(MaterialsSubsystem->GetMaterialDaoManager()))
	{
		IAE_MaterialDAO::Execute_UpdateMaterial(MaterialsSubsystem->GetMaterialDaoManager(), Cast<UAE_Material>(Object));
	}
}
