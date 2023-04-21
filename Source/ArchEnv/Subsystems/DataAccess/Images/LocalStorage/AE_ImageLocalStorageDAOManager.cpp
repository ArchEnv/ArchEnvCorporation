// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_ImageLocalStorageDAOManager.h"

#include "ArchEnv/Settings/AE_DefaultImagesSettings.h"

void UAE_ImageLocalStorageDAOManager::LoadDefaultImagesFromDataTable()
{
	const UAE_DefaultImagesSettings* DefaultImagesSettings = GetDefault<UAE_DefaultImagesSettings>();
	
	if (const UDataTable* ImagesDataTable = DefaultImagesSettings->DefaultImagesPath.LoadSynchronous())
	{
		TArray<FName> RowNames = ImagesDataTable->GetRowNames();

		for (FName RowName : RowNames)
		{
			UAE_Image* NewImage = NewObject<UAE_Image>();
			if (const FAE_ImageInfo* ImageInfo = ImagesDataTable->FindRow<FAE_ImageInfo>(RowName, ""))
			{
				NewImage->SetImageId(RowName.ToString());
				NewImage->SetTexture(ImageInfo->ImageTexture);

				Images.Add(NewImage);
			}
		}
	}
}

void UAE_ImageLocalStorageDAOManager::Initialize()
{
	LoadDefaultImagesFromDataTable();
}

void UAE_ImageLocalStorageDAOManager::CreateImage(UAE_Image* Image)
{
}

TArray<UAE_Image*> UAE_ImageLocalStorageDAOManager::GetAllImages()
{
	return Images;
}

void UAE_ImageLocalStorageDAOManager::UpdateImage(UAE_Image* Image)
{
}

void UAE_ImageLocalStorageDAOManager::DeleteImage(UAE_Image* Image)
{
}

UAE_Image* UAE_ImageLocalStorageDAOManager::GetImageById(const FString& Id)
{
	UAE_Image* ImageFound = nullptr;

	for (UAE_Image* Image : Images)
	{
		if (Image->GetImageId() == Id)
		{
			ImageFound = Image;
			break;
		}
	}
	
	return ImageFound;
}
