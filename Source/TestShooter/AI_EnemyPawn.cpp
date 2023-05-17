// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_EnemyPawn.h"
#include "Perception/PawnSensingComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AAI_EnemyPawn::AAI_EnemyPawn()
{
	Tags.Add(TEXT("Enemy"));

	MoveComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MoveComponent"));
	MoveComponent->MaxSpeed = 100.f;
	MoveComponent->Acceleration = 200.f;

	SensComponent = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("SensComponent"));
	SensComponent->SetPeripheralVisionAngle(45.f);

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAI_EnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAI_EnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAI_EnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

