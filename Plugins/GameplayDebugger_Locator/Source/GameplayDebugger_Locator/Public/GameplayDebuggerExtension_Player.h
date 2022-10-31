// Copyright Francesco Sapio. All right reserved.

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMEPLAY_DEBUGGER
#include "GameplayDebuggerExtension.h"

/**
 * 
 */
class GAMEPLAYDEBUGGER_LOCATOR_API GameplayDebuggerExtension_Player : public FGameplayDebuggerExtension
{
public:
	GameplayDebuggerExtension_Player();

	//virtual void OnDeactivated() override;
	virtual FString GetDescription() const override;

	static TSharedRef<FGameplayDebuggerExtension> MakeInstance();

protected:

	void PrintPlayerLocation();

	uint32 bHasInputBinding : 1;
	mutable uint32 bIsCachedDescriptionValid : 1;
	mutable FString CachedDescription;

};

#endif
