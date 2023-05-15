// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"

#include "Components/SphereComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnItemBeginOverlap);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::OnItemBeginOverlap(	UPrimitiveComponent* OverlappedComponent,
										AActor* OtherActor, 
										UPrimitiveComponent* OtherComp, 
										int32 OtherBodyIndex, 
										bool bFromSweep, 
										const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnItemBeginOverlap"));
	//if (OtherActor && this != OtherActor && OtherActor->ActorHasTag("Character"))
	//{
	//	AttachToActor(OtherActor, FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("hand_weapon_s"));
	//}
}

// Changing of mobility
void AItem::UpdateMobility(EComponentMobility::Type NewType)
{
	if (RootComponent->Mobility != NewType)
	{
		RootComponent->SetMobility(NewType);
	}
}

