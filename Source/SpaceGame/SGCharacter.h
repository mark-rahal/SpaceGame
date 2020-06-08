// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "SGCharacter.generated.h"

UCLASS()
class SPACEGAME_API ASGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASGCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
  
  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  USpringArmComponent* CameraBoom;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UCameraComponent* Camera;

  UFUNCTION()
  void MoveForward(float Value);
  
  UFUNCTION()
  void MoveRight(float Value);

  UFUNCTION()
  void ActivateJump();

  UFUNCTION()
  void DeactivateJump();
};
