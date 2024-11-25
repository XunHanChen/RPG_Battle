// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"

// FGameplayTag
#include "GameplayTagContainer.h"

#include "CharacterClassInfo.generated.h"

class UGameplayEffect;
class UGameplayAbility;

USTRUCT()
struct FCharacterClassDefaultInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UGameplayEffect> DefaultAttributes;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> StartingAbilities;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameplayAbility>> StartingPassvies;
};

/**
 * 
 */
UCLASS()
class RPG_BATTLE_API UCharacterClassInfo : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
	TMap<FGameplayTag, FCharacterClassDefaultInfo> ClassDefaultInfoMap;
};
