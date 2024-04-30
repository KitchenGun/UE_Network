// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "UE5NetworkStudyCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AUE5NetworkStudyCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

public:
	AUE5NetworkStudyCharacter();
	
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);
		

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	// To add mapping context
	virtual void BeginPlay();

	//hp var update
	void OnHealthUpdate();

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
	
	/** Getter for Max Health.*/
	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetMaxHp() const { return MaxHp; }
	/** Getter for cur Health.*/
	UFUNCTION(BlueprintPure, Category = "Health")
	FORCEINLINE float GetCurrentHp() const { return CurrentHp; }
	
	// current hp change it will be call
	UFUNCTION()
	void OnRep_CurrentHp();

	UFUNCTION(BlueprintCallable, Category = "Health")
		void SetCurrentHp(float Value);

	//Damage Function
	UFUNCTION(BlueprintCallable, Category = "Health")
	float TakeDamage
	(
		float Damage, 
		struct FDamageEvent const& DamageEvent, 
		AController* EventInstigator,
		AActor* DamageCauser
	) override;

protected:
	UPROPERTY(EditDefaultsOnly,Category = "Health")
	float MaxHp = 100.0f;
	UPROPERTY(ReplicatedUsing = OnRep_CurrentHp)
	float CurrentHp = 100.0f;

};

