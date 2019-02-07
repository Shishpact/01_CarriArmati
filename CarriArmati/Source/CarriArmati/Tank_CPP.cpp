// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank_CPP.h"


// Sets default values
ATank_CPP::ATank_CPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Aiming = CreateDefaultSubobject<UAimingCPP>(FName("Componenti"));
	//move = CreateDefaultSubobject<UMovimento>(FName("move"));
}

// Called when the game starts or when spawned
void ATank_CPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank_CPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank_CPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank_CPP::AimAt(FVector HitLocation)
{
	Aiming->AimAt(HitLocation, VelLancio);
}

void ATank_CPP::SetCannone(UTorrettaMesh* Set)
{
	Aiming->SetCannone(Set);
}

void ATank_CPP::SetTorre(UTorrettaMesh* Set)
{
	Aiming->SetTorre(Set);
}

void ATank_CPP::SpawnOggetto()
{
	Aiming->SpawnOggetto();
}