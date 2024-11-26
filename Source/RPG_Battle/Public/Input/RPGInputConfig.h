// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h" // Include for FGameplayTag
#include "RPGInputConfig.generated.h"

class UInputAction;

USTRUCT()
struct FRPGInputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UInputAction> InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();

};

/**
 * 
 */
UCLASS()
class RPG_BATTLE_API URPGInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditDefaultsOnly)
	TArray<FRPGInputAction> RPGInputActions;
};
