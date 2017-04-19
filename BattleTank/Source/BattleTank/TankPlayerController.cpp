// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"


ATank* ATankPlayerController::getControlledTank() const
{
    auto tank = Cast<ATank>(GetPawn());

    return tank;
}

void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();

    auto tank = getControlledTank();

    if (tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay : %s"), *tank->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController BeginPlay : invalid tank"));
    }
}
