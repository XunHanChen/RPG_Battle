// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPG_BattleGameMode.h"
#include "RPG_BattleCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARPG_BattleGameMode::ARPG_BattleGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
