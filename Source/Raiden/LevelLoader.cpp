// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelLoader.h"
#include <Runtime/Engine/Classes/Kismet/GameplayStatics.h>

// Sets default values for this component's properties
ULevelLoader::ULevelLoader()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

const TMap<ELevel, FString> ULevelLoader::level_name_by_level =
{
	{ELevel::Gym_Rick, "Gym_Rick"},
};


// Called when the game starts
void ULevelLoader::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULevelLoader::LoadLevel(UWorld* world, ELevel level)
{
	if (!level_name_by_level.Contains(level))
	{
		UE_LOG(LogTemp, Error, TEXT("Missing TMap entry for Level being loaded: %d"), level);
		return;
	}
	
	auto level_name = FName(level_name_by_level[level]);

	UGameplayStatics::OpenLevel(world, level_name);
}

