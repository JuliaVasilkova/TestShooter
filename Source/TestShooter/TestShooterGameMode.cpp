// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestShooterGameMode.h"
#include "TestShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestShooterGameMode::ATestShooterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprint/BP_ShooterCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
