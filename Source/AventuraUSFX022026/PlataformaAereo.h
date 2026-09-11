// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plataforma.h"
#include "PlataformaAereo.generated.h"

/**
 *
 */
UCLASS()
class AVENTURAUSFX022026_API APlataformaAereo : public APlataforma
{
	GENERATED_BODY()

public:
	APlataformaAereo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int numeroPaso;

};