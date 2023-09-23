// Copyright Epic Games, Inc. All Rights Reserved.

#include "Dev6RedGameMode.h"
#include "Dev6RedCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADev6RedGameMode::ADev6RedGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void ADev6RedGameMode::CompleteMission(APawn* Pawn)
{
	if (Pawn)
	{
		Pawn->DisableInput(nullptr);
	}

	OnMissionComplete(Pawn);
}
