// Fill out your copyright notice in the Description page of Project Settings.


#include "Companion_FollowState.h"
#include "AI_Companion.h"

void Companion_FollowState::OnEnterState(AAI_Companion* companion)
{
}

void Companion_FollowState::UpdateState(AAI_Companion* companion, float deltaTime)
{
	if (companion->isRefPosSet)
	{
		FVector targetPos = companion->referencePosition;

		FVector newLocation = UKismetMathLibrary::VInterpTo_Constant(companion->GetActorLocation(), targetPos, deltaTime, 300.0f);

		FRotator newRotation = companion->GetVelocity().Rotation();

		companion->SetActorRotation(newRotation);
		companion->SetActorLocation(newLocation);
	}
}

void Companion_FollowState::OnExitState(AAI_Companion* companion)
{
}

Companion_FollowState::Companion_FollowState()
{
}

Companion_FollowState::~Companion_FollowState()
{
}

