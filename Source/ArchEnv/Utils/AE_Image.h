// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AE_Image.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FAE_ImageInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UTexture2D* ImageTexture;

	UPROPERTY(EditAnywhere)
	FString ImageId;
	
};

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_Image : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY()
	FAE_ImageInfo ImageInfo;

public:
	UTexture2D* GetTexture() const;
	void SetTexture(UTexture2D* Texture);
	FString GetImageId();
	void SetImageId(FString NewId);
	
};
