// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectiveZone.h"

#include "Components/BoxComponent.h"
#include "Components/DecalComponent.h"
#include "Dev6Red/Dev6RedCharacter.h"
#include "Dev6Red/Dev6RedGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AObjectiveZone::AObjectiveZone()
{
	
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	OverlapComp->SetBoxExtent(m_BoxSizeExtent);

	RootComponent = OverlapComp;
	OverlapComp->SetHiddenInGame(false);
	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::HandleOverlap);

	//DecalComp
	DecalComp = CreateDefaultSubobject<UDecalComponent>(TEXT("DecalComp"));
	DecalComp->DecalSize = FVector(m_BoxSizeExtent);
	DecalComp->SetupAttachment(RootComponent);
	

}

// Called when the game starts or when spawned
void AObjectiveZone::BeginPlay()
{
	Super::BeginPlay();

	
	
}

void AObjectiveZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Log, TEXT("Overlapped"));

	if(GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green,
			FString::Printf(TEXT("Overlapped")));
	}

	ADev6RedCharacter* MyPawn = Cast<ADev6RedCharacter>(OtherActor);

	if (MyPawn == nullptr)
	{
		return;
	}

	if(MyPawn->bIsCarryObjective)
	{
		ADev6RedGameMode* GM = Cast<ADev6RedGameMode>(GetWorld()->GetAuthGameMode());

		if (GM)
		{
			GM->CompleteMission(MyPawn);
		}
	}
	else
	{
		UGameplayStatics::PlaySound2D(this, ObjectiveMissingSound);
	}
}



