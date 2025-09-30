// Fill out your copyright notice in the Description page of Project Settings.



#include "Characters/GCC_BaseCharacter.h"



// Sets default values
AGCC_BaseCharacter::AGCC_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}

UAbilitySystemComponent* AGCC_BaseCharacter::GetAbilitySystemComponent() const
{
	return nullptr;
}
