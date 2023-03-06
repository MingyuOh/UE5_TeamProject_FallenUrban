// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FUItem.generated.h"

class USphereComponent;

enum class EItemState : uint8
{
	EIS_Hovering,
	EIS_Equipped
};

UCLASS()
class FALLENURBAN_API AFUItem : public AActor
{
	GENERATED_BODY()

/// <summary>
/// Variables area
/// </summary>
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

protected:
	EItemState ItemState = EItemState::EIS_Hovering;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly)
	UStaticMeshComponent* ItemMesh;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

/// <summary>
/// Function area
/// </summary>
public:	
	AFUItem();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
