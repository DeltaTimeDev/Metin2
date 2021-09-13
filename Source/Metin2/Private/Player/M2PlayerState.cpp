// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/M2PlayerState.h"
#include "Characters/Abilities/M2AbilitySystemComponent.h"
#include "Characters/Abilities/AttributeSets/M2AttributeSet.h"

AM2PlayerState::AM2PlayerState()
{
	// Create ability system component, and set it to be explicitly replicated
	AbilitySystemComponent = CreateDefaultSubobject<UM2AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// Mixed mode means we only are replicated the GEs to ourself, not the GEs to simulated proxies. If another GDPlayerState (Hero) receives a GE,
	// we won't be told about it by the Server. Attributes, GameplayTags, and GameplayCues will still replicate to us.
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// Create the attribute set, this replicates by default
	// Adding it as a subobject of the owning actor of an AbilitySystemComponent
	// automatically registers the AttributeSet with the AbilitySystemComponent
	AttributeSet = CreateDefaultSubobject<UM2AttributeSet>(TEXT("AttributeSetBase"));

}

void AM2PlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	UE_LOG(LogTemp, Warning, TEXT("AM2PlayerState::PostInitializeComponents"));
}

UAbilitySystemComponent* AM2PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UM2AttributeSet* AM2PlayerState::GetAttributeSetBase() const
{
	return AttributeSet;
}


