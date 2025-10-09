#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8 { Sin, Static };

UCLASS()
class CPPBASE_API ACppBaseActor : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ACppBaseActor();

  UPROPERTY(VisibleAnywhere)
  UStaticMeshComponent *Mesh;

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ShowInformation();

	UPROPERTY(EditAnywhere, Category = "Movement")
	EMovementState MoveType = EMovementState::Sin;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Amplitude = 50.0f;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency = 2.0f;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

private:
	FVector InitialLocation;	
	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SinMovement();
};

