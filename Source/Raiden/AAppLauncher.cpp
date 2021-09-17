// Fill out your copyright notice in the Description page of Project Settings.


#include "AAppLauncher.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>
#include "LevelLoader.h"
#include "RaidenGameModeBase.h"

// Sets default values
AAppLauncher::AAppLauncher()
	: level_to_load(ELevel::Gym_Rick)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;	
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

	auto* game_mode = world->GetAuthGameMode();
	ARaidenGameModeBase* raiden_game_mode = Cast<ARaidenGameModeBase>(game_mode);

	if (current_level != "AppLauncher")
	{
		UE_LOG(LogTemp, Error, TEXT("Trying to InitApplication whilst not inside AppLauncher Level!"));
		return;
	}

	if (raiden_game_mode == NULL)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to cast GameMode to RaidenGameModeBase."));
		return;
	}

	raiden_game_mode->level_loader->LoadLevel(world, level_to_load);

}

