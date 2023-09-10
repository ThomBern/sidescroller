// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void ASDPlayerControllerBase::OnPossess(APawn* aPawn)
{
	// Call the parent method, to let it do anything it needs to
	Super::OnPossess(aPawn);

	// Store a reference to the Player's Pawn
	PlayerCharacter = Cast<ACharacter>(aPawn);
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

	if (ActionForward)
	{
		EnhancedInputComponent->BindAction(ActionForward, ETriggerEvent::Triggered, this, &ASDPlayerControllerBase::HandleForward);
	}	
	
	if (ActionBackward)
	{
		EnhancedInputComponent->BindAction(ActionBackward, ETriggerEvent::Triggered, this, &ASDPlayerControllerBase::HandleBackward);
	}
	
	if (ActionJump)
	{
		EnhancedInputComponent->BindAction(ActionJump, ETriggerEvent::Triggered, this, &ASDPlayerControllerBase::HandleJump);
	}
}

void ASDPlayerControllerBase::OnUnPossess()
{
	// Unbind things here...
	EnhancedInputComponent->ClearActionBindings();

	// Call the parent method, in case it needs to do anything.
	Super::OnUnPossess();
}

void ASDPlayerControllerBase::HandleForward(const FInputActionValue& InputActionValue)
{
	const float Movement = InputActionValue.Get<float>();

	// Add movement to the Player's Character Pawn
	if (PlayerCharacter)
	{
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), 0.0);
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), 1);
	}
}

void ASDPlayerControllerBase::HandleBackward(const FInputActionValue& InputActionValue)
{
	const float Movement = InputActionValue.Get<float>();

	// Add movement to the Player's Character Pawn
	if (PlayerCharacter)
	{
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorRightVector(), 0.0);
		PlayerCharacter->AddMovementInput(PlayerCharacter->GetActorForwardVector(), -1);
	}
}

void ASDPlayerControllerBase::HandleJump()
{
	// Input is 'Digital' (value not used here)

	// Make the Player's Character Pawn jump, disabling crouch if it was active
	if (PlayerCharacter)
	{
		PlayerCharacter->UnCrouch();
		PlayerCharacter->Jump();
	}
}

void ASDPlayerControllerBase::HandleDash()
{
}
