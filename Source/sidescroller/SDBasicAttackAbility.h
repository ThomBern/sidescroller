// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SDBaseAbility.h"
#include "SDBasicAttackAbility.generated.h"

/**
 * 
 */
UCLASS()
class SIDESCROLLER_API USDBasicAttackAbility : public USDBaseAbility
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;

	virtual void StartAbility() override;
	virtual void EndAbility() override;
	virtual void InterruptAbility() override;
};
