// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

class UFloatingPawnMovement;
class UPawnSensingComponent;

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


	/** Movement component for simple Pawn move. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloatingPawnMovement)
	UFloatingPawnMovement* MoveComponent;

	/** Maximum velocity magnitude allowed for the controlled Pawn. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PawnSensingComponen)
	UPawnSensingComponent* SensComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
