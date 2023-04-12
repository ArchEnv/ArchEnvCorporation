// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_GameInstance.h"

#include "ArchEnv/Subsystems/DataAccess/AE_MaterialLocalStorageDAOSubsystem.h"

UAE_GameInstance::UAE_GameInstance()
{
	//Initial Subsystems
	MaterialDAOSubsystem = NewObject<UAE_MaterialLocalStorageDAOSubsystem>(this);
}

UAE_MaterialDAOSubsystem* UAE_GameInstance::GetMaterialDaoSubsystem() const
{
	return MaterialDAOSubsystem;
}
