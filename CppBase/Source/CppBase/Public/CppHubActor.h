#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppHubActor.generated.h"

class ACppBaseActor;

UCLASS(Blueprintable)
class CPPBASE_API ACppHubActor : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ACppHubActor();

  UPROPERTY(EditAnywhere)
  float SpawnTimerRate = 2.0f;
  UPROPERTY(EditAnywhere)
  float DestroyTimerRate = 1.0f;

  UPROPERTY(EditAnywhere)
  int32 MaxSpawnCount = 10;

  int32 CurrentSpawnCount = 0;

  UPROPERTY(VisibleAnywhere)
  TArray<ACppBaseActor *> SpawnedObjects;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
  TSubclassOf<ACppBaseActor> CppClass;

  FTimerHandle SpawnTimeHandle;
  FTimerHandle DestroyTimeHandle;

  UFUNCTION()
  void OnTimeToSpawn();
  UFUNCTION()
  void OnTimeToDestroy();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;
};
