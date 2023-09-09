// Fill out your copyright notice in the Description page of Project Settings.


#include "SDDodgeAbility.h"

void USDDodgeAbility::Tick(float DeltaTime)
{
	//Update whatever needs to be updated
	//Update the cooldown
}

void USDDodgeAbility::StartAbility()
{
	//Does the ability
	//Calls the EndAbility when done
}

void USDDodgeAbility::EndAbility()
{
	//Cleans up
	//Calls the delegate to notify the Controller
}

void USDDodgeAbility::InterruptAbility()
{
	//Cleans up
	//Stops the Ability (Can use the EndAbility)
}