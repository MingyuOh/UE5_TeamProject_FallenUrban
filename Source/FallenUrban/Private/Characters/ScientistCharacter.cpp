// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/ScientistCharacter.h"
#include "Items/Weapons/ScientistWeapon.h"

AScientistCharacter::AScientistCharacter()
{
	CharacterState = ECharacterState::ECS_Equipped;
}

void AScientistCharacter::BeginPlay()
{
    Super::BeginPlay();

	Weapon = GetWorld()->SpawnActor<AScientistWeapon>(this->GetActorLocation(), this->GetActorRotation());
	if (Weapon)
	{
		Weapon->Equip(this->GetMesh(), FName("WeaponAttachPointR"));
		Weapon->SetActorRelativeScale3D(FVector(0.25f, 0.25f, 0.25f));
	}
}

void AScientistCharacter::Attack()
{
	Super::Attack();

}

void AScientistCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
