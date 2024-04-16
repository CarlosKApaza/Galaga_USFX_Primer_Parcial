// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_USFX_LAB2GameMode.h"
#include "Galaga_USFX_LAB2Pawn.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaReabastecimiento.h"
#include "NaveEnemigaNodriza.h"
#include "NaveEnemigaKamikaze.h"
#include "BombaTerrestre.h"
#include "Engine/Engine.h" // Aseg�rate de incluir esto para acceder a GEngine

AGalaga_USFX_LAB2GameMode::AGalaga_USFX_LAB2GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_USFX_LAB2Pawn::StaticClass();
}

void AGalaga_USFX_LAB2GameMode::BeginPlay()
{
	Super::BeginPlay();

	//Rotacion de las naves enemigas
	FRotator rotacionNave = FRotator(0.0f, 0.0f, 0.0f);

	//Ubicacion inicial de las naves enemigas
	FVector ubicacionNaveInicial = FVector(-380.0f, -200.0f, 180.0f); //-200 porque quiero que mi primera nave se cree a partir desde el punto medio un poco mas a la izquierda
	FVector ubicacionNaveActual = ubicacionNaveInicial;
	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		//spawenado las naves de la clase NaveEnemigaCaza con un ciclo
		for (int i = 0; i < 7; i++) { // Crear 10 naves de la clase NaveEnemigaCaza
			ubicacionNaveActual.Y += 180.0f; // Sumar 190 unidades a la coordenada Y en cada iteraci�n (los espacios por naves)
			ANaveEnemigaCaza* NaveEnemigaCazaActual = World->SpawnActor<ANaveEnemigaCaza>(ubicacionNaveActual, rotacionNave);
			//NaveEnemigaCazaActual->SetNombre("Nave Enemiga Caza" + FString::FromInt(i + 1));
			TANavesEnemigas.Add(NaveEnemigaCazaActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaCazaActual, ubicacionNaveActual);
		}

		// Actualizar la ubicaci�n inicial para las naves de la clase NaveEnemigaTransporte
		ubicacionNaveActual.X = ubicacionNaveInicial.X = -70.0f; // crear un fila por el medio
		ubicacionNaveActual.Y = ubicacionNaveInicial.Y = -200.0f; // actualizo la creacion de la nave desde la ubicacionNaveActual

		for (int j = 0; j < 7; j++) { // Crear 10 naves de la clase NaveEnemigaTransporte
			ubicacionNaveActual.Y += 180.0f; // Sumar 190 unidades a la coordenada Y en cada iteraci�n (los espacios por naves)
			ANaveEnemigaTransporte* NaveEnemigaTransporteActual = World->SpawnActor<ANaveEnemigaTransporte>(ubicacionNaveActual, rotacionNave);
			TANavesEnemigas.Add(NaveEnemigaTransporteActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaTransporteActual, ubicacionNaveActual);
		}
		// Actualizar la ubicaci�n inicial para las naves de la clase NaveEnemigaEspia
		ubicacionNaveActual.X = ubicacionNaveInicial.X = 270.0f; // crear un fila m�s arriba
		ubicacionNaveActual.Y = ubicacionNaveInicial.Y = -200.0f; // actualizo la creacion de la nave desde la ubicacionNaveActual

		for (int k = 0; k < 7; k++) { // Crear 10 naves de la clase NaveEnemigaEspia
			ubicacionNaveActual.Y += 180.0f; // Sumar 190 unidades a la coordenada Y en cada iteraci�n (los espacios por naves)
			ANaveEnemigaEspia* NaveEnemigaEspiaActual = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNaveActual, rotacionNave);
			TANavesEnemigas.Add(NaveEnemigaEspiaActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaEspiaActual, ubicacionNaveActual);
		}
		

		// Temporizador para lanzar bombas terrestres aleatorias despu�s de 10 segundos
		GetWorldTimerManager().SetTimer(FTHLanzarBombaTerrestreAleatorios, this, &AGalaga_USFX_LAB2GameMode::BombaTerrestreAleatoria, 6.0f, true);
	
		// Configurar temporizador para hacer explotar la bomba terrestre despu�s de 40 segundos
		GetWorldTimerManager().SetTimer(FTHExplotarBombaTerrestre, this, &AGalaga_USFX_LAB2GameMode::HacerExplotarBombaTerrestre, 8.0f, true, 8.0f);

		// Configurar temporizador para detener todas las acciones despu�s de 120 segundos
		GetWorldTimerManager().SetTimer(FTHLFinalizarAccinoes, this, &AGalaga_USFX_LAB2GameMode::FinalizarAccicones, 120.0f, false);

		// Configurar temporizador para hacer explotar a la navejugador 
		GetWorldTimerManager().SetTimer(FTHExplotarNaveJugador, this, &AGalaga_USFX_LAB2GameMode::DestruirNaveJugador, 10, false);

	}
}

void AGalaga_USFX_LAB2GameMode::FinalizarAccicones()
{
	// Detener todas las acciones
	GetWorldTimerManager().ClearTimer(FTHLanzarBombaTerrestreAleatorios); // Detiene el lanzamiento de bombas terrestres aleatorias despu�s de 40 segundos
	GetWorldTimerManager().ClearTimer(FTHExplotarBombaTerrestre); // Detiene la explosi�n de bombas terrestres despu�s de 40 segundos
	GetWorldTimerManager().ClearTimer(FTHExplotarNaveJugador);

}

