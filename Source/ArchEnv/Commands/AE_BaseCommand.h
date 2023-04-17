// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/Commands/AE_Command.h"
#include "UObject/Object.h"
#include "AE_BaseCommand.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class ARCHENV_API UAE_BaseCommand : public UObject, public IAE_Command
{
	GENERATED_BODY()
public:
	virtual void Initialize(UObject* NewObject) override;
	virtual void Execute_Implementation() override;
	virtual FString GetCommandName_Implementation() override;

protected:

	UPROPERTY()
	UObject* Object;
};
