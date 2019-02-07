// Fill out your copyright notice in the Description page of Project Settings.

#include "AimingCPP.h"


// Sets default values for this component's properties
UAimingCPP::UAimingCPP()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UAimingCPP::MuoviCannone(FVector AimDirection)
{
	auto Rotazione = Cannone->GetForwardVector().Rotation();
	auto AimRotation = AimDirection.Rotation();
	auto deltarotation = AimRotation - Rotazione;

	Cannone->Eleva(deltarotation.Pitch);

	if (FMath::Abs(deltarotation.Yaw) > 180)
	{
		Torre->Ruota(-deltarotation.Yaw);
	}
	else
	{
		Torre->Ruota(deltarotation.Yaw);
	}
	


	//UE_LOG(LogTemp, Warning, TEXT("Il barrel %s mira a %s"), *Rotazione.ToString(), *AimRotation.ToString());
}

// Called when the game starts
void UAimingCPP::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAimingCPP::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (ricarica > 0) ricarica -= DeltaTime;
	// ...
}

void UAimingCPP::AimAt(FVector HitLocation, float VelLancio)
{
	/*
	UE_LOG(LogTemp, Warning, TEXT("Il carro %s mira a %s con il componente %s"), 
		*GetOwner()->GetName(), 
		*HitLocation.ToString(),
		*Cannone->GetComponentLocation().ToString());
	*/

	FVector Toss;
	FVector Start = Cannone->GetSocketLocation(FName("fuoco"));
	//FCollisionResponseParams fake_param;
	//TArray <AActor*> fake_ignore;


	bool result = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		Toss,
		Start,
		HitLocation,
		VelLancio,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (result)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Sto mirando a %s"), *Toss.ToString());
		FVector AimDirection = Toss.GetSafeNormal();
		//UE_LOG(LogTemp, Warning, TEXT("Sto ruotando di a %s"), *AimDirection.ToString());
		MuoviCannone(AimDirection);
	}
}


void UAimingCPP::SetCannone(UTorrettaMesh* Set)
{
	Cannone = Set;
}

void UAimingCPP::SetTorre(UTorrettaMesh* Set)
{
	Torre = Set;
}

void UAimingCPP::SpawnOggetto()
{
	if (Proiettile_BP)
	{
		if (ricarica <= 0)
		{
			FVector PSparo = Cannone->GetSocketLocation(FName("fuoco"));
			FRotator  RSparo = Cannone->GetSocketRotation(FName("fuoco"));
			auto Proiettile = GetWorld()->SpawnActor<AProiettile>(Proiettile_BP, PSparo, RSparo);
			Proiettile->Lancio(VelLancio);

			ricarica = ricarica_time;
		}
	}
	
}

