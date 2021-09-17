// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RaidenGameModeBase.generated.h"

class ULevelLoader;

/**
 * 
 */
UCLASS()
class RAIDEN_API ARaidenGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:	
	ARaidenGameModeBase();
	virtual ~ARaidenGameModeBase() = default;

	UPROPERTY(VisibleAnywhere)
	ULevelLoader* level_loader;
};
