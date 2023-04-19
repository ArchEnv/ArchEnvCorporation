// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_ImagesSubsystem.h"

#include "LocalStorage/AE_ImageLocalStorageDAOManager.h"

UAE_ImagesSubsystem::UAE_ImagesSubsystem()
{
	ImageDAOManager = NewObject<UAE_ImageLocalStorageDAOManager>();
}

UAE_ImageDAOManager* UAE_ImagesSubsystem::GetImageDAOManager()
{
	return ImageDAOManager;
}
