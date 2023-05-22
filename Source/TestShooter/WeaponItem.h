// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "WeaponItem.generated.h"

/** Rules for attaching components - needs to be kept synced to EDetachmentRule */
UENUM()
enum EWeaponAttachmentRule
{
	/** Setup of collision presets while weapon is in hands */
	InHands,

	/** Setup of collision presets while weapon is not in hands aka detached from actor and dropped down */
	NotInHands
};

UCLASS()
class TESTSHOOTER_API AWeaponItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponItem();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Changes collision presets to NewRules
	UFUNCTION(BlueprintCallable)
	void ChangeCollisionPresets(EWeaponAttachmentRule NewRules);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void Shoot(APawn* TargetActor);

public:

	/** Collision component of item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	class USphereComponent* CollisionComponent;

	/** Collision component of item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mesh)
	class UStaticMeshComponent* MeshComponent;

	/** ABulletActor to spawn while shooting with item */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bullet)
	TSubclassOf<class ABulletActor> BulletActorToSpawn;

	// If weaponItem is in hands or not
	UPROPERTY()
	TEnumAsByte<EWeaponAttachmentRule> AttachmentRules;

};
