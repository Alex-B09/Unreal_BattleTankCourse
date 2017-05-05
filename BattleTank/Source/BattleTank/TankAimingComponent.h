// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

// forward declaration
class UTankBarrel;

// Holds barrel's changing orientation
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UTankAimingComponent();


public:
    void AimAt(FVector locationToAimTo, float launchSpeed);
    void SetBarrelComponent(UTankBarrel * barrelToSet);

private:
    UTankBarrel * mBarrel = nullptr;
    void MoveBarrelTowards(FVector aimDirection);
};
