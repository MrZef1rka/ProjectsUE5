// Fill out your copyright notice in the Description page of Project Settings.

#include "CppBaseActor.h"
#include "TimerManager.h"

// Sets default values
ACppBaseActor::ACppBaseActor() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
	
  Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
  SetRootComponent(Mesh);
}

// Called when the game starts or when spawned
void ACppBaseActor::BeginPlay() {
  Super::BeginPlay();
	InitialLocation = GetActorLocation();
}

void ACppBaseActor::ShowInformation() {}

// Called every frame
void ACppBaseActor::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void ACppBaseActor::SinMovement()
{
	switch (MoveType)
	{
	case EMovementState::Sin:
	{
		FVector CurrentLocation = GetActorLocation();
		float Time = GetWorld()->GetTimeSeconds();
		CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * Time);
			
		SetActorLocation(CurrentLocation);
	}
		break;

	case EMovementState::Static: break;
	default: break;	
	}
}
