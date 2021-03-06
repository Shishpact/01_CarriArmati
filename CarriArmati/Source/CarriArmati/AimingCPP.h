// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TorrettaMesh.h"
#include "Proiettile.h"
#include "AimingCPP.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CARRIARMATI_API UAimingCPP : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAimingCPP();

	float ricarica;

	UFUNCTION(BlueprintCallable, Category = "Fuoco")
		void SpawnOggetto();

	UPROPERTY(EditAnywhere, Category = "Firing")
		float VelLancio = 10000;

	AProiettile* Proiettile = nullptr;

	UPROPERTY(EditAnywhere, Category = "fuoco")
		TSubclassOf<class AProiettile> Proiettile_BP;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void MuoviCannone(FVector AimDirection);

	UPROPERTY(EditAnywhere, Category = "SetUp")
		float ricarica_time = 2;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation, float VelLancio);

	void SetCannone(UTorrettaMesh* Set);
	void SetTorre(UTorrettaMesh* Set);
	
	UTorrettaMesh * Cannone = nullptr;
	UTorrettaMesh * Torre = nullptr;

	
};
