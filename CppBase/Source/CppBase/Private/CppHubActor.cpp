// Fill out your copyright notice in the Description page of Project Settings.

#include "CppHubActor.h"
#include "CppBaseActor.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
ACppHubActor::ACppHubActor() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACppHubActor::BeginPlay() {
  Super::BeginPlay();

  GetWorldTimerManager().SetTimer(SpawnTimeHandle, this, &ACppHubActor::OnTimeToSpawn, SpawnTimerRate, true);
  GetWorldTimerManager().SetTimer(DestroyTimeHandle, this, &ACppHubActor::OnTimeToDestroy, DestroyTimerRate, true);
}

// Called every frame
void ACppHubActor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void ACppHubActor::OnTimeToSpawn() {
  if (++CurrentSpawnCount <= MaxSpawnCount) {
    const FVector Location = GetActorLocation() + FVector(FMath::FRandRange(200.f, 1000.f), FMath::FRandRange(200.f, 1000.f), 0.f);
    const FRotator Rotation = FRotator::ZeroRotator;
    ACppBaseActor *SpawnObject = GetWorld()->SpawnActor<ACppBaseActor>(CppClass, Location, Rotation);

    if (SpawnObject) {
      SpawnedObjects.Add(SpawnObject);
    }
  } else {
    GetWorldTimerManager().ClearTimer(SpawnTimeHandle);
    for (int i = MaxSpawnCount; i >= 1; --i) {
      GetWorldTimerManager().SetTimer(DestroyTimeHandle, this, &ACppHubActor::OnTimeToDestroy, DestroyTimerRate, true);
    }
  }
}

void ACppHubActor::OnTimeToDestroy() {
  if (!SpawnedObjects.IsEmpty()) {
    SpawnedObjects.Top()->Destroy();
    SpawnedObjects.Pop(0);
  } else {
    GetWorldTimerManager().ClearTimer(DestroyTimeHandle);
  }
}
