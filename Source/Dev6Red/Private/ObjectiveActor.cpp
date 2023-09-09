// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveActor.h"

#include "Components/SphereComponent.h"
#include "Dev6Red/Dev6RedCharacter.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AObjectiveActor::AObjectiveActor()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToChannels(ECR_Ignore);
	SphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	SphereComp->SetupAttachment(MeshComp);

}

// Called when the game starts or when spawned
void AObjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObjectiveActor::PlayEffect()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), PickUpFX, GetActorLocation());
}


void AObjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	PlayEffect();

	ADev6RedCharacter* MyCharacter = Cast<ADev6RedCharacter>(OtherActor);

	if(MyCharacter)
	{
		MyCharacter->bIsCarryObjective = true;
		Destroy();
	}
}