void AGalaga_USFX_LAB2GameMode::DestruirNaveJugador()
{
	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController(); // se obtiene el controlador de la nave en el juego con GetFirstPlayerController()
	if (PlayerController) // verificamos que no es un puntero nulo 
	{
		AGalaga_USFX_LAB2Pawn* Jugador = Cast<AGalaga_USFX_LAB2Pawn>(PlayerController->GetPawn()); //convertir el objeto GetPawn de Pawn a la clase Pawn que es la clase del jugador 
		if (Jugador) // verificamos jugador que no es un puntero nulo 
		{
			// se obtiene que Jugador no es nulo 
			Jugador->Destroy();
		}
	}
}


void AGalaga_USFX_LAB2GameMode::BombaTerrestreAleatoria()
{
	// Obtener el mundo actual
	UWorld* const World = GetWorld();
	if (World != nullptr && TANavesEnemigas.Num() > 0) // Verificar si el mundo no es nulo y si hay naves enemigas mayor a 0
		
	{
		// Array para almacenar las posiciones de todas las naves enemigas de diferentes tipos
		TArray<FVector> PosicionesNavesDiferentesTipos;

		// Iterar sobre las naves enemigas y guardar las posiciones de diferentes tipos en el array
		for (ANaveEnemiga* NaveEnemiga : TANavesEnemigas)
		{
			if (NaveEnemiga != nullptr) // Verificar si la nave enemiga no es nula
			{
				// Verificar el tipo de la nave y hacemos la conversion
				if (ANaveEnemigaCaza* NaveCaza = Cast<ANaveEnemigaCaza>(NaveEnemiga)) // Cast para hacer la convercion 
				{ 
					PosicionesNavesDiferentesTipos.Add(NaveCaza->GetActorLocation()); // Agregar la posici�n de la nave al array
				}
				else if (ANaveEnemigaEspia* NaveEspia = Cast<ANaveEnemigaEspia>(NaveEnemiga)) // Verificar si la nave es de tipo NaveEnemigaEspia
				{
					PosicionesNavesDiferentesTipos.Add(NaveEspia->GetActorLocation()); // Agregar la posici�n de la nave al array
				}
				else if (ANaveEnemigaTransporte* NaveTransporte = Cast<ANaveEnemigaTransporte>(NaveEnemiga)) // Verificar si la nave es de tipo NaveEnemigaTransporte
				{
					PosicionesNavesDiferentesTipos.Add(NaveTransporte->GetActorLocation()); // Agregar la posici�n de la nave al array
				}
			}
		}
		// Verificar si se encontraron posiciones de naves de diferentes tipos
		if (PosicionesNavesDiferentesTipos.Num() > 0)
		{
			// Elegir una posici�n aleatoria del array de posiciones de naves de diferentes tipos
			int32 RandomIndex = FMath::RandRange(0, PosicionesNavesDiferentesTipos.Num() - 1);
			FVector PosicionAleatoria = PosicionesNavesDiferentesTipos[RandomIndex];

			// Spawnear la bomba en la posici�n aleatoria
			ABombaTerrestre* Bomba = World->SpawnActor<ABombaTerrestre>(PosicionAleatoria, FRotator::ZeroRotator);
			if (Bomba)
			{
				// Mostrar un mensaje en la pantalla para indicar la posici�n de la bomba terrestre generada
				FString Mensaje = FString::Printf(TEXT("Bomba terrestre generada en posici�n aleatoria: %s"), *PosicionAleatoria.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, Mensaje);
				BombaTerrestreActual = Bomba;
			}
			else
			{
				// Mostrar un mensaje de advertencia si no se pudo generar la bomba
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("No se pudo generar la bomba terrestre en una posici�n aleatoria."));
			}
		}
	}
}

void AGalaga_USFX_LAB2GameMode::HacerExplotarBombaTerrestre()
{
	// Verificamos si la referencia bomba terrestre actual no es nula
	if (BombaTerrestreActual != nullptr)
	{
		// Obtenemos la ubicaci�n de la bomba terrestre con el fin de aplicar el efecto de la explosi�n
		FVector BombaLocation = BombaTerrestreActual->GetActorLocation();

		// Iteramos sobre las naves enemigas y destruir aquellas que est�n dentro de un radio determinado de la bomba
		for (ANaveEnemiga* NaveEnemiga : TANavesEnemigas) // Iterar sobre todas las naves enemigas
		{
			if (NaveEnemiga != nullptr) // Verificamos si la nave enemiga no es nula
			{
				// Obtenemos la ubicaci�n de la nave enemiga
				FVector NaveLocation = NaveEnemiga->GetActorLocation(); // Obtenemos la ubicaci�n de la nave enemiga
				float Distance = FVector::Distance(BombaLocation, NaveLocation); // Calculamos la distancia entre la bomba y la nave

				// Si la nave est� dentro de un radio de explosi�n (por ejemplo, 400 unidades), destruirla
				if (Distance <= 400.0f) // Verificamos si la distancia es menor o igual a 400 unidades
				{
					NaveEnemiga->Destroy(); // Destruir la nave enemiga
				}
			}
		}

		// Una vez que se haya aplicado el efecto de la explosi�n, destruir la bomba terrestre
		BombaTerrestreActual->Destroy(); // Destruir la bomba terrestre
		DestruirNaveJugador(); // destruimos la nave del jugador 
	}
}
