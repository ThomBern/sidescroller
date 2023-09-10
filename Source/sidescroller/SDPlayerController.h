// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Character.h"
#include "SDPlayerController.generated.h"

/** Forward declaration to improve compiling times */
class UEnhancedInputComponent;
class ACharacter;
class UInputMappingContext;

UCLASS(Abstract)
class ASDPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionForward = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionBackward = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionJump = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputAction> ActionDash = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Player Input|Character Movement")
	TObjectPtr<UInputMappingContext> InputMappingContent = nullptr;

protected:
	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnUnPossess() override;

	void HandleForward(const FInputActionValue& InputActionValue);
	void HandleBackward(const FInputActionValue& InputActionValue);
	void HandleJump();
	void HandleDash();

private:
	void InitializeAbilities();
	void DeInitializeAbilities();

	UPROPERTY()
	TObjectPtr<UEnhancedInputComponent> EnhancedInputComponent = nullptr;
	
	UPROPERTY()
	TObjectPtr<ACharacter> PlayerCharacter = nullptr;
	UPROPERTY()
	TArray<TObjectPtr<USDDABaseAbility>> Abilities;

};
