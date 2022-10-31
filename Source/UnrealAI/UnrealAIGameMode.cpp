#include "UnrealAIGameMode.h"
#include "UnrealAICharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnrealAIGameMode::AUnrealAIGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
