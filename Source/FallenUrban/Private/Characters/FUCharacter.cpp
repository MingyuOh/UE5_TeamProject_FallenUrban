#include "Characters/FUCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Animation/AnimMontage.h"

#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AFUCharacter::AFUCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.0f);

	FUSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("FUSpringArm"));
	FUSpringArm->SetupAttachment(GetRootComponent());
	FUSpringArm->TargetArmLength = 300.0f;

	ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
	ViewCamera->SetupAttachment(FUSpringArm);

}

void AFUCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(FUContext, 0);
		}
	}
}

void AFUCharacter::Move(const FInputActionValue& Value)
{
	const FVector2D MovementVector = Value.Get<FVector2D>();
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0.0f, Rotation.Yaw, 0.0f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(ForwardDirection, MovementVector.Y);

	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	AddMovementInput(RightDirection, MovementVector.X);
}

void AFUCharacter::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxisVector = Value.Get<FVector2D>();
	AddControllerPitchInput(LookAxisVector.Y);
	AddControllerYawInput(LookAxisVector.X);
}

void AFUCharacter::FKeyPressed()
{
	UE_LOG(LogTemp, Warning, TEXT("[AFUCharacter] FKeyPressed()"));
}

void AFUCharacter::EKeyPressed()
{

}

void AFUCharacter::Attack()
{
	if (EnableAttack())
	{
		PlayAttackMontage();
		ActionState = EActionState::EAS_Attacking;
	}
}

void AFUCharacter::PlayAttackMontage()
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AttackMontage && AnimInstance)
	{
		AnimInstance->Montage_Play(AttackMontage);
		const uint32 Selection = FMath::RandRange(0, 4);
		FName SelectionName = FName();
		switch (Selection)
		{
		case 0:
		{
			SelectionName = FName("Attack1");
		}break;
		case 1:
		{
			SelectionName = FName("Attack2");
		}break;
		case 2:
		{
			SelectionName = FName("Attack3");
		}break;
		case 3:
		{
			SelectionName = FName("Attack4");
		}break;
		default:
		{

		}break;
		}
		AnimInstance->Montage_JumpToSection(SelectionName, AttackMontage);
	}
}

bool AFUCharacter::EnableAttack()
{
	return CharacterState != ECharacterState::ECS_Unequipped
		&& ActionState == EActionState::EAS_Unoccupied;
}

void AFUCharacter::AttackEnd()
{
	ActionState = EActionState::EAS_Unoccupied;
}

void AFUCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFUCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &AFUCharacter::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AFUCharacter::Look);
		EnhancedInputComponent->BindAction(FKeyAction, ETriggerEvent::Triggered, this, &AFUCharacter::FKeyPressed);
		EnhancedInputComponent->BindAction(EKeyAction, ETriggerEvent::Triggered, this, &AFUCharacter::EKeyPressed);
		EnhancedInputComponent->BindAction(AttackAction, ETriggerEvent::Triggered, this, &AFUCharacter::Attack);
	}

}

