// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/GCC_WidgetComponent.h"

#include "AbilitySystem/GCC_AbilitySystemComponent.h"
#include "AbilitySystem/GCC_AttributeSet.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/GCC_BaseCharacter.h"
#include "UI/GCC_AttributeWidget.h"


void UGCC_WidgetComponent::BeginPlay()
{
	Super::BeginPlay();

	InitAbilitySystemData();

	if (!IsASCInitialized())
	{
		CrashCharacter->OnASCInitialized.AddDynamic(this, &ThisClass::OnASCInitialized);
		return;
	}

	InitializeAttributeDelegates();
}

void UGCC_WidgetComponent::InitAbilitySystemData()
{
	CrashCharacter = Cast<AGCC_BaseCharacter>(GetOwner());
	AttributeSet = Cast<UGCC_AttributeSet>(CrashCharacter->GetAttributeSet());
	AbilitySystemComponent = Cast<UGCC_AbilitySystemComponent>(CrashCharacter->GetAbilitySystemComponent());
}

bool UGCC_WidgetComponent::IsASCInitialized() const
{
	return AbilitySystemComponent.IsValid() && AttributeSet.IsValid();
}

void UGCC_WidgetComponent::InitializeAttributeDelegates()
{
	if (!AttributeSet->bAttributeInitialized)
	{
		AttributeSet->OnAttributesInitialized.AddDynamic(this, &ThisClass::BindToAttributeChanges);
	}
	else
	{
		BindToAttributeChanges();
	}
}

void UGCC_WidgetComponent::OnASCInitialized(UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	AbilitySystemComponent = Cast<UGCC_AbilitySystemComponent>(ASC);
	AttributeSet = Cast<UGCC_AttributeSet>(AS);

	if (!IsASCInitialized()) return;
	InitializeAttributeDelegates();
}

void UGCC_WidgetComponent::BindToAttributeChanges()
{
	for (const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair : AttributeMap)
	{
		BindWidgetToAttributeChanges(GetUserWidgetObject(), Pair); // for checking the owned widget object.
		
		GetUserWidgetObject()->WidgetTree->ForEachWidget([this, &Pair](UWidget* ChildWidget)
		{
			BindWidgetToAttributeChanges(ChildWidget, Pair);
		});
	}
}

void UGCC_WidgetComponent::BindWidgetToAttributeChanges(UWidget* WidgetObject, const TTuple<FGameplayAttribute, FGameplayAttribute>& Pair) const
{
	UGCC_AttributeWidget* AttributeWidget = Cast<UGCC_AttributeWidget>(WidgetObject);
	if (!IsValid(AttributeWidget)) return; // We only care about CC Attribute Widgets
	if (!AttributeWidget->MatchesAttributes(Pair)) return; // Only subscribe for matching Attributes

	AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get()); // for initial values.

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Key).AddLambda([this, AttributeWidget, &Pair](const FOnAttributeChangeData& AttributeChangeData)
	{
		AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get()); // For changes during the game.
	});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value).AddLambda(
		[this, AttributeWidget, &Pair](const FOnAttributeChangeData& AttributeChangeData)
	{
		AttributeWidget->OnAttributeChange(Pair, AttributeSet.Get()); // For changes during the game.
	});
}

