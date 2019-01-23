// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"
#include "TorrettaMesh.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class CARRIARMATI_API UTorrettaMesh : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Eleva(float VelRelativa);
	void Ruota(float VelRelativa);
	
	UPROPERTY(EditAnyWhere, Category = "SetUp")
		float ElevazioneMaxSec = 20;

	UPROPERTY(EditAnyWhere, Category = "SetUp")
		float ElevazioneMax = 20;

	UPROPERTY(EditAnyWhere, Category = "SetUp")
		float ElevazioneMin = -5;

	UPROPERTY(EditAnyWhere, Category = "SetUp")
		float RotazioneMaxSec = 25;



};
