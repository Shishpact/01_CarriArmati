    // Fill out your copyright notice in the Description page of Project Settings.

#include "Movimento.h"

void UMovimento::IntenzioneAvanti(float movimento)
{
	//UE_LOG(LogTemp, Warning, TEXT("mov avanti %f"), movimento);
	DxC->RichiestaMovimento(movimento);
	SxC->RichiestaMovimento(movimento);
}


void UMovimento::IntenzioneLaterale(float movimento)
{
	//UE_LOG(LogTemp, Warning, TEXT("mov laterale %f"), movimento);
	DxC->RichiestaMovimento(-movimento);
	SxC->RichiestaMovimento(movimento);
}

void UMovimento::Inizialize(UMeshCingolo* DxTrack, UMeshCingolo* SxTrack)
{
	if (!DxTrack || !SxTrack) return;

	DxC = DxTrack;
	SxC = SxTrack;
}

void UMovimento::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	FVector AIForwardIntention = MoveVelocity.GetSafeNormal();
	FVector TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();

	//UE_LOG(LogTemp, Error, TEXT("%s va in direzione %s "), *GetOwner()->GetName(), *MoveVelocity.GetSafeNormal().ToString());

	float MuoviDiritto = FVector::DotProduct(TankForward, AIForwardIntention);
	IntenzioneAvanti(MuoviDiritto);

	float MuoviLaterale = FVector::CrossProduct(TankForward, AIForwardIntention).Z;
	IntenzioneLaterale(MuoviLaterale);
}