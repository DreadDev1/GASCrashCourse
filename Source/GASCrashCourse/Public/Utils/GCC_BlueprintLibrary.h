// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AutomationBlueprintFunctionLibrary.h"
#include "GCC_BlueprintLibrary.generated.h"

UENUM(BlueprintType)
enum class EHitDirection : uint8
{
	Left,
	Right,
	Forward,
	Back
};

UCLASS()
class GASCRASHCOURSE_API UGCC_BlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintPure)
	static EHitDirection GetHitDirection(const FVector& TargetForward, const FVector& ToInstigator);

	UFUNCTION(BlueprintPure)
	static FName GetHitDirectionName(const EHitDirection& HitDirection);
};
