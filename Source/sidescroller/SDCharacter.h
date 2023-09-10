// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SDCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UENUM()
enum class EPlayerLookDirection : int8
{
	LookingLeft = -1,
	LookingRight = 1,
};

UCLASS(Blueprintable)
class ASDCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	ASDCharacterBase();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE TObjectPtr<UCameraComponent> GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE TObjectPtr<USpringArmComponent> GetCameraBoom() const { return CameraBoom; }
	
	UPROPERTY()
	EPlayerLookDirection LookDirection;

	UFUNCTION()
	void UpdateLookDirection(int direction);

protected:


private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UCameraComponent> TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<USpringArmComponent> CameraBoom;
};

