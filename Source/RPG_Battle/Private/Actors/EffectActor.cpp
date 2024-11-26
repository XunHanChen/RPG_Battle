// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/EffectActor.h"
#include "Components/BoxComponent.h"
#include <AbilitySystemComponent.h>
#include <AbilitySystemBlueprintLibrary.h>

// Sets default values
AEffectActor::AEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	bReplicates = true;

	ActorMesh = CreateDefaultSubobject<UStaticMeshComponent>("ActorMesh");
	SetRootComponent(ActorMesh);
;
	OverlapBox = CreateDefaultSubobject<UBoxComponent>("OverlapBox");
	OverlapBox->SetupAttachment(GetRootComponent());
	OverlapBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	OverlapBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

}

// Called when the game starts or when spawned
void AEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (HasAuthority())
	{
		OverlapBox->OnComponentBeginOverlap.AddDynamic(this, &AEffectActor::OnBoxBeginOverlap);
	}

}

void AEffectActor::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (UAbilitySystemComponent* OtherASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor))
	{
		const FGameplayEffectContextHandle Contexthandle = OtherASC->MakeEffectContext();
		const FGameplayEffectSpecHandle SpecHandle = OtherASC->MakeOutgoingSpec(OverlapEffect, 1.f, Contexthandle);
		OtherASC->ApplyGameplayEffectSpecToSelf(*SpecHandle.Data.Get());

		Destroy();
	}
}

