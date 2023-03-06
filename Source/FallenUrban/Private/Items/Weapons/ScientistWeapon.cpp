// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Weapons/ScientistWeapon.h"

AScientistWeapon::AScientistWeapon() : AFUWeapon()
{
    // ItemMesh Type = StaticMesh
    static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_ScientistWeapon(TEXT("StaticMesh'/OMG/Assets/Items/Weapons/Meshes/SM_ScientistWeapon_Temp.SM_ScientistWeapon_Temp'"));
    if (SM_ScientistWeapon.Succeeded() && SM_ScientistWeapon.Object)
    {
        ItemMesh->SetStaticMesh(SM_ScientistWeapon.Object);
    }

    // ItemMesh Type: USkeletalMesh
    /* static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_ScientistWeapon(TEXT("SkeletalMesh'/Game/ParagonGadget/Characters/Heroes/Gadget/Meshes/gadget_bot.gadget_bot'"));
    if (SK_ScientistWeapon.Succeeded())
    {
        ItemMesh->SetSkeletalMesh(SK_ScientistWeapon.Object);
    }
    */
    
    static ConstructorHelpers::FObjectFinder<UMaterial> UM_ScientistWeapon(TEXT("Material'/OMG/Assets/Items/Weapons/Materials/M_LightStreams2.M_LightStreams2'"));
    if (UM_ScientistWeapon.Succeeded() && UM_ScientistWeapon.Object)
    {
        ItemMesh->SetMaterial(0, UM_ScientistWeapon.Object);
    }
}
