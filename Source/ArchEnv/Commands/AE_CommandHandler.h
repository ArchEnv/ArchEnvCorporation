// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AE_BaseCommand.h"
#include "UObject/Object.h"
#include "AE_CommandHandler.generated.h"

/**
 * 
 */
UCLASS()
class ARCHENV_API UAE_CommandHandler : public UObject
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	TArray<UAE_BaseCommand*> GetCommands();

	void AddCommand(UAE_BaseCommand* NewCommand);

	void RemoveCommand(UAE_BaseCommand* NewCommand);

protected:

	UPROPERTY()
	TArray<UAE_BaseCommand*> Commands;
};
