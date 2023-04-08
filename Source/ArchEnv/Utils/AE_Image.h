// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AE_Image.generated.h"

class UTexture2D;

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_Image : public UObject
{
	GENERATED_BODY()
	
	UPROPERTY()
	UTexture2D* ImageTexture;

public:
	UTexture2D* GetTexture() const;
	void SetTexture(UTexture2D* Texture);
};
