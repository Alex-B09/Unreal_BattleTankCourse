// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "TankBarrel.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
    // off to improve performance if you don't need them.
    PrimaryComponentTick.bCanEverTick = true;

    // ...
}

void UTankAimingComponent::AimAt(FVector locationToAimTo, float launchSpeed)
{
    if (auto owner = GetOwner())
    {

        if (mBarrel)
        {
            FVector launchVelocity;
            FVector startLocation = mBarrel->GetSocketLocation(FName("CanonEnd"));

            bool haveAimTarget = UGameplayStatics::SuggestProjectileVelocity(
                this,
                launchVelocity,
                startLocation,
                locationToAimTo,
                launchSpeed,
                false,
                0,
                0,
                ESuggestProjVelocityTraceOption::DoNotTrace);

            if (haveAimTarget)
            {
                auto aimDirection = launchVelocity.GetSafeNormal();
                MoveBarrelTowards(aimDirection);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("Tank %s aim at FAILLLLLL"),
                       *owner->GetName());
            }

        }
    }
}

void UTankAimingComponent::SetBarrelComponent(UTankBarrel * barrelToSet)
{
    mBarrel = barrelToSet;
}

void UTankAimingComponent::MoveBarrelTowards(FVector aimDirection)
{
    // obtain socket position
    // calculate the angle from socket to destination
    auto barrelRotator = mBarrel->GetForwardVector().Rotation();
    auto aimAsRotator = aimDirection.Rotation();
    auto deltaRotation = aimAsRotator - barrelRotator;

    UE_LOG(LogTemp, Warning, TEXT("Taking aim at %s"), *aimAsRotator.ToString());

    float deltaTime = GetWorld()->DeltaTimeSeconds;

    mBarrel->Elevate(5.f); // todo remove magic number
}