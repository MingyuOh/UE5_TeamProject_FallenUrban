// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/FUAnimInstance.h"
#include "Characters/FUCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UFUAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	FUCharacter = Cast<AFUCharacter>(TryGetPawnOwner());
	if (FUCharacter)
	{
		FUCharacterMovement = FUCharacter->GetCharacterMovement();
	}

}

void UFUAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (FUCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(FUCharacterMovement->Velocity);
		CharacterState = FUCharacter->GetCharacterState();
	}
}
