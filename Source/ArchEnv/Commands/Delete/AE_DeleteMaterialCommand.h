// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AE_DeleteCommand.h"
#include "UObject/Object.h"
#include "AE_DeleteMaterialCommand.generated.h"

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_DeleteMaterialCommand : public UAE_DeleteCommand
{
	GENERATED_BODY()
public:
	virtual void Execute_Implementation() override;
};
