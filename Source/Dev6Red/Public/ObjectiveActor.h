// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectiveActor.generated.h"


class USphereComponent;

UCLASS()
class DEV6RED_API AObjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectiveActor();

protected:

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent* SphereComp;

	/*Particle System*/
	UPROPERTY(EditDefaultsOnly, Category="FX")
	UParticleSystem* PickUpFX;

	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PlayEffect();

public:	

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	

};
