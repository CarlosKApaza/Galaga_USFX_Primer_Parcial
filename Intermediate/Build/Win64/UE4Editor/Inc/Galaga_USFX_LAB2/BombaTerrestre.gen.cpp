// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB2/BombaTerrestre.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBombaTerrestre() {}
// Cross Module References
	GALAGA_USFX_LAB2_API UClass* Z_Construct_UClass_ABombaTerrestre_NoRegister();
	GALAGA_USFX_LAB2_API UClass* Z_Construct_UClass_ABombaTerrestre();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB2();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void ABombaTerrestre::StaticRegisterNativesABombaTerrestre()
	{
	}
	UClass* Z_Construct_UClass_ABombaTerrestre_NoRegister()
	{
		return ABombaTerrestre::StaticClass();
	}
	struct Z_Construct_UClass_ABombaTerrestre_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MallaBomba_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MallaBomba;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_velocidadBomba_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_velocidadBomba;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABombaTerrestre_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB2,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABombaTerrestre_Statics::Class_MetaDataParams[] = {
		{ "Comment", "// Forward declaration para crear un componente de malla est?tica\n" },
		{ "IncludePath", "BombaTerrestre.h" },
		{ "ModuleRelativePath", "BombaTerrestre.h" },
		{ "ToolTip", "Forward declaration para crear un componente de malla est?tica" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_MallaBomba_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Projectile" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "BombaTerrestre.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_MallaBomba = { "MallaBomba", nullptr, (EPropertyFlags)0x00100000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABombaTerrestre, MallaBomba), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_MallaBomba_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_MallaBomba_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_velocidadBomba_MetaData[] = {
		{ "Category", "Movimiento" },
		{ "Comment", "// funci?n para mover la bomba\n// EditAnywhere para que se pueda modificar desde el editor\n" },
		{ "ModuleRelativePath", "BombaTerrestre.h" },
		{ "ToolTip", "funci?n para mover la bomba\nEditAnywhere para que se pueda modificar desde el editor" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_velocidadBomba = { "velocidadBomba", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABombaTerrestre, velocidadBomba), METADATA_PARAMS(Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_velocidadBomba_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_velocidadBomba_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABombaTerrestre_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_MallaBomba,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABombaTerrestre_Statics::NewProp_velocidadBomba,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABombaTerrestre_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABombaTerrestre>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABombaTerrestre_Statics::ClassParams = {
		&ABombaTerrestre::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ABombaTerrestre_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ABombaTerrestre_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABombaTerrestre_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABombaTerrestre_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABombaTerrestre()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABombaTerrestre_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABombaTerrestre, 995292051);
	template<> GALAGA_USFX_LAB2_API UClass* StaticClass<ABombaTerrestre>()
	{
		return ABombaTerrestre::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABombaTerrestre(Z_Construct_UClass_ABombaTerrestre, &ABombaTerrestre::StaticClass, TEXT("/Script/Galaga_USFX_LAB2"), TEXT("ABombaTerrestre"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABombaTerrestre);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
