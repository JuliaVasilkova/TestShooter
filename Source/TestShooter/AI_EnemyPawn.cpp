// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_EnemyPawn.h"
#include "Perception/PawnSensingComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/Actor.h"
#include "TestShooterCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "NavigationSystem.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIController.h"
#include "AITypes.h"

// Sets default values
AAI_EnemyPawn::AAI_EnemyPawn()
{

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

	Tags.Add(FName("Enemy"));

	if (SensComponent)
	{
		SensComponent->OnSeePawn.AddDynamic(this, &AAI_EnemyPawn::OnEnemySeePawn);
	}

	NavArea = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
	EnemyAIController = Cast<AAIController>(GetController());
}

// Called every frame
void AAI_EnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

/** AI Delegate to find player and move to him as simple implementation of simple AI enemy logic*/
void AAI_EnemyPawn::OnEnemySeePawn(APawn* Pawn)
{
	if (!IsDead && Cast<ATestShooterCharacter>(Pawn) != nullptr)
	{
		EPathFollowingRequestResult::Type Result = EnemyAIController->MoveToActor(Pawn, 50.f, true);
		if (Result == EPathFollowingRequestResult::AlreadyAtGoal)
		{
			ATestShooterCharacter* PlayerPawn = Cast<ATestShooterCharacter>(Pawn);
			UGameplayStatics::ApplyDamage(PlayerPawn, 10.f, PlayerPawn->GetController(), this, UDamageType::StaticClass());
		}
	}
}

float AAI_EnemyPawn::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Health -= Damage;

	if (Health <= 0)
	{
		IsDead = true;
		this->Destroy();
	}

	return Damage;
}

void AAI_EnemyPawn::RandomPatrol()
{
	if (NavArea)
	{
		NavArea->K2_GetRandomReachablePointInRadius(GetWorld(), GetActorLocation(), RandomLocation, 15000.0f);
		EnemyAIController->MoveToLocation(RandomLocation);
	}
}