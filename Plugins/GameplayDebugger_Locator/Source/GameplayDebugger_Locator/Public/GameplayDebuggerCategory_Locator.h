// Copyright 2019 Francesco Sapio. All right reserved.

#pragma once

#include "CoreMinimal.h"

#if WITH_GAMEPLAY_DEBUGGER

#include "GameplayDebuggerCategory.h"

class FGameplayDebuggerCategory_Locator : public FGameplayDebuggerCategory
{

protected:
	struct FRepData
	{
		FString ActorLocationString;

		void Serialize(FArchive& Ar);
	};

	FRepData DataPack;

public:

	FGameplayDebuggerCategory_Locator();

	static TSharedRef<FGameplayDebuggerCategory> MakeInstance();

	virtual void CollectData(APlayerController* OwnerPC, AActor* DebugActor) override;

	virtual void DrawData(APlayerController* OwnerPC, FGameplayDebuggerCanvasContext& CanvasContext) override;


};

#endif