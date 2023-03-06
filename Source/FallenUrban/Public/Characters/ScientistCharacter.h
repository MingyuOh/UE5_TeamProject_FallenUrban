// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/FUCharacter.h"
#include "ScientistCharacter.generated.h"

class AScientistWeapon;

UCLASS()
class FALLENURBAN_API AScientistCharacter : public AFUCharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category = Weapon)
	AScientistWeapon* Weapon;
	
public:
	AScientistCharacter();
	
protected:
	virtual void BeginPlay() override;
	virtual void Attack() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
