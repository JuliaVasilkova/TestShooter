// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletActor.h"

#include "AI_EnemyPawn.h"
#include "Item.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ABulletActor::ABulletActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	CollisionComponent->SetupAttachment(RootComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(CollisionComponent);

	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));
	MovementComponent->InitialSpeed = 2000;
	MovementComponent->ProjectileGravityScale = 0;

}

// Called when the game starts or when spawned
void ABulletActor::BeginPlay()
{
	Super::BeginPlay();

	//To make bullets disappear even if they didn't hit anything
	SetLifeSpan(5);
	CollisionComponent->OnComponentBeginOverlap.AddDynamic(this, &ABulletActor::OnBulletBeginOverlap);
}

// Called every frame
void ABulletActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// OnBulletBeginOverlap delegate needs to apply damage after bullet overlaps Enemy Pawn
void ABulletActor::OnBulletBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor != this && OtherActor->ActorHasTag("Enemy") && Cast<AAI_EnemyPawn>(OtherActor) != nullptr)
	{
		AAI_EnemyPawn* Enemy = Cast<AAI_EnemyPawn>(OtherActor);
		UGameplayStatics::ApplyDamage(Enemy, 10.f, GetWorld()->GetFirstPlayerController(), this, UDamageType::StaticClass());
		Destroy();
	}
}

