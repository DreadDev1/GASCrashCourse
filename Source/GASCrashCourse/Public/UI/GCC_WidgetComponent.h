// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "GCC_WidgetComponent.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UGCC_AttributeSet;
class UGCC_AbilitySystemComponent;
class AGCC_BaseCharacter;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class GASCRASHCOURSE_API UGCC_WidgetComponent : public UWidgetComponent
{
	GENERATED_BODY()
public:
	

protected:
	virtual void BeginPlay() override;

private:
	TWeakObjectPtr<AGCC_BaseCharacter> CrashCharacter;
	TWeakObjectPtr<UGCC_AbilitySystemComponent> AbilitySystemComponent;
	TWeakObjectPtr<UGCC_AttributeSet> AttributeSet;

	void InitAbilitySystemData();
	bool IsASCInitialized() const;

	UFUNCTION()
	void OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS);

};
