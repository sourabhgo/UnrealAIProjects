#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyFirstAIController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALAI_API AMyFirstAIController : public AAIController
{
	GENERATED_BODY()

protected:

	//** override the OnPossess function to run the behavior tree.
	void OnPossess(APawn* InPawn) override;
	
};
