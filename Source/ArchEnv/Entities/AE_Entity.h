// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AE_Entity.generated.h"

UCLASS()
class ARCHENV_API AAE_Entity : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAE_Entity();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
