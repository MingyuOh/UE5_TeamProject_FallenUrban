// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/FUItem.h"
#include "Components/SphereComponent.h"

AFUItem::AFUItem() : RunningTime(0.0f)
{
	PrimaryActorTick.bCanEverTick = true;

	ItemMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
	RootComponent = ItemMesh;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetupAttachment(GetRootComponent());
}

void AFUItem::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFUItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
}

