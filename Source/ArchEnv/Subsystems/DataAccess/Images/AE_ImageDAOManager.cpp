// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_ImageDAOManager.h"

void UAE_ImageDAOManager::CreateImage_Implementation(UAE_Image* Image)
{
	IAE_ImageDAO::CreateImage_Implementation(Image);
}

TArray<UAE_Image*> UAE_ImageDAOManager::GetAllImages_Implementation()
{
	return IAE_ImageDAO::GetAllImages_Implementation();
}

void UAE_ImageDAOManager::UpdateImage_Implementation(UAE_Image* Image)
{
	IAE_ImageDAO::UpdateImage_Implementation(Image);
}

void UAE_ImageDAOManager::DeleteImage_Implementation(UAE_Image* Image)
{
	IAE_ImageDAO::DeleteImage_Implementation(Image);
}

UAE_Image* UAE_ImageDAOManager::GetImageById_Implementation(const FString& Id)
{
	return IAE_ImageDAO::GetImageById_Implementation(Id);
}
