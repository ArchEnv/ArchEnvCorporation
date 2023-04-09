// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_Entity.h"

#include "ArchEnv/Materials/AE_Material.h"
#include "ArchEnv/UE5Environment/AE_HUD.h"
#include "Kismet/GameplayStatics.h"

AAE_Entity::AAE_Entity()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Static Mesh Component"));
	SetRootComponent(StaticMeshComponent);
}

void AAE_Entity::SetConfigurableMaterial(UAE_Material* NewConfigurableMaterial)
{
	ConfigurableMaterial = NewConfigurableMaterial;
}

UAE_Material* AAE_Entity::GetConfigurableMaterial()
{
	return ConfigurableMaterial;
}

void AAE_Entity::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAE_Entity::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	
	if (const APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		AAE_HUD* HUD = Cast<AAE_HUD>(PlayerController->GetHUD());
		HUD->SetSelectedEntity(this);
		HUD->ShowMaterialSelectorWidget();
	}
}


