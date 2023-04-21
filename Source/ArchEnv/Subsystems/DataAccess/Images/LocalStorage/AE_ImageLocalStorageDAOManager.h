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

	void LoadDefaultImagesFromDataTable();
	
public:

	virtual void Initialize() override;
	virtual void CreateImage(UAE_Image* Image) override;
	virtual TArray<UAE_Image*> GetAllImages() override;
	virtual void UpdateImage(UAE_Image* Image) override;
	virtual void DeleteImage(UAE_Image* Image) override;
	virtual UAE_Image* GetImageById(const FString& Id) override;
};
