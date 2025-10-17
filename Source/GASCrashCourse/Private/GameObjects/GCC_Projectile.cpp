// Fill out your copyright notice in the Description page of Project Settings.


#include "GameObjects/GCC_Projectile.h"

#include "AbilitySystemComponent.h"
#include "Characters/GCC_PlayerCharacter.h"
#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
AGCC_Projectile::AGCC_Projectile()
{
	PrimaryActorTick.bCanEverTick = false;

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");

	bReplicates = true;
}

void AGCC_Projectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	AGCC_PlayerCharacter* PlayerCharacter = Cast<AGCC_PlayerCharacter>(OtherActor);
	if (!IsValid(PlayerCharacter)) return;
	if (!PlayerCharacter->IsAlive()) return;
	UAbilitySystemComponent* AbilitySystemComponent = PlayerCharacter->GetAbilitySystemComponent();
	if (!IsValid(AbilitySystemComponent) || !HasAuthority()) return;

	FGameplayEffectContextHandle ContextHandle = AbilitySystemComponent->MakeEffectContext();
	FGameplayEffectSpecHandle SpecHandle = AbilitySystemComponent->MakeOutgoingSpec(DamageEffect, 1, ContextHandle);

	// TODO: Use Damage variable for amount of damage to cause
	AbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

	SpawnImpactEffects();
	Destroy();
}
