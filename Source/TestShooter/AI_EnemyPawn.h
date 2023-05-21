// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

class UFloatingPawnMovement;
class UPawnSensingComponent;
class UNavigationSystemV1;
class AAIController;

#include "AI_EnemyPawn.generated.h"

UCLASS()
class TESTSHOOTER_API AAI_EnemyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAI_EnemyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Navigation Area to move around. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NavArea)
	UNavigationSystemV1* NavArea;

	/** Any point we choose to move to. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = NavArea)
	FVector RandomLocation;

	/** Movement component for simple Pawn move. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloatingPawnMovement)
	UFloatingPawnMovement* MoveComponent;

	/** SensComponent to look for Player character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PawnSensingComponen)
	UPawnSensingComponent* SensComponent;

	/** Health param to track damage. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EnemyProperties)
	float Health = 50;

	/** Health param to implement progress bar. */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = EnemyProperties)
	float MaxHealth = 50;

	/** If_Enemy_is_dead flag */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = EnemyProperties)
	bool IsDead = false;

	AAIController* EnemyAIController = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Overlap begin delegate
	UFUNCTION(BlueprintCallable)
	virtual void OnEnemySeePawn(APawn* Pawn);

	UFUNCTION(BlueprintCallable)
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	// Moves enemy to random location destination
	UFUNCTION(BlueprintCallable)
	void RandomPatrol();
};
