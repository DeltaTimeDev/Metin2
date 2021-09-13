// Copyright Epic Games, Inc. All Rights Reserved.

#include "Metin2GameMode.h"
#include "Metin2Character.h"
#include "UObject/ConstructorHelpers.h"

AMetin2GameMode::AMetin2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
