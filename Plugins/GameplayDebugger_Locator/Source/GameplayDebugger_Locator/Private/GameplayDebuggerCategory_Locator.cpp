// Copyright Francesco Sapio. All right reserved.

#include "GameplayDebuggerCategory_Locator.h"

#if WITH_GAMEPLAY_DEBUGGER
#include "GameFramework/Actor.h"

FGameplayDebuggerCategory_Locator::FGameplayDebuggerCategory_Locator()
{
	bShowOnlyWithDebugActor = false;
	SetDataPackReplication<FRepData>(&DataPack);
}

void FGameplayDebuggerCategory_Locator::FRepData::Serialize(FArchive& Ar) {
	Ar << ActorLocationString;
}

TSharedRef<FGameplayDebuggerCategory> FGameplayDebuggerCategory_Locator::MakeInstance()
{
	return MakeShareable(new FGameplayDebuggerCategory_Locator());
}

void FGameplayDebuggerCategory_Locator::CollectData(APlayerController * OwnerPC, AActor * DebugActor)
{
	if (DebugActor) {
		DataPack.ActorLocationString = DebugActor->GetActorLocation().ToString();
	}
}

void FGameplayDebuggerCategory_Locator::DrawData(APlayerController * OwnerPC, FGameplayDebuggerCanvasContext & CanvasContext)
{
	CanvasContext.Printf(TEXT("If a DebugActor is selected, here below is its location:"));
	CanvasContext.Printf(TEXT("{cyan}Location: {yellow}%s"), *DataPack.ActorLocationString);
}

#endif
