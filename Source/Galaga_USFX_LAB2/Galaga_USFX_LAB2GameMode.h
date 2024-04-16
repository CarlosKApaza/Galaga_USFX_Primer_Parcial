// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_USFX_LAB2GameMode.generated.h"

class ANaveEnemiga; // Forward declaration 
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
	TArray<ANaveEnemiga*> TANavesEnemigas; // Crear un TArray para almacenar las naves enemigas



	TArray<ANaveEnemigaCaza*> TANavesEnemigasCaza;
	TArray<ANaveEnemigaTransporte*> TANavesEnemigasTransporte;
	TArray<ANaveEnemigaEspia*> TANavesEnemigasEspia;


	// Contenedor avanzado TMap para almacenar las posiciones de las naves enemigas
	UPROPERTY()
	TMap<ANaveEnemiga*, FVector> TMPosicionesNavesEnemigas; // TMap para almacenar los obejtos y las posiciones de las naves enemigas


	void BombaTerrestreAleatoria(); // Función para lanzar bombas terrestres aleatoriamente
	void HacerExplotarBombaTerrestre(); // Función para hacer explotar la bomba terrestre
	void FinalizarAccicones(); // Función para detener todas las acciones
	
	void DestruirNaveJugador();



public:
	FTimerHandle FTHLFinalizarAccinoes; // Timer para detener todas las acciones
	FTimerHandle FTHLanzarBombaTerrestreAleatorios; // Timer para lanzar bombas terrestres
	FTimerHandle FTHExplotarBombaTerrestre; // Timer para hacer explotar la bomba terrestre
	FTimerHandle FTHExplotarNaveJugador;

protected:
	// Variable miembro para almacenar la referencia a la bomba terrestre actual
	ABombaTerrestre* BombaTerrestreActual; // Crear una referencia a la bomba terrestre actual Para poder acceder a la bomba terrestre actual

};


