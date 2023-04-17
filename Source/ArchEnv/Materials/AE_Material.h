// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/AE_ConfigurableItems.h"
#include "ArchEnv/Interfaces/Commands/AE_CommandHandlerProvider.h"
#include "UObject/NoExportTypes.h"
#include "AE_Material.generated.h"

class UAE_Image;
/**
 * 
 */
UCLASS(Blueprintable)
class ARCHENV_API UAE_Material : public UObject, public IAE_ConfigurableItems, public IAE_CommandHandlerProvider
{
	GENERATED_BODY()
protected:
	
	UPROPERTY()
	UAE_Image* Thumbnail;

	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString Id;

	UPROPERTY()
	UAE_CommandHandler* CommandHandler;

public:
	UFUNCTION(BlueprintCallable)
	FString GetMaterialName() const;
	
	UFUNCTION()
	void SetMaterialName(const FString& NewName);
	
	UFUNCTION(BlueprintCallable)
	FString GetMaterialId() const;

	UFUNCTION()
	void SetMaterialId(const FString& NewId);

	UFUNCTION(BlueprintCallable)
	UAE_Image* GetThumbnail() const;

	UFUNCTION(BlueprintCallable)
	void SetThumbnail(UAE_Image* NewThumbnail);

	virtual UTexture2D* GetTexture_Implementation() override;

	virtual UAE_CommandHandler* GetCommandHandler_Implementation() override;
};
