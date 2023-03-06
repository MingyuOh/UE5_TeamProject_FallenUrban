// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/FUItem.h"
#include "FUWeapon.generated.h"

class USoundBase;
class UBoxComponent;

UCLASS()
class FALLENURBAN_API AFUWeapon : public AFUItem
{
	GENERATED_BODY()
	
public:
	AFUWeapon();

protected:
	virtual void BeginPlay() override;

public:
	void Equip(USceneComponent* InParent, FName InSocketName);
	void AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName);
};
