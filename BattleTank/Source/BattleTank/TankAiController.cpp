// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAiController.h"

#include "TankPlayerController.h"
#include "Tank.h"

void ATankAiController::BeginPlay()
{
    Super::BeginPlay();
    auto tank = GetControlledTank();

    if (tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Ai Tank controller possessing %s"), *tank->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Ai Tank controller not possessing anything"));
    }

    auto playerTank = GetPlayerTank();
    if (playerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("Ai Tank controller : player found : %s"), *playerTank->GetName());
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Ai Tank controller : player not found"));
    }
}

void ATankAiController::Tick(float deltaSeconds)
{
    Super::Tick(deltaSeconds);
    // get player controller

    if (auto playerTank = GetPlayerTank())
    {
        if (auto tank = GetControlledTank())
        {
            tank->AimAt(playerTank->GetActorLocation());
        }
    }
}

ATank* ATankAiController::GetPlayerTank() const
{
    ATank * playerTank = nullptr;
    auto playerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
    if (playerController)
    {
        playerTank = playerController->GetControlledTank();
    }

    return playerTank;
}

ATank* ATankAiController::GetControlledTank() const
{
    auto tank = Cast<ATank>(GetPawn());
    return tank;
}

