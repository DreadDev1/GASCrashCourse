// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/GCC_GamePlayAbility.h"
#include "GCC_SearchForTarget.generated.h"

namespace EPathFollowingResult { enum Type : int; }

class UAITask_MoveTo;
class AGCC_BaseCharacter;
class UAbilityTask_WaitDelay;
class AGCC_EnemyCharacter;
class AAIController;
class UGCC_WaitGameplayEvent;

UCLASS()
class GASCRASHCOURSE_API UGCC_SearchForTarget : public UGCC_GamePlayAbility
{
	GENERATED_BODY()
public:
	UGCC_SearchForTarget();
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	TWeakObjectPtr<AGCC_EnemyCharacter> OwningEnemy;
	TWeakObjectPtr<AAIController> OwningAIController;
	TWeakObjectPtr<AGCC_BaseCharacter> TargetBaseCharacter;

private:

	UPROPERTY()
	TObjectPtr<UGCC_WaitGameplayEvent> WaitGameplayEventTask;

	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> SearchDelayTask;

	UPROPERTY()
	TObjectPtr<UAbilityTask_WaitDelay> AttackDelayTask;

	UPROPERTY()
	TObjectPtr<UAITask_MoveTo> MoveToLocationOrActorTask;
	
	void StartSearch();

	UFUNCTION()
	void EndAttackEventReceived(FGameplayEventData Payload);

	UFUNCTION()
	void Search();

	void MoveToTargetAndAttack();

	UFUNCTION()
	void AttackTarget(TEnumAsByte<EPathFollowingResult::Type> Result, AAIController* AIController);

	UFUNCTION()
	void Attack();
};
