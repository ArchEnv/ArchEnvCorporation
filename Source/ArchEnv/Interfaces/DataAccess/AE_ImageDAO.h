// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Utils/AE_Image.h"
#include "UObject/Interface.h"
#include "AE_ImageDAO.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
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
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Initialize();
	virtual void Initialize_Implementation() PURE_VIRTUAL(IAE_ImageDAO::Initialize);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void CreateImage(UAE_Image* Image);
	virtual void CreateImage_Implementation(UAE_Image* Image) PURE_VIRTUAL(IAE_ImageDAO::CreateImage);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	TArray<UAE_Image*> GetAllImages();
	virtual TArray<UAE_Image*> GetAllImages_Implementation() PURE_VIRTUAL(IAE_ImageDAO::GetAllImages, return {};);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void UpdateImage(UAE_Image* Image);
	virtual void UpdateImage_Implementation(UAE_Image* Image) PURE_VIRTUAL(IAE_ImageDAO::UpdateImage);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void DeleteImage(UAE_Image* Image);
	virtual void DeleteImage_Implementation(UAE_Image* Image) PURE_VIRTUAL(IAE_ImageDAO::DeleteImage);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	UAE_Image* GetImageById(const FString& Id);
	virtual UAE_Image* GetImageById_Implementation(const FString& Id) PURE_VIRTUAL(IAE_ImageDAO::GetImageById, return nullptr;);
};
