// LeaveMeAlone Game by Netologiya. All RightsReserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ALMADefaultCharacter();

protected:
	// Called when the game starts or when spawned

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;
	
	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraSettings")
	float ZoomSpeed = 50.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraSettings")
	float MinZoomDistance = 500.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraSettings")
	float MaxZoomDistance = 1400.0f;
	float CurrentZoomDistance;
	
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float YRotation = -75.0f;
	float ArmLength = 1400.0f;
	float FOV = 55.0f;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void MoveJump(float Value);
	void ZoomCamera(float Value);

};
