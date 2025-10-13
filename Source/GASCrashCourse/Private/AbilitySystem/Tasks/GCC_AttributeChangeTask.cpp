// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Tasks/GCC_AttributeChangeTask.h"
#include "AbilitySystemComponent.h"

UGCC_AttributeChangeTask* UGCC_AttributeChangeTask::ListenForAttributeChange( UAbilitySystemComponent* AbilitySystemComponent, FGameplayAttribute Attribute)
{
	UGCC_AttributeChangeTask* WaitForAttributeChangeTask = NewObject<UGCC_AttributeChangeTask>();
	WaitForAttributeChangeTask->ASC = AbilitySystemComponent;
	WaitForAttributeChangeTask->AttributeToListenFor = Attribute;

	if (!IsValid(AbilitySystemComponent))
	{
		WaitForAttributeChangeTask->RemoveFromRoot();
		return nullptr;
	}

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(WaitForAttributeChangeTask, &UGCC_AttributeChangeTask::AttributeChanged);

	return WaitForAttributeChangeTask;
}

void UGCC_AttributeChangeTask::EndTask()
{
	if (ASC.IsValid())
	{
		ASC->GetGameplayAttributeValueChangeDelegate(AttributeToListenFor).RemoveAll(this);
	}

	SetReadyToDestroy();
	MarkAsGarbage();
}

void UGCC_AttributeChangeTask::AttributeChanged(const FOnAttributeChangeData& Data)
{
	OnAttributeChanged.Broadcast(Data.Attribute, Data.NewValue, Data.OldValue);
}
