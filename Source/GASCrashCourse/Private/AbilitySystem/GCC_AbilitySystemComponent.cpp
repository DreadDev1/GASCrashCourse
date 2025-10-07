// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GCC_AbilitySystemComponent.h"


UGCC_AbilitySystemComponent::UGCC_AbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UGCC_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UGCC_AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
