// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "Item.generated.h"

UCLASS()
class TESTSHOOTER_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Overlap begin delegate
	UFUNCTION()
	virtual void OnItemBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void UpdateMobility(EComponentMobility::Type NewType);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	/** Collision component of item */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Mesh)
	class USphereComponent* CollisionComponent;

};
