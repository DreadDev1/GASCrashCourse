// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GCC_AbilitySystemComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASCRASHCOURSE_API UGCC_AbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	virtual void OnGiveAbility(FGameplayAbilitySpec& AbilitySpec) override;
	virtual void OnRep_ActivateAbilities() override;

	UFUNCTION(BlueprintCallable, Category = "Crash|Abilities")
	void SetAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level);

	UFUNCTION(BlueprintCallable, Category = "Crash|Abilities")
	void AddToAbilityLevel(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level = 1);

private:

	void HandleAutoActivatedAbility(const FGameplayAbilitySpec& AbilitySpec);	
};