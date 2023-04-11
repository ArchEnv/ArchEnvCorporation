// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AE_MaterialController.generated.h"


/**
 * 
 */
UCLASS(Blueprintable)
class ARCHENV_API UAE_MaterialController : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
protected:
	UPROPERTY()
	TArray<UAE_ConfigurableMaterial*> ConfigurableMaterials;

public:
	
	UFUNCTION(BlueprintCallable)
	TArray<UAE_ConfigurableMaterial*> GetConfigurableMaterials() const;

	UFUNCTION()
	void SetConfigurableMaterials(const TArray<UAE_ConfigurableMaterial*>& NewConfigurableMaterials);
	

	UFUNCTION(BlueprintCallable)
	TArray<UAE_ConfigurableMaterial*> GetConfigurableMaterialsInLocalFiles();

	UFUNCTION(BlueprintCallable)
	void SaveConfigurableMaterialsInLocalFiles(TArray<UAE_ConfigurableMaterial*> NewConfigurableMaterials);
	

};
