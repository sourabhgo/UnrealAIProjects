// Copyright 2019 Francesco Sapio. All right reserved.

#include "GameplayDebuggerExtension_Player.h"

#if WITH_GAMEPLAY_DEBUGGER
#include "InputCoreTypes.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
//#include "GameplayDebuggerPlayerManager.h"
//#include "Engine/Engine.h"

GameplayDebuggerExtension_Player::GameplayDebuggerExtension_Player()
{
	const FGameplayDebuggerInputHandlerConfig KeyConfig(TEXT("PrintPlayer"), EKeys::NumLock.GetFName());
	bHasInputBinding = BindKeyPress(KeyConfig, this, &GameplayDebuggerExtension_Player::PrintPlayerLocation);
}

FString GameplayDebuggerExtension_Player::GetDescription() const
{
	if (!bIsCachedDescriptionValid)
	{
		CachedDescription = !bHasInputBinding ? FString() :
			FString::Printf(TEXT("{%s}%s:{%s}Player"),
				*FGameplayDebuggerCanvasStrings::ColorNameInput,
				*GetInputHandlerDescription(0),
				*FGameplayDebuggerCanvasStrings::ColorNameEnabled);

		bIsCachedDescriptionValid = true;
	}

	return CachedDescription;
}

TSharedRef<FGameplayDebuggerExtension> GameplayDebuggerExtension_Player::MakeInstance()
{
	return MakeShareable(new GameplayDebuggerExtension_Player());
}

void GameplayDebuggerExtension_Player::PrintPlayerLocation()
{
	UE_LOG(LogTemp, Warning, TEXT("Player's Location: %s"), *GetPlayerController()->GetPawn()->GetActorLocation().ToString());
}

#endif