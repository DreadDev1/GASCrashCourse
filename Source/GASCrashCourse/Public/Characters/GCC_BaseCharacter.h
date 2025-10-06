// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"

#include "GCC_BaseCharacter.generated.h"

UCLASS(Abstract)
class GASCRASHCOURSE_API AGCC_BaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AGCC_BaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
};
