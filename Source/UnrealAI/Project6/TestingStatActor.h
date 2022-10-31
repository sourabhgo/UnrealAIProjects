#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestingStatActor.generated.h"

DECLARE_STATS_GROUP(TEXT("AI_MyCustomGroup"), STATGROUP_AI_MyCustomGroup, STATCAT_Advanced);
DECLARE_CYCLE_STAT(TEXT("StatTestActor ~ PerformTick"), STAT_PerformTick, STATGROUP_AI_MyCustomGroup);

UCLASS()
class UNREALAI_API ATestingStatActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestingStatActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
