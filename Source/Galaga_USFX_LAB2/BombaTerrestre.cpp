// Fill out your copyright notice in the Description page of Project Settings.


#include "BombaTerrestre.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"


// Sets default values
ABombaTerrestre::ABombaTerrestre()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaBomba(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Torus.Shape_Torus'"));
	// Create the mesh component
	MallaBomba = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	MallaBomba->SetStaticMesh(mallaBomba.Object);
	MallaBomba->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABombaTerrestre::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABombaTerrestre::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoverBomba(DeltaTime);

}

void ABombaTerrestre::MoverBomba(float DeltaTime)
{
	// Move the bomba
}

