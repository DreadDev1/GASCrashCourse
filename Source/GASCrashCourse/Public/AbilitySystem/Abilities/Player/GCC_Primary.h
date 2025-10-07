// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GCC_GamePlayAbility.h"
#include "GCC_Primary.generated.h"




UCLASS()
class GASCRASHCOURSE_API UGCC_Primary : public UGCC_GamePlayAbility
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable, Category = "Crash|Abilities")
	void HitBoxOverlapTest();

private:

	UPROPERTY(EditDefaultsOnly, Category = "Crash|Abilities")
	float HitBoxRadius = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Crash|Abilities")
	float HitBoxForwardOffset = 200.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Crash|Abilities")
	float HitBoxElevationOffset = 20.0f;
};
