// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NiagaraTestVFXCharacter.generated.h"

UCLASS(config=Game)
class ANiagaraTestVFXCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, Category = Effects)
	class UNiagaraSystem* TrailSystem;

	UPROPERTY(EditAnywhere, Category = Effects)
	class UNiagaraComponent* NiagaraComponent;
	
public:
	ANiagaraTestVFXCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Input)
	float TurnRateGamepad;

protected:

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	/** 
	 * Called via input to turn at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate. 
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	/* Called for enable shield */
	void EnableShield();

	/* Called for disable shield */
	void DisableShield();

	/* Called for increase movement speed */
	void StartSprint();

	/* Reduce speed to default value */
	void StopSprint();
	
	void ZoomCamera(float Value);
	
public:
	
	/* Return max player energy */
	UFUNCTION(BlueprintCallable)
	float GetMaxEnergy() { return MaxEnergy; };

	/* Return current player energy */
	UFUNCTION(BlueprintCallable)
	float GetCurrentEnergy() { return CurrentEnergy; };

	/* Is shield enabled? */
	UFUNCTION(BlueprintCallable)
	bool IsShieldEnabled() { return bShieldIsEnabled; };

public:
	/* Regenerates energy */
	void RegenerateEnergy(float Time);

	void DecreaseEnergy(float Time);

protected:
	/* Is shield enabled? */
	bool bShieldIsEnabled;

	/* Active shield time */
	float ShieldActiveTime;

protected:
	/* Movement speed modifier */
	UPROPERTY(EditAnywhere, Category = Movement)
	float SprintModifier;

	UPROPERTY(EditAnywhere, Category = Camera)
	float CameraZoomSpeed;

	///// Energy /////
	UPROPERTY(EditAnywhere, Category = Energy)
	float MaxEnergy;

	UPROPERTY(EditAnywhere, Category = Energy)
	float CurrentEnergy;

	UPROPERTY(EditAnywhere, Category = Energy)
	float EnergyRegenPerSecond;

	UPROPERTY(EditAnywhere, Category = Energy)
	float ShieldEnergyCost;
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;
	
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

