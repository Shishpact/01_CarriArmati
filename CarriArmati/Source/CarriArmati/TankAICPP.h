// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank_CPP.h"
#include "Engine/World.h"
#include "TankControllerCPP.h"
#include "TankAICPP.generated.h"

/**
 * 
 */
UCLASS()
class CARRIARMATI_API ATankAICPP : public AAIController
{
	GENERATED_BODY()
	
	
		virtual void BeginPlay() override;
	ATank_CPP* GetTank();
	
	ATank_CPP* GetPlayerTank();

	virtual void Tick(float deltatime) override;

};
