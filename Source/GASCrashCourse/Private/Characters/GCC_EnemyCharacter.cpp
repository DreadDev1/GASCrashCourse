// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/GCC_EnemyCharacter.h"

#include "AbilitySystem/GCC_AbilitySystemComponent.h"
#include "AbilitySystem/GCC_AttributeSet.h"


AGCC_EnemyCharacter::AGCC_EnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	AbilitySystemComponent = CreateDefaultSubobject<UGCC_AbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UGCC_AttributeSet>("AttributeSet");
}

UAbilitySystemComponent* AGCC_EnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAttributeSet* AGCC_EnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void AGCC_EnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(this, this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());

	if (!HasAuthority()) return;

	GiveStartupAbilities();
	InitializeAttributes();

	UGCC_AttributeSet* GCC_AttributeSet = Cast<UGCC_AttributeSet>(GetAttributeSet());
	if (!IsValid(GCC_AttributeSet)) return;
	
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(GCC_AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);
}
