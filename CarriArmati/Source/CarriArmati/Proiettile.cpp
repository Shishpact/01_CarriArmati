// Fill out your copyright notice in the Description page of Project Settings.

#include "Proiettile.h"


// Sets default values
AProiettile::AProiettile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh proiettile"));

	Movimento = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Movimento"));

	Movimento->bAutoActivate = false;

	Sfera = CreateDefaultSubobject<USphereComponent>(FName("Sfera"));
}

// Called when the game starts or when spawned
void AProiettile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AProiettile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AProiettile::Lancio(float speed)
{
	Movimento->SetVelocityInLocalSpace(FVector::ForwardVector*speed);

	Movimento->Activate();

}
