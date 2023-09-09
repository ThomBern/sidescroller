// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SDDABaseAbility.h"
#include "UObject/NoExportTypes.h"
#include "SDBaseAbility.generated.h"

/**
 * 
 */
UCLASS()
class SIDESCROLLER_API USDBaseAbility : public UObject, public FTickableGameObject
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) PURE_VIRTUAL(USDBaseAbility::Tick, );

	virtual void StartAbility() PURE_VIRTUAL(USDBaseAbility::StartAbility, );
	virtual void EndAbility() PURE_VIRTUAL(USDBaseAbility::EndAbility, );
	virtual void InterruptAbility() PURE_VIRTUAL(USDBaseAbility::InterruptAbility, );

	virtual bool ShouldBeInvincible() const { return bIsInvincible; }

private:
	virtual ETickableTickType GetTickableTickType() const override
	{
		return ETickableTickType::Always;
	}

	virtual TStatId GetStatId() const override
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(FMyTickableThing, STATGROUP_Tickables);
	}

	virtual void StartAbilityCooldown() { AbilityCooldown = DataAssetAbility->GetAbilityCooldown(); }
	virtual void UpdateAbilityCooldown(float DeltaTime) { FMath::Max(0.0f, AbilityCooldown - DeltaTime); }

	bool bIsInvincible = false;
	float AbilityCooldown = 0.0f;

	TObjectPtr<USDDABaseAbility> DataAssetAbility;
};
