// Fill out your copyright notice in the Description page of Project Settings.

#include "TankControllerCPP.h"

void ATankControllerCPP::BeginPlay()
{
	Super::BeginPlay();

	auto CarroControllato = GetTank();

	if (!CarroControllato)
	{
		UE_LOG(LogTemp, Warning, TEXT("Non ho un tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controllo il tank %s"),*CarroControllato->GetName());
	}
}


void ATankControllerCPP::Tick(float deltatime)
{
	Super::Tick(deltatime);
	Mira();

}

void ATankControllerCPP::Mira()
{
	if (!GetTank()) return;

	FVector Hitlocation;

	if (TrovaVista(Hitlocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Posizione Mirino %s"), *Hitlocation.ToString());
		GetTank()->AimAt(Hitlocation);
	}
}

bool ATankControllerCPP::TrovaVista(FVector& loc)
{
	
	//individuare zona mirata	
	int32 ViewPortX, ViewPortY;
	GetViewportSize(ViewPortX, ViewPortY);

	FVector2D AimOnScreen = (FVector2D(ViewPortX*MirinoX, ViewPortY*MirinoY));

	//convertire zona mirata in un Fvector che miri ad una zona 3d
	//UE_LOG(LogTemp, Warning, TEXT("Posizione schermo %s"), *AimOnScreen.ToString());
	
	FVector Direzione;
	if (TrovaDirezioneVista(AimOnScreen, Direzione)) 
	{
		TrovaHitVista(Direzione, loc);
		return true;
	}

	//creare line trace tra camera e tale punto

	loc = FVector(0,0,0);
	return false;
}

bool ATankControllerCPP::TrovaDirezioneVista(FVector2D Mirino, FVector& DirezioneVista)
{

	FVector WorldLoc;

	return DeprojectScreenPositionToWorld
	(
		Mirino.X,
		Mirino.Y,
		WorldLoc,
		DirezioneVista
	);
}

bool ATankControllerCPP::TrovaHitVista(FVector DirezioneVista, FVector&HitLocation)
{
	auto StartLoc = PlayerCameraManager->GetCameraLocation();
	FHitResult Hit;
	
	FVector EndLoc = DirezioneVista * LineTraceRange + StartLoc;

	if (GetWorld()->LineTraceSingleByChannel
		(
			Hit,
			StartLoc,
			EndLoc,
			ECollisionChannel::ECC_Visibility
		)
	   )
	
	{
		HitLocation = Hit.Location;
		return true;
	}
	return false;

}


ATank_CPP* ATankControllerCPP::GetTank()
{
	return Cast<ATank_CPP>(GetPawn());
}

