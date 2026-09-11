#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Atajo.generated.h"

UCLASS()
class AVENTURAUSFX022026_API AAtajo : public AActor
{
    GENERATED_BODY()

public:
    AAtajo();

protected:
    virtual void BeginPlay() override;

public:
    // Componente de caja que actúa como Trigger de solapamiento
    UPROPERTY(VisibleAnywhere, Category = "Componentes")
        class UBoxComponent* AroTrigger;

    // Malla visual del portal
    UPROPERTY(VisibleAnywhere, Category = "Componentes")
        class UStaticMeshComponent* MallaPortal;

    // Coordenadas de destino preconfiguradas
    UPROPERTY(EditAnywhere, Category = "Teletransporte")
        FVector PosicionDestino;

    // Función que detecta cuando la pelota cruza el área
    UFUNCTION()
        void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};