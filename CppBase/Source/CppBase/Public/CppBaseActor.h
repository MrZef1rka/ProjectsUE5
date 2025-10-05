#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EMovementState : uint8 { Mobility, Static };

USTRUCT(BlueprintType)
struct FTransformStruct {
  GENERATED_USTRUCT_BODY()

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector CurrentLocation = FVector::ZeroVector;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FRotator CurrentRotation = FRotator::ZeroRotator;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

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

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

private:
  UPROPERTY(EditAnywhere)
  int32 EnemyCount;

  UPROPERTY(EditAnywhere)
  bool bIsAlive;
};
