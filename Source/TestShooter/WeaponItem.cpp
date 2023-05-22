// Fill out your copyright notice in the Description page of Project Settings.

#include "WeaponItem.h"

#include "Components/SphereComponent.h"
#include "BulletActor.h"

// Sets default values
AWeaponItem::AWeaponItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(RootComponent);


	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(MeshComponent);

	AttachmentRules = EWeaponAttachmentRule::NotInHands;

}

// Called when the game starts or when spawned
void AWeaponItem::BeginPlay()
{
	Super::BeginPlay();

}

void AWeaponItem::Shoot(APawn* TargetActor)
{
	if (BulletActorToSpawn)
	{
		ABulletActor* Bullet = GetWorld()->SpawnActor<ABulletActor>(BulletActorToSpawn, GetActorTransform());

	}
}

// Setups collision presets for actor and its components to NewRules according to new situation
void AWeaponItem::ChangeCollisionPresets(EWeaponAttachmentRule NewRules)
{
	if (NewRules == EWeaponAttachmentRule::InHands)
	{
		MeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Ignore);

		CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Ignore);
		CollisionComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECollisionResponse::ECR_Ignore);

		AttachmentRules = EWeaponAttachmentRule::InHands;
	}
	else if (NewRules == EWeaponAttachmentRule::NotInHands)
	{
		MeshComponent->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
		MeshComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECollisionResponse::ECR_Block);

		CollisionComponent->SetCollisionResponseToChannel(ECC_WorldStatic, ECollisionResponse::ECR_Block);
		CollisionComponent->SetCollisionResponseToChannel(ECC_Pawn, ECollisionResponse::ECR_Overlap);
		CollisionComponent->SetCollisionObjectType(ECC_WorldDynamic);


		AttachmentRules = EWeaponAttachmentRule::NotInHands;
	}
}

// Called every frame
void AWeaponItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

