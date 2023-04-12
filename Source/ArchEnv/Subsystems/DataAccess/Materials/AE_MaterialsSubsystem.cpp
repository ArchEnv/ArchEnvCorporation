// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_MaterialsSubsystem.h"
#include "AE_MaterialDAOManager.h"

UAE_MaterialsSubsystem::UAE_MaterialsSubsystem()
{
	MaterialDAOManager = NewObject<UAE_MaterialDAOManager>();
}

UAE_MaterialDAOManager* UAE_MaterialsSubsystem::GetMaterialDaoManager() const
{
	return MaterialDAOManager;
}
