// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SDDABaseAbility.generated.h"

class USDBaseAbility;

/**
 * 
 */
UCLASS()
class SIDESCROLLER_API USDDABaseAbility : public UDataAsset
{
	GENERATED_BODY()
	
public:
	void Initialize();
	void DeInitialize();

	float GetAbilityCooldown() const { return ActionCooldown; }

private:
	UPROPERTY()
	USDBaseAbility* Ability = nullptr;
	UPROPERTY()
	float ActionCooldown = 0.0f;
	//Animation
};
