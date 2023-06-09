// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_Character.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAE_Character::AAE_Character()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
		
	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void AAE_Character::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

	//Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(WalkMappingContext, 0);
		}
	}

	//Set input mode and show cursor
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		PlayerController->SetShowMouseCursor(true);
		PlayerController->SetInputMode(FInputModeGameAndUI());	
	}
	
}

// Called to bind functionality to input
void AAE_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAE_Character::Move);

		//Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AAE_Character::Look);

		//Switch movement mode
		EnhancedInputComponent->BindAction(SwitchMovementModeAction, ETriggerEvent::Triggered, this, &AAE_Character::SwitchMovementMode);

	}
}


void AAE_Character::Move(const FInputActionValue& Value)
{
	// input is a Vector2D
	const FVector MovementVector = Value.Get<FVector>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
		AddMovementInput(GetActorUpVector(), MovementVector.Z);
	}
}

void AAE_Character::Look(const FInputActionValue& Value)
{
	// input is a Vector2D
	FVector2D LookAxisVector = Value.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add yaw and pitch input to controller
		AddControllerYawInput(LookAxisVector.X);
		AddControllerPitchInput(LookAxisVector.Y);
	}
}

void AAE_Character::SwitchMovementMode(const FInputActionValue& Value)
{
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			if (GetCharacterMovement()->IsFlying())
			{
				GetCharacterMovement()->SetMovementMode(MOVE_Walking);
				Subsystem->AddMappingContext(WalkMappingContext, 0);
				Subsystem->RemoveMappingContext(FlightMappingContext);
			}else
			{
				GetCharacterMovement()->SetMovementMode(MOVE_Flying);
				Subsystem->AddMappingContext(FlightMappingContext, 0);
				Subsystem->RemoveMappingContext(WalkMappingContext);
			}
		}
	}
}
