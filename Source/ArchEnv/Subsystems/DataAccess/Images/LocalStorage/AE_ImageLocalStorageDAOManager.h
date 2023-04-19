// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Subsystems/DataAccess/Images/AE_ImageDAOManager.h"
#include "AE_ImageLocalStorageDAOManager.generated.h"

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_ImageLocalStorageDAOManager : public UAE_ImageDAOManager
{
	GENERATED_BODY()

protected:

	void LoadImagesFromDataTable(const FString& Path);
	
public:

	UAE_ImageLocalStorageDAOManager();
	
	virtual void CreateImage_Implementation(UAE_Image* Image) override;
	virtual TArray<UAE_Image*> GetAllImages_Implementation() override;
	virtual void UpdateImage_Implementation(UAE_Image* Image) override;
	virtual void DeleteImage_Implementation(UAE_Image* Image) override;
	virtual UAE_Image* GetImageById_Implementation(const FString& Id) override;
};
