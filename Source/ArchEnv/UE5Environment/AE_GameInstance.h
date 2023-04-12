// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AE_GameInstance.generated.h"

class UAE_MaterialDAOSubsystem;
/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UAE_GameInstance();
	
	UFUNCTION(BlueprintCallable)
	UAE_MaterialDAOSubsystem* GetMaterialDaoSubsystem() const;

protected:

	UPROPERTY()
	UAE_MaterialDAOSubsystem* MaterialDAOSubsystem;

};
