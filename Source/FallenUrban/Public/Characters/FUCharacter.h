// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "FUCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
class UAnimMontage;

UCLASS()
class FALLENURBAN_API AFUCharacter : public ACharacter
{
	GENERATED_BODY()

/// <summary>
/// Variables area
/// </summary>
private:
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* FUSpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(EditDefaultsOnly, Category = Montages)
	UAnimMontage* AttackMontage;

protected:
	ECharacterState CharacterState = ECharacterState::ECS_Unequipped;
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputMappingContext* FUContext;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* FKeyAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* EKeyAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* AttackAction;

	UPROPERTY(EditAnywhere, Category = Input)
	UInputAction* JumpAction;

/// <summary>
/// Functions area
/// </summary>
protected:
	virtual void BeginPlay() override;

	virtual void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void FKeyPressed();
	void EKeyPressed();
	virtual void Attack();
	void PlayAttackMontage();

	bool EnableAttack();
	UFUNCTION(BlueprintCallable)
	void AttackEnd();
public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE ECharacterState GetCharacterState() 
	{ 
		return CharacterState; 
	}
public:
	AFUCharacter();

};
