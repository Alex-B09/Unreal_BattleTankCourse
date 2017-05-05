// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 *
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
    GENERATED_BODY()

public:
    void Elevate(float degreePerSecond);

private:
    UPROPERTY(EditAnywhere, Category = Setup)
        float mMaxDegreesPerSecond = 20.f;

    UPROPERTY(EditAnywhere, Category = Setup)
        float mMaxElevation = 40.f;

    UPROPERTY(EditAnywhere, Category = Setup)
        float mMinElevation = 0.f;


};
