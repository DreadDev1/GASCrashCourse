// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GCC_AttributeWidget.h"

void UGCC_AttributeWidget::OnAttributeChange(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair, UGCC_AttributeSet* AttributeSet)
{
	const float AttributeValue = Pair.Key.GetNumericValue(AttributeSet);
	const float MaxAttributeValue = Pair.Value.GetNumericValue(AttributeSet);

	BP_OnAttributeChange(AttributeValue, MaxAttributeValue);
}

bool UGCC_AttributeWidget::MatchesAttributes(const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	return Attribute == Pair.Key && MaxAttribute == Pair.Value;
}
