// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AimingCPP.h"
#include "Movimento.h"
#include "Tank_CPP.generated.h"

UCLASS()
class CARRIARMATI_API ATank_CPP : public APawn
{
	GENERATED_BODY()


	FORCEINLINE UTorrettaMesh* GetCannone()
	{
		return Cannone;

	}

	

public:
	// Sets default values for this pawn's properties
	ATank_CPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Componenti")
		UAimingCPP* Aiming;

	UFUNCTION(BlueprintCallable, Category = "SetUp")
		void SetCannone(UTorrettaMesh* Set);

	UFUNCTION(BlueprintCallable, Category = "SetUp")
		void SetTorre(UTorrettaMesh* Set);

	

	UTorrettaMesh* Cannone = nullptr;
	UTorrettaMesh* Torre = nullptr;

	UPROPERTY(EditAnywhere,Category = "Firing")
		float VelLancio = 100000;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);
	void SpawnOggetto();

	//UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "SetUp")
		//UMovimento* move = nullptr;

};
