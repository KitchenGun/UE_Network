// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE5NetworkStudyGameMode.h"
#include "UE5NetworkStudyCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE5NetworkStudyGameMode::AUE5NetworkStudyGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
