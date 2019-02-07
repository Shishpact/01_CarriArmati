// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "Proiettile.generated.h"

UCLASS()
class CARRIARMATI_API AProiettile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProiettile();
	UPROPERTY(EditAnywhere, Category = "Mesh")
		UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UProjectileMovementComponent *Movimento = nullptr;
	USphereComponent *Sfera = nullptr;

	void Lancio(float speed);
	
};
