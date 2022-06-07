// Copyright Epic Games, Inc. All Rights Reserved.

#include "NiagaraTestVFXGameMode.h"
#include "NiagaraTestVFXCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANiagaraTestVFXGameMode::ANiagaraTestVFXGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
