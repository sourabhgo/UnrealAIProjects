#include "LoggingActor.h"
#include "UnrealAI.h"

// Sets default values
ALoggingActor::ALoggingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALoggingActor::BeginPlay()
{
	Super::BeginPlay();

	//if (GEngine) {
	//	GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::Turquoise, TEXT("Some text to Display"));
	//}
	//UE_LOG(LogTemp, Warning, TEXT("Message to Display"));
	UE_LOG(MyAwesomeAILogCategory, Log, TEXT("I am logged from a custom Category!"));
}

// Called every frame
void ALoggingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

