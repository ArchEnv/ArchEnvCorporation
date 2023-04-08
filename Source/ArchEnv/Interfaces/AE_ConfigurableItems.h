// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AE_ConfigurableItems.generated.h"

class IAE_ConfigurableControllers;

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UAE_ConfigurableItems : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARCHENV_API IAE_ConfigurableItems
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	UTexture2D* GetTexture();
};
