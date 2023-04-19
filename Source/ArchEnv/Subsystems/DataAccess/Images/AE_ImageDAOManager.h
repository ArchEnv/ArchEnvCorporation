// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/DataAccess/AE_ImageDAO.h"
#include "UObject/NoExportTypes.h"
#include "AE_ImageDAOManager.generated.h"

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_ImageDAOManager : public UObject, public IAE_ImageDAO
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TArray<UAE_Image*> Images;

public:
	virtual void CreateImage_Implementation(UAE_Image* Image) override;
	virtual TArray<UAE_Image*> GetAllImages_Implementation() override;
	virtual void UpdateImage_Implementation(UAE_Image* Image) override;
	virtual void DeleteImage_Implementation(UAE_Image* Image) override;
	virtual UAE_Image* GetImageById_Implementation(const FString& Id) override;
};
