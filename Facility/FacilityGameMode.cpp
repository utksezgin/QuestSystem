// Copyright Epic Games, Inc. All Rights Reserved.

#include "FacilityGameMode.h"
#include "FacilityHUD.h"
#include "FacilityCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFacilityGameMode::AFacilityGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFacilityHUD::StaticClass();
}
