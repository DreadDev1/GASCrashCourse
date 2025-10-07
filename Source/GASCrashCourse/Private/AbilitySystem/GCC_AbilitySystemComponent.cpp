// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/GCC_AbilitySystemComponent.h"

#include "GameplayTags/GCC_Tags.h"

void UGCC_AbilitySystemComponent::OnGiveAbility(FGameplayAbilitySpec& AbilitySpec)
{
	Super::OnGiveAbility(AbilitySpec);
	
	HandleAutoActivatedAbility(AbilitySpec);
}

void UGCC_AbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();

	FScopedAbilityListLock ActiveScopeLock(*this);
	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		HandleAutoActivatedAbility(AbilitySpec);
	}
}

void UGCC_AbilitySystemComponent::HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec)
{
	if (!IsValid(AbilitySpec.Ability)) return;

	for (const FGameplayTag& Tag : AbilitySpec.Ability->GetAssetTags())
	{
		if (Tag.MatchesTagExact(GCCTags::GCCAbilities::ActivateOnGiven))
		{
			TryActivateAbility(AbilitySpec.Handle);
			return;
		}
	}
}
