// Fill out your copyright notice in the Description page of Project Settings.


#include "Companion_HealState.h"

void Companion_HealState::OnEnterState(AAI_Companion* companion)
{
	
}

void Companion_HealState::UpdateState(AAI_Companion* companion, float deltaTime)
{
	if (companion->isHealing)
	{
		companion->SetActorLocation(companion->referencePositionWhileHealing);
		companion->SetActorRotation(companion->referenceRotationWhileHealing);
	}
	else
	{
		companion->SetFollowState();
	}
}

void Companion_HealState::OnExitState(AAI_Companion* companion)
{
}

Companion_HealState::Companion_HealState()
{
}

Companion_HealState::~Companion_HealState()
{
}
