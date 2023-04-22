// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ArchEnv/Interfaces/AE_GenericViewItem.h"
#include "ArchEnv/Interfaces/Commands/AE_CommandHandlerProvider.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "AE_Material.generated.h"

class UAE_Image;

USTRUCT(BlueprintType)
struct FAE_MaterialInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FText MaterialName;

	UPROPERTY(EditAnywhere)
	FString MaterialId;

	UPROPERTY(EditAnywhere)
	FString ImageId;
	
};

/**
 * 
 */
UCLASS(Blueprintable)
class ARCHENV_API UAE_Material : public UObject, public IAE_GenericViewItem, public IAE_CommandHandlerProvider
{
	GENERATED_BODY()
protected:
	
	UPROPERTY()
	UAE_Image* MaterialImage;

	UPROPERTY()
	FAE_MaterialInfo MaterialInfo;

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

	UFUNCTION()
	FString GetImageId();

	UFUNCTION()
	void SetImageId(const FString& NewId);
	
	UFUNCTION(BlueprintCallable)
	UAE_Image* GetMaterialImage() const;

	UFUNCTION(BlueprintCallable)
	void SetMaterialImage(UAE_Image* NewMaterialImage);

	virtual UTexture2D* GetTexture() override;

	UFUNCTION(BlueprintCallable)
	virtual UAE_CommandHandler* GetCommandHandler_Implementation() override;
};
