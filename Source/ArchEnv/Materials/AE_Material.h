// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/AE_ConfigurableItems.h"
#include "UObject/NoExportTypes.h"
#include "AE_Material.generated.h"

class UAE_Image;
/**
 * 
 */
UCLASS(Blueprintable)
class ARCHENV_API UAE_Material : public UObject, public IAE_ConfigurableItems
{
	GENERATED_BODY()
protected:
	
	UPROPERTY()
	UAE_Image* Thumbnail;

	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString Id;

public:
	UFUNCTION(BlueprintCallable)
	FString GetName() const;
	
	UFUNCTION()
	void SetName(const FString& NewName);
	
	UFUNCTION(BlueprintCallable)
	FString GetId() const;

	UFUNCTION()
	void SetId(const FString& NewId);

	UFUNCTION(BlueprintCallable)
	UAE_Image* GetThumbnail() const;

	UFUNCTION(BlueprintCallable)
	void SetThumbnail(UAE_Image* NewThumbnail);

	virtual UTexture2D* GetTexture_Implementation() override;
};
