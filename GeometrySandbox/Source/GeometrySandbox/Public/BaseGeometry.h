// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "TimerManager.h"
#include "BaseGeometry.generated.h"

UENUM(BlueprintType)
enum class EMovementType : uint8
{
	Sin,
	Static
};

USTRUCT(Blueprintable)
struct FGeometryData
{
	GENERATED_USTRUCT_BODY()
    
	// Конструктор для инициализации по умолчанию
	FGeometryData()
		: MoveType(EMovementType::Static)
		, Amplitude(50.0f)
		, Frequency(2.0f)
		, Color(FLinearColor::Blue)
		, TimeRate(3.0f)	
	{}
    
	UPROPERTY(EditAnywhere, Category = "Movement")
	EMovementType MoveType;
    
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Amplitude;
    
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Frequency;
    
	UPROPERTY(EditAnywhere, Category = "Design")
	FLinearColor Color;

	UPROPERTY(EditAnywhere, Category = "Design")
	float TimeRate;
};

UCLASS(Blueprintable, BlueprintType)
class GEOMETRYSANDBOX_API ABaseGeometry : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseGeometry();

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BaseMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Geometry Data")
	FGeometryData GeometryData;
	
	UPROPERTY(EditAnywhere, Category = "Weapons")
	int32 Weapon = 6;
	
	UPROPERTY(EditDefaultsOnly, Category = "Stats")
	int32 Armor = 5;
	
	UPROPERTY(EditInstanceOnly, Category = "Health")
	float Health = 55.55;
	
	UPROPERTY(EditAnywhere, Category = "Health")
	bool isDead = false;
	
	UPROPERTY(VisibleAnywhere, Category = "Weapons")
	bool hasWeapon = true;
	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:
	FVector InitialLocation;
	FTimerHandle Timer;
	const int32 MaxTimerCount = 5;
	int32 CurrentTimerCount = 0;
	void PrintTypes() const;
	void PrintTransform() const;
	auto HandleMovement() -> void;
	void SetColor(const FLinearColor& Color) const;
	void OnTimer();
};


