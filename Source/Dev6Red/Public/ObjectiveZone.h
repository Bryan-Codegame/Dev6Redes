// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectiveZone.generated.h"

class UBoxComponent;

UCLASS()
class DEV6RED_API AObjectiveZone : public AActor
{
	GENERATED_BODY()

	FVector m_BoxSizeExtent = FVector(200.0f, 200.0f,200.0f);
public:	
	// Sets default values for this actor's properties
	AObjectiveZone();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category="Component")
	UBoxComponent* OverlapComp;

	UPROPERTY(VisibleAnywhere, Category="Component")
	UDecalComponent* DecalComp;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	

};
