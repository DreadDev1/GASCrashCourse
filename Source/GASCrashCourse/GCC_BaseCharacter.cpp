// Fill out your copyright notice in the Description page of Project Settings.


#include "GCC_BaseCharacter.h"


// Sets default values
AGCC_BaseCharacter::AGCC_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;
}
