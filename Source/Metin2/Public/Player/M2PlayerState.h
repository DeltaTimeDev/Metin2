// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "M2PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class METIN2_API AM2PlayerState : public APlayerState ,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AM2PlayerState();

	virtual void PostInitializeComponents() override;

	// Implement IAbilitySystemInterface
	class UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
	class UM2AttributeSet* GetAttributeSetBase() const;

	

protected:

		UPROPERTY()
	class UM2AbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
		class UM2AttributeSet* AttributeSet;

};
