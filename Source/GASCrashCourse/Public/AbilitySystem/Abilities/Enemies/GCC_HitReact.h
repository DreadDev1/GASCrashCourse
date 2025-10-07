// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GCC_GamePlayAbility.h"
#include "GCC_HitReact.generated.h"

/**
 * 
 */
UCLASS()
class GASCRASHCOURSE_API UGCC_HitReact : public UGCC_GamePlayAbility
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Crash|Abilities")
	void CacheHitDirectionVectors(AActor* Instigator);

	UPROPERTY(BlueprintReadOnly, Category = "Crash|Abilities")
	FVector AvatarForward;

	UPROPERTY(BlueprintReadOnly, Category = "Crash|Abilities")
	FVector ToInstigator;
};
