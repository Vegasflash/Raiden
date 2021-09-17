// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ELevel.h"
#include "AAppLauncher.generated.h"

class ULevelLoader;
class ARaidenGameModeBase;

UCLASS()
class RAIDEN_API AAppLauncher : public AActor
{
	GENERATED_BODY()
private:	

	void InitApplication();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Sets default values for this actor's properties
	AAppLauncher();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ELevel level_to_load;
};
