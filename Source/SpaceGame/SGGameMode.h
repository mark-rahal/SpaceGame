// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SGGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SPACEGAME_API ASGGameMode : public AGameMode
{
	GENERATED_BODY()
	
  virtual void StartPlay() override;
};
