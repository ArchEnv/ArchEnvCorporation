// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_EditMaterialCommand.h"
#include "ArchEnv/Interfaces/DataAccess/AE_MaterialDAO.h"
#include "ArchEnv/Materials/AE_Material.h"
#include "ArchEnv/Subsystems/DataAccess/AE_DataAccessSubsystem.h"
#include "ArchEnv/Subsystems/DataAccess/Materials/LocalStorage/AE_MaterialLocalStorageDAOManager.h"

void UAE_EditMaterialCommand::Execute_Implementation()
{
	const UAE_DataAccessSubsystem* DataAccessSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UAE_DataAccessSubsystem>();
	
	if (UAE_MaterialDAOManager* MaterialDAOManager = DataAccessSubsystem->GetMaterialsDAOManager())
	{
		MaterialDAOManager->UpdateMaterial(Cast<UAE_Material>(Object));
	}
}
