// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAICPP.h"

void ATankAICPP::BeginPlay()
{
	Super::BeginPlay();

	auto CarroControllato = GetTank();
	auto Bersaglio = GetPlayerTank();

	if (!CarroControllato || !Bersaglio)  return;

	UE_LOG(LogTemp, Warning, TEXT("Carro nemico:  %s"), *Bersaglio->GetName());
	
}

ATank_CPP* ATankAICPP::GetTank()
{
	return Cast<ATank_CPP>(GetPawn());
}

ATank_CPP* ATankAICPP::GetPlayerTank()
{
	auto Controller = Cast <ATankControllerCPP>(GetWorld()->GetFirstPlayerController());

		return Cast<ATank_CPP>(Controller->GetPawn());

}

void ATankAICPP::Tick(float deltatime)
{
	Super::Tick(deltatime);
	if (GetPlayerTank())
	{
		GetTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}