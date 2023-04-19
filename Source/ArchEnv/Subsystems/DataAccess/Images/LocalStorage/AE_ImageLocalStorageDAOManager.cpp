// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_ImageLocalStorageDAOManager.h"

UAE_ImageLocalStorageDAOManager::UAE_ImageLocalStorageDAOManager()
{
	
}

void UAE_ImageLocalStorageDAOManager::CreateImage_Implementation(UAE_Image* Image)
{
	Super::CreateImage_Implementation(Image);
}

TArray<UAE_Image*> UAE_ImageLocalStorageDAOManager::GetAllImages_Implementation()
{
	return Super::GetAllImages_Implementation();
}

void UAE_ImageLocalStorageDAOManager::UpdateImage_Implementation(UAE_Image* Image)
{
	Super::UpdateImage_Implementation(Image);
}

void UAE_ImageLocalStorageDAOManager::DeleteImage_Implementation(UAE_Image* Image)
{
	Super::DeleteImage_Implementation(Image);
}

UAE_Image* UAE_ImageLocalStorageDAOManager::GetImageById_Implementation(const FString& Id)
{
	return Super::GetImageById_Implementation(Id);
}
