// Copyright Epic Games, Inc. All Rights Reserved.

#include "NiagaraTestVFXGameMode.h"
#include "NiagaraTestVFXCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANiagaraTestVFXGameMode::ANiagaraTestVFXGameMode()
{
	DefaultPawnClass = ANiagaraTestVFXCharacter::StaticClass();
}
