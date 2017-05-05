// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    SetActorTickEnabled(true);

    auto tank = GetControlledTank();

    if (tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay : %s"), *tank->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay : invalid tank"));
    }
}


void ATankPlayerController::Tick(float dealtaSeconds)
{
    Super::Tick(dealtaSeconds);
    AimTowardsCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
    auto tank = Cast<ATank>(GetPawn());
    return tank;
}


void ATankPlayerController::AimTowardsCrosshair()
{
    auto controlledTank = GetControlledTank();
    if (controlledTank)
    {
        FVector hitLocation = FVector::ZeroVector;
        FString objectHit = "Nothing";
        if (GetCrosshairTraceHit(objectHit, hitLocation))
        {
            controlledTank->AimAt(hitLocation);
        }

        //UE_LOG(LogTemp, Warning, TEXT("Targetting : %s   Location : %s"), *objectHit, *hitLocation.ToString());
    }
}

bool ATankPlayerController::GetCrosshairTraceHit(FString &objectHit, FVector & hitLocation) const
{
    FHitResult hitResult;
    auto screenPosition = GetCrosshairScreenLocation();
    bool isHit = GetHitResultAtScreenPosition(screenPosition,
                                              ECollisionChannel::ECC_Visibility,
                                              false,
                                              hitResult);
    if (isHit)
    {
        hitLocation = hitResult.Location;
        objectHit = hitResult.GetActor()->GetName();
    }
    return isHit;
}

FVector2D ATankPlayerController::GetCrosshairScreenLocation() const
{
    int32 viewportSizeX;
    int32 viewportSizeY;
    GetViewportSize(viewportSizeX, viewportSizeY);

    return FVector2D(viewportSizeX * mCrosshairX, viewportSizeY * mCrosshairY);
}
