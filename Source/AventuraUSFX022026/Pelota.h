#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pelota.generated.h"

UCLASS()
class AVENTURAUSFX022026_API APelota : public AActor
{
    GENERATED_BODY()

public:
    APelota();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Componente de malla para la pelota
    UPROPERTY(VisibleAnywhere, Category = "Componentes")
        class UStaticMeshComponent* MallaPelota;

    UPROPERTY()
        class USoundBase* SonidoGolpe;

    UPROPERTY()
        class UParticleSystem* ParticulaGolpe;

    // Función que maneja los dos efectos de colisión al golpear algo
    UFUNCTION()
        void OnPelotaHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};