// Fill out your copyright notice in the Description page of Project Settings.


#include "GASCrashCourse/Public/Characters/GCC_PlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/GCC_AttributeSet.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/GCC_PlayerState.h"


AGCC_PlayerCharacter::AGCC_PlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 540.f, 0.f);
	GetCharacterMovement()->JumpZVelocity = 500.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
	GetCharacterMovement()->BrakingDecelerationFalling = 1500.f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>("FollowCamera");
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;
}

UAbilitySystemComponent* AGCC_PlayerCharacter::GetAbilitySystemComponent() const
{
	AGCC_PlayerState* GCCPlayerState = Cast<AGCC_PlayerState>(GetPlayerState());
	if (!IsValid(GCCPlayerState)) return nullptr;

	return GCCPlayerState->GetAbilitySystemComponent();
}

UAttributeSet* AGCC_PlayerCharacter::GetAttributeSet() const
{
	AGCC_PlayerState* GCCPlayerState = Cast<AGCC_PlayerState>(GetPlayerState());
	if (!IsValid(GCCPlayerState)) return nullptr;

	return GCCPlayerState->GetAttributeSet();
}

void AGCC_PlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	
	if (!IsValid(GetAbilitySystemComponent()) || !HasAuthority()) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());
	GiveStartupAbilities();
	InitializeAttributes();

	UGCC_AttributeSet* GCC_AttributeSet = Cast<UGCC_AttributeSet>(GetAttributeSet());
	if (!IsValid(GCC_AttributeSet)) return;
	
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(GCC_AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);

}

void AGCC_PlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	
	if (!IsValid(GetAbilitySystemComponent())) return;

	GetAbilitySystemComponent()->InitAbilityActorInfo(GetPlayerState(), this);
	OnASCInitialized.Broadcast(GetAbilitySystemComponent(), GetAttributeSet());

	UGCC_AttributeSet* GCC_AttributeSet = Cast<UGCC_AttributeSet>(GetAttributeSet());
	if (!IsValid(GCC_AttributeSet)) return;
	
	GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(GCC_AttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::OnHealthChanged);

}
