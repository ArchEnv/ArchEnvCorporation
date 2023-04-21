// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Utils/AE_Image.h"
#include "UObject/Interface.h"
#include "AE_ImageDAO.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType, NotBlueprintable)
class UAE_ImageDAO : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARCHENV_API IAE_ImageDAO
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable)
	virtual void Initialize() PURE_VIRTUAL(IAE_ImageDAO::Initialize,);

	UFUNCTION(BlueprintCallable)
	virtual void CreateImage(UAE_Image* Image) PURE_VIRTUAL(IAE_ImageDAO::CreateImage,);

	UFUNCTION(BlueprintCallable)
	virtual TArray<UAE_Image*> GetAllImages() PURE_VIRTUAL(IAE_ImageDAO::GetAllImages, return {};);

	UFUNCTION(BlueprintCallable)
	virtual void UpdateImage(UAE_Image* Image) PURE_VIRTUAL(IAE_ImageDAO::UpdateImage,);

	UFUNCTION(BlueprintCallable)
	virtual void DeleteImage(UAE_Image* Image) PURE_VIRTUAL(IAE_ImageDAO::DeleteImage,);

	UFUNCTION(BlueprintCallable)
	virtual UAE_Image* GetImageById(const FString& Id) PURE_VIRTUAL(IAE_ImageDAO::GetImageById, return nullptr;);
};
