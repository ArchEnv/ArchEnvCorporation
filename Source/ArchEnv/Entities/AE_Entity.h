// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AE_Entity.generated.h"

class UAE_Material;
UCLASS()
class ARCHENV_API AAE_Entity : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAE_Entity();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION(BlueprintCallable)
	void SetConfigurableMaterial(UAE_Material* NewConfigurableMaterial);

	UFUNCTION(BlueprintCallable)
	UAE_Material* GetConfigurableMaterial();

protected:

	UPROPERTY()
	UAE_Material* ConfigurableMaterial;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;

	

};
