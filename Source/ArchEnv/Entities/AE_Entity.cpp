// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_Entity.h"

// Sets default values
AAE_Entity::AAE_Entity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAE_Entity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAE_Entity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

