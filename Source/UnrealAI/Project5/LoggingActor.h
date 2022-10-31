#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoggingActor.generated.h"

UCLASS()
class UNREALAI_API ALoggingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoggingActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
