#include "TestingStatActor.h"

// Sets default values
ATestingStatActor::ATestingStatActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATestingStatActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestingStatActor::Tick(float DeltaTime)
{
	SCOPE_CYCLE_COUNTER(STAT_PerformTick);
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("Test Message on Tick"));
}

