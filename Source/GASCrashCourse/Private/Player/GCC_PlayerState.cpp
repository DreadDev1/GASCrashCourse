// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/GCC_PlayerState.h"
#include "AbilitySystemComponent.h"

AGCC_PlayerState::AGCC_PlayerState()
{
	SetNetUpdateFrequency(100.f);

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
}

UAbilitySystemComponent* AGCC_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}