// Fill out your copyright notice in the Description page of Project Settings.


#include "SGCharacter.h"

// Sets default values
ASGCharacter::ASGCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  // create spring arm
  CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
  CameraBoom->SetupAttachment(RootComponent);
  CameraBoom->TargetArmLength = 300.0f;
  CameraBoom->bUsePawnControlRotation = true;


  Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
  Camera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
  Camera->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ASGCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

  // setup movement bindings
  PlayerInputComponent->BindAxis("MoveForward", this, &ASGCharacter::MoveForward);
  PlayerInputComponent->BindAxis("MoveRight", this, &ASGCharacter::MoveRight);

  // setup look bindings
  PlayerInputComponent->BindAxis("LookX", this, &ASGCharacter::AddControllerYawInput);
  PlayerInputComponent->BindAxis("LookY", this, &ASGCharacter::AddControllerPitchInput);

  // setup jump binding
  PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASGCharacter::ActivateJump);
  PlayerInputComponent->BindAction("Jump", IE_Released, this, &ASGCharacter::DeactivateJump);
}

void ASGCharacter::MoveForward(float Value) {
  FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
  AddMovementInput(Direction, Value);
}

void ASGCharacter::MoveRight(float Value) {
    FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(Direction, Value);
}

void ASGCharacter::ActivateJump() {
  bPressedJump = true;
}

void ASGCharacter::DeactivateJump() {
  bPressedJump = false;
}
