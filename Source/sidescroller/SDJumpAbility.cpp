// Fill out your copyright notice in the Description page of Project Settings.


#include "SDJumpAbility.h"

void USDJumpAbility::Tick(float DeltaTime)
{
	//Update whatever needs to be updated
	//Update the cooldown
}

void USDJumpAbility::StartAbility()
{
	//Does the ability
	//Calls the EndAbility when done
}

void USDJumpAbility::EndAbility()
{
	//Cleans up
	//Calls the delegate to notify the Controller
}

void USDJumpAbility::InterruptAbility()
{
	//Cleans up
	//Stops the Ability (Can use the EndAbility)
}