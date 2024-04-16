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
			//NaveEnemigaTransporteActual->SetNombre("Nave Enemiga Transporte" + FString::FromInt(j + 1));
			TANavesEnemigas.Add(NaveEnemigaTransporteActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaTransporteActual, ubicacionNaveActual);
		}
		// Actualizar la ubicaci�n inicial para las naves de la clase NaveEnemigaEspia
		ubicacionNaveActual.X = ubicacionNaveInicial.X = 270.0f; // crear un fila m�s arriba
		ubicacionNaveActual.Y = ubicacionNaveInicial.Y = -200.0f; // actualizo la creacion de la nave desde la ubicacionNaveActual

		for (int k = 0; k < 7; k++) { // Crear 10 naves de la clase NaveEnemigaEspia
			ubicacionNaveActual.Y += 180.0f; // Sumar 190 unidades a la coordenada Y en cada iteraci�n (los espacios por naves)
			ANaveEnemigaEspia* NaveEnemigaEspiaActual = World->SpawnActor<ANaveEnemigaEspia>(ubicacionNaveActual, rotacionNave);
			//NaveEnemigaEspiaActual->SetNombre("Nave Enemiga Espia" + FString::FromInt(k + 1));
			TANavesEnemigas.Add(NaveEnemigaEspiaActual);
			TMPosicionesNavesEnemigas.Add(NaveEnemigaEspiaActual, ubicacionNaveActual);
		}
		
		// Mostrar las posiciones de las naves enemigas cada segundo
		/*GetWorldTimerManager().SetTimer(FTHVisualizacionPosicionesNavesEnemigas, this, &AGalaga_USFX_LAB2GameMode::MostrarPosicionesNavesEnemigas, 1.0f, true);*/

		// Temporizador para eliminar enemigos aleatorios cada 10 segundos
		//GetWorldTimerManager().SetTimer(FTHEliminarEnemigosAleatorios, this, &AGalaga_USFX_LAB2GameMode::EliminarEnemigosAleatoriamente, 5.0f, true, 5.0f);

		// Temporizador para crear enemigos aleatorios despu�s de 10 segundo
		//GetWorldTimerManager().SetTimer(FTHCrearEnemigosAleatorios, this, &AGalaga_USFX_LAB2GameMode::CrearEnemigosAleatoriamente, 5.0f, true, 5.0f);

		// Temporizador para lanzar bombas terrestres aleatorias despu�s de 10 segundos
		GetWorldTimerManager().SetTimer(FTHLanzarBombaTerrestreAleatorios, this, &AGalaga_USFX_LAB2GameMode::BombaTerrestreAleatoria, 4.0f, true);
		// Configurar temporizador para detener todas las acciones despu�s de 40 segundos

		GetWorldTimerManager().SetTimer(FTHExplotarBombaTerrestre, this, &AGalaga_USFX_LAB2GameMode::HacerExplotarBombaTerrestre, 5.0f, true, 5.0f);
		GetWorldTimerManager().SetTimer(FTHEndGameActions, this, &AGalaga_USFX_LAB2GameMode::StopGameActions, 120.0f, false);


	}
}

//void AGalaga_USFX_LAB2GameMode::EliminarEnemigosAleatoriamente()
//{
//	// Verificar si hay al menos dos enemigos para eliminar
//	if (TANavesEnemigas.Num() >= 2)
//	{
//		// Eliminar dos enemigos aleatorios
//		for (int i = 0; i < 2; i++)
//		{
//			int32 RandomIndex = FMath::RandRange(0, TANavesEnemigas.Num() - 1);
//			ANaveEnemiga* NaveEnemigaAEliminar = TANavesEnemigas[RandomIndex];
//			TANavesEnemigas.Remove(NaveEnemigaAEliminar);
//			TMPosicionesNavesEnemigas.Remove(NaveEnemigaAEliminar);
//			NaveEnemigaAEliminar->Destroy();
//		}
//	}
//}

