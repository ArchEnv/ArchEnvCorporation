// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_DeleteMaterialCommand.h"
#include "ArchEnv/Interfaces/DataAccess/AE_MaterialDAO.h"
#include "ArchEnv/Materials/AE_Material.h"
#include "ArchEnv/Subsystems/DataAccess/AE_DataAccessSubsystem.h"
#include "ArchEnv/Subsystems/DataAccess/Materials/LocalStorage/AE_MaterialLocalStorageDAOManager.h"

void UAE_DeleteMaterialCommand::Execute_Implementation()
{
	const UAE_DataAccessSubsystem* DataAccessSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UAE_DataAccessSubsystem>();
	
	if (UAE_MaterialDAOManager* MaterialDAOManager = DataAccessSubsystem->GetMaterialsDAOManager())
	{
		MaterialDAOManager->DeleteMaterial(Cast<UAE_Material>(Object));
	}
}
