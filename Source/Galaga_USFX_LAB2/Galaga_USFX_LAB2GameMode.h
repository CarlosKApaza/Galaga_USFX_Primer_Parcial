// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_LAB2GameMode.generated.h"

class ANaveEnemiga;
class ANaveEnemigaCaza;
class ANaveEnemigaTransporte;
class ANaveEnemigaEspia;
class ANaveEnemigaReabastecimiento;
class ANaveEnemigaNodriza;
class ANaveEnemigaKamikaze;
class ABombaTerrestre;

UCLASS(MinimalAPI)
class AGalaga_USFX_LAB2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_USFX_LAB2GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Contenedores avanzados TArrays para almacenar las naves enemigas
	TArray<ANaveEnemiga*> TANavesEnemigas;
	TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	TArray<ANaveEnemigaTransporte*> TANavesEnemigasTransporte;
	TArray<ANaveEnemigaEspia*> TANavesEnemigasEspia;


	// Contenedor avanzado TMap para almacenar las posiciones de las naves enemigas
	UPROPERTY()
	TMap<ANaveEnemiga*, FVector> TMPosicionesNavesEnemigas; // TMap para almacenar los obejtos y las posiciones de las naves enemigas

	
	//void EliminarEnemigosAleatoriamente(); // Función para eliminar enemigos aleatoriamente
	//void CrearEnemigosAleatoriamente(); // Función para crear enemigos aleatoriamente
	void BombaTerrestreAleatoria(); // Función para lanzar bombas terrestres aleatoriamente
	void HacerExplotarBombaTerrestre(); // Función para hacer explotar la bomba terrestre
	void StopGameActions(); // Función para detener todas las acciones
	

public:
	// Timer para controlar la visualización de las posiciones de las naves enemigas
	// Declaraciones de FTimerHandle
	//FTimerHandle FTHEliminarEnemigosAleatorios; // Timer para eliminar enemigos aleatorios
	//FTimerHandle FTHCrearEnemigosAleatorios; // Timer para crear enemigos aleatorios
	FTimerHandle FTHEndGameActions; // Timer para detener todas las acciones
	FTimerHandle FTHLanzarBombaTerrestreAleatorios; // Timer para lanzar bombas terrestres
	FTimerHandle FTHExplotarBombaTerrestre; // Timer para hacer explotar la bomba terrestre

protected:
	// Variable miembro para almacenar la referencia a la bomba terrestre actual
	ABombaTerrestre* BombaTerrestreActual;
};


