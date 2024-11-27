// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include <AbilitySystem/RPGAbilitySystemComponent.h>
#include <AbilitySystemInterface.h>
#include <Input/RPGInputConfig.h>

#include "RPGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RPG_BATTLE_API ARPGPlayerController : public APlayerController, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	ARPGPlayerController();

	virtual void SetupInputComponent() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	virtual void BeginPlay() override;

	void AbilityInputPressed(FGameplayTag InputTag);
	void AbilityInputReleased(FGameplayTag InputTag);

private:

	UPROPERTY()
	TObjectPtr<URPGAbilitySystemComponent> RPGAbilitySystemComp;

	UPROPERTY(EditDefaultsOnly, Category = "Custom Values|Input")
	TObjectPtr<URPGInputConfig> RPGInputConfig;

	URPGAbilitySystemComponent* GetRPGAbilitySystemComponent();
};
