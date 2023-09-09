// Fill out your copyright notice in the Description page of Project Settings.


#include "SDBasicAttackAbility.h"

void USDBasicAttackAbility::Tick(float DeltaTime)
{
	//Update whatever needs to be updated
	//Update the cooldown
}

void USDBasicAttackAbility::StartAbility()
{
	//Does the ability
	//Calls the EndAbility when done
}

void USDBasicAttackAbility::EndAbility()
{
	//Cleans up
	//Calls the delegate to notify the Controller
}

void USDBasicAttackAbility::InterruptAbility()
{
	//Cleans up
	//Stops the Ability (Can use the EndAbility)
}