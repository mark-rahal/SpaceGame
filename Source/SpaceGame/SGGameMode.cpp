// Fill out your copyright notice in the Description page of Project Settings.


#include "SGGameMode.h"

void ASGGameMode::StartPlay() {
	Super::StartPlay();
  if (GEngine) {
    GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::FromInt(GetNumPlayers()));
  }
}