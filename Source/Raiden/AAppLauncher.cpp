// Fill out your copyright notice in the Description page of Project Settings.


#include "AAppLauncher.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "Raiden/LevelLoader.h"
//#include "ELevel.h"

// Sets default values
AAppLauncher::AAppLauncher()
	: level_to_load(ELevel::Gym_Rick)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	level_loader = CreateDefaultSubobject<ULevelLoader>(TEXT("Level Loader"));
}

// Called when the game starts or when spawned
void AAppLauncher::BeginPlay()
{
	Super::BeginPlay();

	InitApplication();
}

void AAppLauncher::InitApplication()
{
	auto* world = GetWorld();

	auto prefix = world->StreamingLevelsPrefix;

	FString current_level = world->GetMapName();
	current_level.RemoveFromStart(prefix);


	if (current_level == "AppLauncher")
	{
		level_loader->LoadLevel(world, level_to_load);
	}
}

