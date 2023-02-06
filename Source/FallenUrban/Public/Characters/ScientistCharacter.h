// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/FUCharacter.h"
#include "ScientistCharacter.generated.h"



UCLASS()
class FALLENURBAN_API AScientistCharacter : public AFUCharacter
{
	GENERATED_BODY()
	
protected:
	virtual void Attack() override;

public:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
