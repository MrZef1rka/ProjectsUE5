// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometry.h"



DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All)

// Sets default values
ABaseGeometry::ABaseGeometry()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometry::BeginPlay()
{
	Super::BeginPlay();
    
	InitialLocation = GetActorLocation();
	SetColor(GeometryData.Color);
	GetWorldTimerManager().SetTimer(Timer, this, &ABaseGeometry::OnTimer, GeometryData.TimeRate, true);
	OnTimer();
}

// Called every frame
void ABaseGeometry::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	HandleMovement();
}

void ABaseGeometry::HandleMovement()
{
	switch (GeometryData.MoveType)
	{
	case EMovementType::Sin:
		{
			FVector CurrentLocation = GetActorLocation();
			float Time = GetWorld()->GetTimeSeconds();
			CurrentLocation.Z = InitialLocation.Z + GeometryData.Amplitude * FMath::Sin(GeometryData.Frequency * Time);
			
			SetActorLocation(CurrentLocation);
		}
		break;

	case EMovementType::Static: break;
	default: break;	
	}
}

void ABaseGeometry::SetColor(const FLinearColor& Color) const
{
	if (UMaterialInstanceDynamic* DynMaterial = BaseMesh->CreateAndSetMaterialInstanceDynamic(0))
	{
		DynMaterial->SetVectorParameterValue("Color", Color);
	}
}
void ABaseGeometry::OnTimer()
{
	if (++CurrentTimerCount <= MaxTimerCount)
	{
		const FLinearColor NewColor = FLinearColor::MakeRandomColor();
		SetColor(NewColor);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(Timer);
	}
}
void ABaseGeometry::PrintTypes() const
{
	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Weapons: %d, Armor: %i"), Weapon, Armor);
	UE_LOG(LogBaseGeometry, Warning, TEXT("Health: %f"), Health);
	UE_LOG(LogBaseGeometry, Warning, TEXT("IsDead: %d"), isDead);

	FString Name = "User: Sergio";
	UE_LOG(LogBaseGeometry, Display, TEXT("Name: %s"), *Name);
	

	FString WeaponStr = "Weapon = " + FString::FromInt(Weapon);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString isDeadStr = "IsDead = " + FString(isDead ? "true" : "false");

	FString Stat = FString::Printf(TEXT(" \n == All Stat == \n %s \n %s \n %s "), *WeaponStr, *HealthStr, *isDeadStr);
	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *Stat);

	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, *Stat, true, FVector2D(1.0f, 1.0f));
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, Name);
};

void ABaseGeometry::PrintTransform() const
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();
	
	UE_LOG(LogBaseGeometry, Warning, TEXT("Actor name %s"), *GetName());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Transform %s"), *Transform.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Location %s"), *Location.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Rotation %s"), *Rotation.ToString());
	UE_LOG(LogBaseGeometry, Warning, TEXT("Scale %s"), *Scale.ToString());
}

