// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_DataAccessSubsystem.h"

#include "Images/AE_ImageDAOManager.h"
#include "Images/LocalStorage/AE_ImageLocalStorageDAOManager.h"
#include "Materials/AE_MaterialDAOManager.h"
#include "Materials/LocalStorage/AE_MaterialLocalStorageDAOManager.h"

void UAE_DataAccessSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	MaterialDAOManager = NewObject<UAE_MaterialLocalStorageDAOManager>(this);
	ImagesDAOManager = NewObject<UAE_ImageLocalStorageDAOManager>(this);

	IAE_ImageDAO::Execute_Initialize(ImagesDAOManager);
	IAE_MaterialDAO::Execute_Initialize(MaterialDAOManager);
}

UAE_MaterialDAOManager* UAE_DataAccessSubsystem::GetMaterialsDAOManager() const
{
	return MaterialDAOManager;
}

UAE_ImageDAOManager* UAE_DataAccessSubsystem::GetImagesDAOManager() const
{
	return ImagesDAOManager;
}
