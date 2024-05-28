// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_Companion.h"
#include "Companion_AttackState.h"
#include "Companion_FollowState.h"
#include "Companion_HealState.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AAI_Companion::AAI_Companion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	woofSound = CreateDefaultSubobject<UAudioComponent>(TEXT("AudioComp"));

	RootComponent = staticMesh;

	currentState = new Companion_FollowState();
	currentState->OnEnterState(this);

	isRefPosSet = false;
	isAttacking = false;
	isHealing = false;

}

// Called when the game starts or when spawned
void AAI_Companion::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AAI_Companion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentState)
	{
		currentState->UpdateState(this, DeltaTime);
	}
}

void AAI_Companion::SetState(ICompanionState* newState)
{
	if (currentState)
	{
		currentState->OnExitState(this);
		delete currentState;
	}
	currentState = newState;
	currentState->OnEnterState(this);
}

void AAI_Companion::SetHealingState()
{
	Companion_HealState* healState = new Companion_HealState();
	this->SetState(healState);
}

void AAI_Companion::SetAttackState()
{
	Companion_AttackState* attackState = new Companion_AttackState();
	this->SetState(attackState);
}

void AAI_Companion::SetFollowState()
{
	Companion_FollowState* followState = new Companion_FollowState();
	this->SetState(followState);
}

