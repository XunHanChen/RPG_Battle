// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/CharacterBase.h"

// Sets default values
ACharacterBase::ACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::InitAbilityActorInfo()
{
	// Intentionally left blank now.
}

void ACharacterBase::BindCallbacksToDependencies()
{
	// Intentionally left blank now.
}

void ACharacterBase::InitClassDefaults()
{
	// Intentionally left blank now.
}

void ACharacterBase::BroadcastInitialValues()
{
	// Intentionally left blank now.
}
