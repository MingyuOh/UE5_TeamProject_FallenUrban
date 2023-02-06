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
	UInputAction* AttackAction;

/// <summary>
/// Functions area
/// </summary>
protected:
	virtual void BeginPlay() override;

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	virtual void FKeyPressed();
	virtual void Attack();

	bool EnableAttack();

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
