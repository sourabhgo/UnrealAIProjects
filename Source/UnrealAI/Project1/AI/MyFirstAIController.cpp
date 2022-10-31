#include "MyFirstAIController.h"
#include "UnrealAICharacter.h"
#include "BehaviorTree/BehaviorTree.h"

void AMyFirstAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AUnrealAICharacter* Character = Cast<AUnrealAICharacter>(InPawn);
	if (Character != nullptr)
	{
		UBehaviorTree* BehaviorTree = Character->BehaviorTree;
		if (BehaviorTree != nullptr) {
			RunBehaviorTree(BehaviorTree);
		}
	}
}