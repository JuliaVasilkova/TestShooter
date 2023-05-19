// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class USphereComponent;
class UStaticMeshComponent;
class AAI_EnemyPawn;
class UProjectileMovementComponent;

#include "BulletActor.generated.h"

UCLASS()
class TESTSHOOTER_API ABulletActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABulletActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Overlap begin delegate
	UFUNCTION(BlueprintCallable)
	virtual void OnBulletBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** AAI_EnemyPawn. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Classes)
	TSubclassOf<AAI_EnemyPawn> SubclassOfEnemyPawn;

	/** Collision component of item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	USphereComponent* CollisionComponent;

	/** Collision component of item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	UStaticMeshComponent* MeshComponent;

	/** Collision component of item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	UProjectileMovementComponent* MovementComponent;

};
