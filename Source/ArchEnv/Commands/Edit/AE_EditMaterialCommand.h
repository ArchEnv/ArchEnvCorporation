// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AE_EditCommand.h"
#include "UObject/Object.h"
#include "AE_EditMaterialCommand.generated.h"

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_EditMaterialCommand : public UAE_EditCommand
{
	GENERATED_BODY()
public:
	virtual void Execute_Implementation() override;
};
