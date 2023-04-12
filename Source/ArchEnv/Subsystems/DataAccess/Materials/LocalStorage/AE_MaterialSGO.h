// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "AE_MaterialSGO.generated.h"

class UAE_Material;
/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_MaterialSGO : public USaveGame
{
	GENERATED_BODY()

public:

	UFUNCTION()
	void SetSaveMaterial(const UAE_Material* SaveMaterial);
	
	UFUNCTION()
	FString GetId() const;

	UFUNCTION()
	FString GetMaterialName() const;
	
	UPROPERTY()
	FString SaveSlotName;

	UPROPERTY()
	uint32 UserIndex;
	
protected:
		
	UPROPERTY()
	FString Id;

	UPROPERTY()
	FString MaterialName;

};
