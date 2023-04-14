// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AE_GenericViewControl.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, BlueprintType)
class UAE_GenericViewControl : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ARCHENV_API IAE_GenericViewControl
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
 	TArray<UObject*> GetItems();
	virtual TArray<UObject*> GetItems_Implementation() PURE_VIRTUAL(IAE_GenericViewControl::GetItems, return {};);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnItemClicked(UObject* Item);
	virtual void OnItemClicked_Implementation(UObject* Item) PURE_VIRTUAL(IAE_GenericViewControl::OnItemClicked);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	TArray<UObject*> FilterItemsByString(const FString& String);
	virtual TArray<UObject*> FilterItemsByString_Implementation(const FString& String) PURE_VIRTUAL(IAE_GenericViewControl::FilterItemsByString, return {};);
};
