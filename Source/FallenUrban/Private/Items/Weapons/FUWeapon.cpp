#include "Items/Weapons/FUWeapon.h"

AFUWeapon::AFUWeapon() : AFUItem()
{
}

void AFUWeapon::BeginPlay()
{
}

void AFUWeapon::Equip(USceneComponent* InParent, FName InSocketName)
{
	AttachMeshToSocket(InParent, InSocketName);
	ItemState = EItemState::EIS_Equipped;
}

void AFUWeapon::AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName)
{
	FAttachmentTransformRules AttachmentTransformRules(EAttachmentRule::SnapToTarget, true);
	ItemMesh->AttachToComponent(InParent, AttachmentTransformRules, InSocketName);
}
