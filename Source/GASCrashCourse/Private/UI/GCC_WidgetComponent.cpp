// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GCC_WidgetComponent.h"

#include "AbilitySystem/GCC_AbilitySystemComponent.h"
#include "AbilitySystem/GCC_AttributeSet.h"
#include "Characters/GCC_BaseCharacter.h"


void UGCC_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemData();

	if (!IsASCInitialized())
	{
		CrashCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
	}
}

void UGCC_WidgetComponent::InitAbilitySystemData()
{
	CrashCharacter = Cast<AGCC_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UGCC_AttributeSet>(CrashCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<UGCC_AbilitySystemComponent>(CrashCharacter->GetAbilitySystemComponent());
}

bool UGCC_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UGCC_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UGCC_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UGCC_AttributeSet>(AS);

	// TODO: Check if the Attribute Set has been initialized with the first GE
	// If not, bind to some delegate that will be broadcast when it is initialized.
}

