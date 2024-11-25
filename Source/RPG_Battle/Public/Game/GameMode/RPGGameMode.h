// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

// UCharacterClassInfo
#include <Data/CharacterClassInfo.h>

#include "RPGGameMode.generated.h"

/**
 * 
 */
UCLASS()
class RPG_BATTLE_API ARPGGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:

	UCharacterClassInfo* GetCharacterClassDefaultInfo() const;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Custom Values|Class Defaults")
	TObjectPtr<UCharacterClassInfo> ClassDefaults;
};
