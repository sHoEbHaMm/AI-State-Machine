// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "AI_CompanionState.h"
#include "Components/AudioComponent.h"
#include "AI_Companion.generated.h"

UCLASS()
class AIBEHAVIOR_API AAI_Companion : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAI_Companion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* staticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector referencePosition;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector referencePositionWhileHealing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator referenceRotationWhileHealing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ACharacter* playerCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isRefPosSet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isHealing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isAttacking;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UAudioComponent* woofSound;

	void SetState(ICompanionState* newState);

	UFUNCTION(BlueprintCallable, Category = "CompanionState")
	void SetHealingState();

	UFUNCTION(BlueprintCallable, Category = "CompanionState")
	void SetAttackState();

	UFUNCTION(BlueprintCallable, Category = "CompanionState")
	void SetFollowState();


private:
	ICompanionState* currentState;

};
