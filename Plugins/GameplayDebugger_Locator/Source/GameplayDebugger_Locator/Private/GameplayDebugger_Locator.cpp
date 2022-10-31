// Copyright 2019 Francesco Sapio. All right reserved.

#include "GameplayDebugger_Locator.h"

#if WITH_GAMEPLAY_DEBUGGER
#include "GameplayDebugger.h"
#include "GameplayDebuggerCategory_Locator.h"
#include "GameplayDebuggerExtension_Player.h"
#endif

#define LOCTEXT_NAMESPACE "FGameplayDebugger_LocatorModule"

void FGameplayDebugger_LocatorModule::StartupModule()
{

#if WITH_GAMEPLAY_DEBUGGER

	UE_LOG(LogTemp, Warning, TEXT("Locator Module Loaded"));

	if (IGameplayDebugger::IsAvailable())
	{
		IGameplayDebugger& GameplayDebugger = IGameplayDebugger::Get();

		GameplayDebugger.RegisterExtension("Player", IGameplayDebugger::FOnGetExtension::CreateStatic(&GameplayDebuggerExtension_Player::MakeInstance));

		GameplayDebugger.NotifyExtensionsChanged();

		GameplayDebugger.RegisterCategory("Locator", IGameplayDebugger::FOnGetCategory::CreateStatic(&FGameplayDebuggerCategory_Locator::MakeInstance), EGameplayDebuggerCategoryState::EnabledInGameAndSimulate);

		GameplayDebugger.NotifyCategoriesChanged();

		UE_LOG(LogTemp, Warning, TEXT("GameplayDebugger Registered"));
	}

#endif
}

void FGameplayDebugger_LocatorModule::ShutdownModule()
{

#if WITH_GAMEPLAY_DEBUGGER

	if (IGameplayDebugger::IsAvailable())
	{
		IGameplayDebugger& GameplayDebugger = IGameplayDebugger::Get();

		GameplayDebugger.UnregisterExtension("Player");

		GameplayDebugger.NotifyExtensionsChanged();

		GameplayDebugger.UnregisterCategory("Locator");

		GameplayDebugger.NotifyCategoriesChanged();

	}
#endif
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGameplayDebugger_LocatorModule, GameplayDebugger_Locator)