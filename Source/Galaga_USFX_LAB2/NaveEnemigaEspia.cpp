// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaEspia.h"

void ANaveEnemigaEspia::BeginPlay()
{
	Super::BeginPlay();
}

ANaveEnemigaEspia::ANaveEnemigaEspia()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Wedge_B.Shape_Wedge_B'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);
	VelocidadYEspia = -200.0f;
}

void ANaveEnemigaEspia::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Mover(DeltaTime);
}
void ANaveEnemigaEspia::Mover(float DeltaTime)
{
	//Obtenemos la posición actual del actor
	FVector PosicionActual = GetActorLocation();

	// Generamos nuevas coordenadas X 
	float NuevaX = 0.0f; // No se mueve en el eje X

	// Calculamos la nueva posición en el eje Y
	float NuevaPosicionY = PosicionActual.Y + (VelocidadYEspia * DeltaTime);

	// Verificamos si la nave ha alcanzado el límite superior o inferior
	if (NuevaPosicionY <= -1820.0f)
	{
		// Cambiamos la dirección multiplicando por -1
		VelocidadYEspia *= -1.0f;
	}
	else if (NuevaPosicionY >= 1820.0f)
	{
		// Cambiamos la dirección multiplicando por -1
		VelocidadYEspia *= -1.0f;
	}
	// Establecemos la nueva posición del actor
	SetActorLocation(FVector(PosicionActual.X + NuevaX, NuevaPosicionY, PosicionActual.Z));
}
