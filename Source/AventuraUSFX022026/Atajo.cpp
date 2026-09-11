#include "Atajo.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

AAtajo::AAtajo()
{
    PrimaryActorTick.bCanEverTick = false;

    // Configurar el área de activación
    AroTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("AroTrigger"));
    RootComponent = AroTrigger;
    AroTrigger->SetBoxExtent(FVector(150.f, 150.f, 150.f));
    AroTrigger->SetCollisionProfileName(TEXT("Trigger"));

    // Configurar la malla visual
    MallaPortal = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPortal"));
    MallaPortal->SetupAttachment(RootComponent);

    // Posición exacta de destino solicitada
    PosicionDestino = FVector(291.732727f, -631.481018f, 359.443909f);
}

void AAtajo::BeginPlay()
{
    Super::BeginPlay();

    // Vincular el evento de solapamiento
    AroTrigger->OnComponentBeginOverlap.AddDynamic(this, &AAtajo::OnOverlapBegin);
}

void AAtajo::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // Validar que el actor exista, no sea el portal y tenga físicas activas
    if (OtherActor && OtherActor != this && OtherComp && OtherComp->IsSimulatingPhysics())
    {
        // Limpiar la velocidad para evitar bloqueos de inercia al teletransportar
        OtherComp->SetPhysicsLinearVelocity(FVector::ZeroVector);

        // Mover instantáneamente a la pelota a las coordenadas de destino
        OtherActor->SetActorLocation(PosicionDestino, false, nullptr, ETeleportType::TeleportPhysics);
    }
}