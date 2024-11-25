// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

// UCharacterClassInfo
#include <Data/CharacterClassInfo.h>

#include "RPGAbilitySystemLibrary.generated.h"


/**
 * 
 */
UCLASS()
class RPG_BATTLE_API URPGAbilitySystemLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintPure)
	static UCharacterClassInfo* GetCharacterClassDefaultInfo(const UObject* WorldContextObject);
};
