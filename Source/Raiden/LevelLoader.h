// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ELevel.h"
#include "LevelLoader.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RAIDEN_API ULevelLoader : public UActorComponent
{
	GENERATED_BODY()

public:	
	static const TMap<ELevel, FString> level_name_by_level;

	// Sets default values for this component's properties
	ULevelLoader();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	void LoadLevel(UWorld* world, ELevel level);

		
};
