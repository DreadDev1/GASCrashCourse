// Fill out your copyright notice in the Description page of Project Settings.


#include "GASCrashCourse/Public/Characters/GCC_BaseCharacter.h"


// Sets default values
AGCC_BaseCharacter::AGCC_BaseCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	GetMesh()->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::AlwaysTickPoseAndRefreshBones;

}
