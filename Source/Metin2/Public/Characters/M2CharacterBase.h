// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "M2CharacterBase.generated.h"

UCLASS()
class METIN2_API AM2CharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()


	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	// Sets default values for this character's properties
	AM2CharacterBase();




	/** Camera bool length to character changing rate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraBoomChangeMouseRate;

	/** Camera boom length to character changing rate */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraBoomChangeKeyRate;

	/** Maximum camera boom length to character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraBoomMaxLength;

	/** Minimum camera boom length to character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraBoomMinLength;

	/** Default camera boom length to character */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float CameraBoomDefaultLength;



	// Implement IAbilitySystemInterface
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);


	void ChangeCameraBoomLengthRate(float Rate);


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Only called on the Server. Calls before Server's AcknowledgePossession.
	virtual void PossessedBy(AController* NewController) override;

protected:
	// Reference to the ASC. It will live on the PlayerState or here if the character doesn't have a PlayerState.
	UPROPERTY()
		class UM2AbilitySystemComponent* AbilitySystemComponent;


public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