//void AGalaga_USFX_LAB2GameMode::CrearEnemigosAleatoriamente()
//{
//	// Obtener el mundo
//	UWorld* const World = GetWorld();
//	if (World == nullptr)
//	{
//		return;
//	}
//
//	// Lista de clases de naves enemigas disponibles
//	TArray<TSubclassOf<ANaveEnemiga>> ClasesNavesEnemigas;
//	ClasesNavesEnemigas.Add(ANaveEnemigaCaza::StaticClass());
//	ClasesNavesEnemigas.Add(ANaveEnemigaTransporte::StaticClass());
//	ClasesNavesEnemigas.Add(ANaveEnemigaEspia::StaticClass());
//
//	// Espacio deseado entre las naves en el eje Y
//	float EspacioEntreNavesY = 100.0f;
//
//	// Posici�n Y inicial
//	float PosicionY = -50.0f;
//
//	// Incremento en la posici�n Y para cada fila
//	float IncrementoY = EspacioEntreNavesY * ClasesNavesEnemigas.Num();
//
//	// Crear tres nuevas naves enemigas aleatoriamente
//	for (int i = 0; i < 6; i++)
//	{
//		// Obtener una posici�n aleatoria desde TMPosicionesNavesEnemigas
//		int32 RandomIndex = FMath::RandRange(0, TMPosicionesNavesEnemigas.Num() - 1);
//		auto It = TMPosicionesNavesEnemigas.CreateIterator();
//		for (int32 Index = 0; Index < RandomIndex; ++Index)
//		{
//			++It;
//		}
//		FVector PosicionNaveNueva = It->Value;
//
//		// Ajustar la posici�n Y basada en el �ndice de iteraci�n
//		PosicionNaveNueva.Y = PosicionY + (i * IncrementoY);
//
//		// Obtener una clase de nave enemiga aleatoria
//		int32 RandomClassIndex = FMath::RandRange(0, ClasesNavesEnemigas.Num() - 1);
//		TSubclassOf<ANaveEnemiga> ClaseNaveEnemiga = ClasesNavesEnemigas[RandomClassIndex];
//
//		// Crear una nueva nave enemiga en la posici�n aleatoria
//		if (ClaseNaveEnemiga)
//		{
//			ANaveEnemiga* NuevaNaveEnemiga = World->SpawnActor<ANaveEnemiga>(ClaseNaveEnemiga, PosicionNaveNueva, FRotator::ZeroRotator);
//			if (NuevaNaveEnemiga)
//			{
//				// Agregar la nueva nave enemiga al mapa
//				TMPosicionesNavesEnemigas.Add(NuevaNaveEnemiga, PosicionNaveNueva);
//			}
//		}
//	}
//}

void AGalaga_USFX_LAB2GameMode::StopGameActions()
{
	// Detener todas las acciones
	//GetWorldTimerManager().ClearTimer(FTHEliminarEnemigosAleatorios); // Detiene la eliminaci�n de enemigos aleatorios despu�s de 40 segundos
	//GetWorldTimerManager().ClearTimer(FTHCrearEnemigosAleatorios); // Detiene la creaci�n de enemigos aleatorios despu�s de 40 segundos
	GetWorldTimerManager().ClearTimer(FTHLanzarBombaTerrestreAleatorios); // Detiene el lanzamiento de bombas terrestres aleatorias despu�s de 40 segundos
	GetWorldTimerManager().ClearTimer(FTHExplotarBombaTerrestre); // Detiene la explosi�n de bombas terrestres despu�s de 40 segundos

}

void AGalaga_USFX_LAB2GameMode::BombaTerrestreAleatoria()
{
	UWorld* const World = GetWorld();
	if (World != nullptr && TANavesEnemigas.Num() > 0)
	{
		// Array para almacenar las posiciones de todas las naves enemigas de diferentes tipos
		TArray<FVector> PosicionesNavesDiferentesTipos;

		// Iterar sobre las naves enemigas y guardar las posiciones de diferentes tipos en el array
		for (ANaveEnemiga* NaveEnemiga : TANavesEnemigas)
		{
			if (NaveEnemiga != nullptr)
			{
				// Verificar el tipo de la nave
				if (ANaveEnemigaCaza* NaveCaza = Cast<ANaveEnemigaCaza>(NaveEnemiga))
				{
					PosicionesNavesDiferentesTipos.Add(NaveCaza->GetActorLocation());
				}
				else if (ANaveEnemigaEspia* NaveEspia = Cast<ANaveEnemigaEspia>(NaveEnemiga))
				{
					PosicionesNavesDiferentesTipos.Add(NaveEspia->GetActorLocation());
				}
				else if (ANaveEnemigaTransporte* NaveTransporte = Cast<ANaveEnemigaTransporte>(NaveEnemiga))
				{
					PosicionesNavesDiferentesTipos.Add(NaveTransporte->GetActorLocation());
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
	// Verificar si la bomba terrestre actual no es nula
	if (BombaTerrestreActual != nullptr)
	{
		// Obtener la ubicaci�n de la bomba terrestre
		FVector BombaLocation = BombaTerrestreActual->GetActorLocation();

		// Iterar sobre las naves enemigas y destruir aquellas que est�n dentro de un radio determinado de la bomba
		for (ANaveEnemiga* NaveEnemiga : TANavesEnemigas)
		{
			if (NaveEnemiga != nullptr)
			{
				// Obtener la ubicaci�n de la nave enemiga
				FVector NaveLocation = NaveEnemiga->GetActorLocation();
				float Distance = FVector::Distance(BombaLocation, NaveLocation);

				// Si la nave est� dentro de un radio de explosi�n (por ejemplo, 500 unidades), destruirla
				if (Distance <= 400.0f)
				{
					NaveEnemiga->Destroy();
				}
			}
		}

		// Una vez que se haya aplicado el efecto de la explosi�n, destruir la bomba terrestre
		BombaTerrestreActual->Destroy();
	}
}
