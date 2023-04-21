// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/DeveloperSettings.h"
#include "AE_DefaultImagesSettings.generated.h"

/**
 * 
 */
UCLASS(Config=Game, defaultconfig, meta = (DisplayName="Default Images Settings"))
class ARCHENV_API UAE_DefaultImagesSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:

	/* Soft path will be converted to content reference before use */
	UPROPERTY(Config, EditAnywhere, BlueprintReadOnly, Category = "General", AdvancedDisplay)
	TSoftObjectPtr<UDataTable> DefaultImagesPath;
};
