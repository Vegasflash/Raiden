// Copyright Epic Games, Inc. All Rights Reserved.


#include "RaidenGameModeBase.h"
#include "LevelLoader.h"

ARaidenGameModeBase::ARaidenGameModeBase()
{
	level_loader = CreateDefaultSubobject<ULevelLoader>(TEXT("Level Loader"));
}

