// Copyright Epic Games, Inc. All Rights Reserved.

#include "sidescrollerPlayerController.h"
#include "sidescrollerCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"


void AsidescrollerPlayerControllerBase::OnPossess(APawn* aPawn)
{
	// Call the parent method, to let it do anything it needs to
	Super::OnPossess(aPawn);

	// Store a reference to the Player's Pawn
	PlayerCharacter = Cast<AsidescrollerCharacterBase>(aPawn);
	checkf(PlayerCharacter,
		TEXT("APlayerControllerBBBase derived classes should only posess ACharacterBBBase derived pawns"));

	// Get a reference to the EnhancedInputComponent
	EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	checkf(EnhancedInputComponent,
		TEXT("Unable to get reference to the EnhancedInputComponent."));

	// Get the local player subsystem
	// Just a local variable, we dont need to refer to it again after this
	UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
		ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	checkf(InputSubsystem,
		TEXT("Unable to get reference to the EnhancedInputLocalPlayerSubsystem."));

	// Wipe existing mappings, and add our mapping.
	checkf(InputMappingContent, TEXT("InputMappingContent was not specified."));
	InputSubsystem->ClearAllMappings();
	InputSubsystem->AddMappingContext(InputMappingContent, 0);

	if (ActionMove)
	{
		EnhancedInputComponent->BindAction(ActionMove, ETriggerEvent::Triggered, this, &AsidescrollerPlayerControllerBase::HandleMove);
	}
	
	if (ActionJump)
	{
		EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Triggered, this, &AsidescrollerPlayerControllerBase::HandleJump);
	}
}

void AsidescrollerPlayerControllerBase::OnUnPossess()
{
	// Unbind things here...
	EnhancedInputComponent->ClearActionBindings();

	// Call the parent method, in case it needs to do anything.
	Super::OnUnPossess();
}

void AsidescrollerPlayerControllerBase::HandleMove(const FInputActionValue& InputActionValue)
{
	// Value is a Vector2D
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();

	// Add movement to the Player's Character Pawn
	if (PlayerCharacter)
	{
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), MovementVector.Y);
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), MovementVector.X);
	}
}

void AsidescrollerPlayerControllerBase::HandleJump()
{
	// Input is 'Digital' (value not used here)

	// Make the Player's Character Pawn jump, disabling crouch if it was active
	if (PlayerCharacter)
	{
		PlayerCharacter->UnCrouch();
		PlayerCharacter->Jump();
	}
}
