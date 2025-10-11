// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AbilitySystem/GCC_AttributeSet.h"

#include "GCC_AttributeWidget.generated.h"

/**
 * 
 */
UCLASS()
class GASCRASHCOURSE_API UGCC_AttributeWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|Attributes")
	FGameplayAttribute Attribute;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Crash|Attributes")
	FGameplayAttribute MaxAttribute;

	void OnAttributeChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, UGCC_AttributeSet* AttributeSet);
	bool MatchesAttributes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const;

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "On Attribute Change"))
	void BP_OnAttributeChange(float NewValue, float NewMaxValue);
};
