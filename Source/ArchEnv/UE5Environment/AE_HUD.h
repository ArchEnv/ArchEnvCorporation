// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Entities/AE_Entity.h"
#include "GameFramework/HUD.h"
#include "AE_HUD.generated.h"

/**
 * 
 */
UCLASS()
class ARCHENV_API AAE_HUD : public AHUD
{
	GENERATED_BODY()

protected:
	
	UPROPERTY(BlueprintReadOnly)
	AAE_Entity* SelectedEntity;

public:

	
	UFUNCTION(BlueprintCallable)
	AAE_Entity* GetSelectedEntity() const;

	UFUNCTION()
	void SetSelectedEntity(AAE_Entity* NewSelectedEntity);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ShowMaterialSelectorWidget();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HideMaterialSelectorWidget();

	AAE_HUD();
	
};
