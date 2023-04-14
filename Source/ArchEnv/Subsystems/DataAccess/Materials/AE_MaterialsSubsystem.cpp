// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_MaterialsSubsystem.h"
#include "AE_MaterialDAOManager.h"
#include "LocalStorage/AE_MaterialLocalStorageDAOManager.h"

UAE_MaterialsSubsystem::UAE_MaterialsSubsystem()
{
	MaterialDAOManager = NewObject<UAE_MaterialLocalStorageDAOManager>();
}

UAE_MaterialDAOManager* UAE_MaterialsSubsystem::GetMaterialDaoManager() const
{
	return MaterialDAOManager;
}
