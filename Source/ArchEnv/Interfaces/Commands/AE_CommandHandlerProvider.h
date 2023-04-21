// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AE_CommandHandlerProvider.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UAE_CommandHandlerProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARCHENV_API IAE_CommandHandlerProvider
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	UAE_CommandHandler* GetCommandHandler();
	virtual UAE_CommandHandler* GetCommandHandler_Implementation() PURE_VIRTUAL(IAE_CommandHandlerProvider::GetCommandHandler, return nullptr;);
};
