// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BombaTerrestre.generated.h"


class UStaticMeshComponent; // Forward declaration para crear un componente de malla est�tica

UCLASS()
class GALAGA_USFX_LAB2_API ABombaTerrestre : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MallaBomba; // Crear un componente de malla est�tica para la bomba
	
private:
	FVector posicionBomba;
	FString nombreb;
	float radioBomba;
public:
	//getter
	FORCEINLINE FVector GetPosicionBomba() const { return posicionBomba; }
	FORCEINLINE FString GetNombreBomba() const { return nombreb; }
	FORCEINLINE float GetRadioBomba() const { return radioBomba; }

	//setter
	FORCEINLINE void SetPosicionBomba(FVector posicion) { posicionBomba = posicion; }
	FORCEINLINE void SetNombreBomba(FString nombre) { nombreb = nombre; }
	FORCEINLINE void SetRadioBomba(float radio) { radioBomba = radio; }

public:	
	// Sets default values for this actor's properties
	ABombaTerrestre();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void MoverBomba(float DeltaTime); // funci�n para mover la bomba
	UPROPERTY(EditAnywhere, Category = "Movimiento") // EditAnywhere para que se pueda modificar desde el editor
	float velocidadBomba; // velocidad de la bomba en el eje 
};
