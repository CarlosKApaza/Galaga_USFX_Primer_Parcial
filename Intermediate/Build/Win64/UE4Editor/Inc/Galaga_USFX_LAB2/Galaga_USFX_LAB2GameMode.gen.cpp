// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Galaga_USFX_LAB2/Galaga_USFX_LAB2GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGalaga_USFX_LAB2GameMode() {}
// Cross Module References
	GALAGA_USFX_LAB2_API UClass* Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_NoRegister();
	GALAGA_USFX_LAB2_API UClass* Z_Construct_UClass_AGalaga_USFX_LAB2GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_Galaga_USFX_LAB2();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	GALAGA_USFX_LAB2_API UClass* Z_Construct_UClass_ANaveEnemiga_NoRegister();
// End Cross Module References
	void AGalaga_USFX_LAB2GameMode::StaticRegisterNativesAGalaga_USFX_LAB2GameMode()
	{
	}
	UClass* Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_NoRegister()
	{
		return AGalaga_USFX_LAB2GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TMPosicionesNavesEnemigas_ValueProp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TMPosicionesNavesEnemigas_Key_KeyProp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TMPosicionesNavesEnemigas_MetaData[];
#endif
		static const UE4CodeGen_Private::FMapPropertyParams NewProp_TMPosicionesNavesEnemigas;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_Galaga_USFX_LAB2,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "Galaga_USFX_LAB2GameMode.h" },
		{ "ModuleRelativePath", "Galaga_USFX_LAB2GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::NewProp_TMPosicionesNavesEnemigas_ValueProp = { "TMPosicionesNavesEnemigas", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 1, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::NewProp_TMPosicionesNavesEnemigas_Key_KeyProp = { "TMPosicionesNavesEnemigas_Key", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UClass_ANaveEnemiga_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::NewProp_TMPosicionesNavesEnemigas_MetaData[] = {
		{ "Comment", "// Contenedor avanzado TMap para almacenar las posiciones de las naves enemigas\n" },
		{ "ModuleRelativePath", "Galaga_USFX_LAB2GameMode.h" },
		{ "ToolTip", "Contenedor avanzado TMap para almacenar las posiciones de las naves enemigas" },
	};
#endif
	const UE4CodeGen_Private::FMapPropertyParams Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::NewProp_TMPosicionesNavesEnemigas = { "TMPosicionesNavesEnemigas", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGalaga_USFX_LAB2GameMode, TMPosicionesNavesEnemigas), EMapPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::NewProp_TMPosicionesNavesEnemigas_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::NewProp_TMPosicionesNavesEnemigas_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::NewProp_TMPosicionesNavesEnemigas_ValueProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::NewProp_TMPosicionesNavesEnemigas_Key_KeyProp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::NewProp_TMPosicionesNavesEnemigas,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGalaga_USFX_LAB2GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::ClassParams = {
		&AGalaga_USFX_LAB2GameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGalaga_USFX_LAB2GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGalaga_USFX_LAB2GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGalaga_USFX_LAB2GameMode, 1770710822);
	template<> GALAGA_USFX_LAB2_API UClass* StaticClass<AGalaga_USFX_LAB2GameMode>()
	{
		return AGalaga_USFX_LAB2GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGalaga_USFX_LAB2GameMode(Z_Construct_UClass_AGalaga_USFX_LAB2GameMode, &AGalaga_USFX_LAB2GameMode::StaticClass, TEXT("/Script/Galaga_USFX_LAB2"), TEXT("AGalaga_USFX_LAB2GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGalaga_USFX_LAB2GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
