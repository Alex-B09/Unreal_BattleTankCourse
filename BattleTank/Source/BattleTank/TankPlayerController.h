// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"

#include "Tank.h"

#include "TankPlayerController.generated.h"

/**
 *
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    ATank* GetControlledTank() const;

    void BeginPlay() override;
    void Tick(float dealtaSeconds) override;

private:
    void AimTowardsCrosshair();
    FVector2D GetCrosshairScreenLocation() const;
    bool GetCrosshairTraceHit(FString &objectHit, FVector & hitLocation) const;

    UPROPERTY(EditAnywhere)
        float mCrosshairX = 0.5f;

    UPROPERTY(EditAnywhere)
        float mCrosshairY = 0.33333f;
};
