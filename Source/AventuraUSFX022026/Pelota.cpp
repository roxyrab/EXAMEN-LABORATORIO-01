#include "Pelota.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystem.h"
#include "UObject/ConstructorHelpers.h"

APelota::APelota()
{
    PrimaryActorTick.bCanEverTick = true;

    // Crear y establecer la malla como componente raíz
    MallaPelota = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaPelota"));
    RootComponent = MallaPelota;

    // Habilitar físicas y eventos de impacto rígido
    MallaPelota->SetSimulatePhysics(true);
    MallaPelota->SetNotifyRigidBodyCollision(true);
    MallaPelota->SetCollisionProfileName(TEXT("PhysicsActor"));
    MallaPelota->BodyInstance.bNotifyRigidBodyCollision = true;

    // Opcional: Asegura que mantenga elasticidad si el material físico lo permite
    MallaPelota->SetEnableGravity(true);

    // CARGAR EL SONIDO DESDE CÓDIGO
    static ConstructorHelpers::FObjectFinder<USoundBase> AssetSonido(TEXT("/Game/StarterContent/Audio/Explosion02.Explosion02"));
    if (AssetSonido.Succeeded())
    {
        SonidoGolpe = AssetSonido.Object;
    }

    // CARGAR LA PARTÍCULA DESDE CÓDIGO
    static ConstructorHelpers::FObjectFinder<UParticleSystem> AssetParticula(TEXT("/Game/StarterContent/Particles/P_Explosion.P_Explosion"));
    if (AssetParticula.Succeeded())
    {
        ParticulaGolpe = AssetParticula.Object;
    }
}

void APelota::BeginPlay()
{
    Super::BeginPlay();

    // Vincular el evento de colisión de la pelota con nuestra función de efectos
    MallaPelota->OnComponentHit.AddDynamic(this, &APelota::OnPelotaHit);
}

void APelota::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APelota::OnPelotaHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // Reproducir el sonido cargado en el constructor
    if (SonidoGolpe)
    {
        UGameplayStatics::PlaySoundAtLocation(this, SonidoGolpe, Hit.ImpactPoint);
    }

    // Reproducir la partícula cargada en el constructor (Usando directamente la variable miembro)
    if (ParticulaGolpe)
    {
        UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ParticulaGolpe, Hit.ImpactPoint, FRotator::ZeroRotator, FVector(0.5f));
    }
}
