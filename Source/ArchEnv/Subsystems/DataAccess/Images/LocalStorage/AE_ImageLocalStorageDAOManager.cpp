// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_ImageLocalStorageDAOManager.h"

void UAE_ImageLocalStorageDAOManager::LoadImagesFromDataTable(const FString& Path)
{
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableObject(*Path);

	if (DataTableObject.Succeeded())
	{
		const UDataTable* DataTable = DataTableObject.Object;
		TArray<FName> RowNames = DataTable->GetRowNames();

		for (FName RowName : RowNames)
		{
			UAE_Image* NewImage = NewObject<UAE_Image>();
			const FAE_ImageInfo* ImageInfo = DataTable->FindRow<FAE_ImageInfo>(RowName, "");
			
			NewImage->SetImageId(RowName.ToString());
			NewImage->SetTexture(ImageInfo->ImageTexture);

			Images.Add(NewImage);
		}
	}
}

UAE_ImageLocalStorageDAOManager::UAE_ImageLocalStorageDAOManager()
{
	const FString DataTablePath = "DataTable'/Game/Data/DefaultImagesDataTable.DefaultImagesDataTable'";
	LoadImagesFromDataTable(DataTablePath);
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
