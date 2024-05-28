// Fill out your copyright notice in the Description page of Project Settings.


#include "Companion_AttackState.h"

void Companion_AttackState::OnEnterState(AAI_Companion* companion)
{
}

void Companion_AttackState::UpdateState(AAI_Companion* companion, float deltaTime)
{
	if (companion->isAttacking)
	{
		companion->woofSound->Play();
	}
	else
	{
		companion->SetFollowState();
	}
}

void Companion_AttackState::OnExitState(AAI_Companion* companion)
{
}

Companion_AttackState::Companion_AttackState()
{
}

Companion_AttackState::~Companion_AttackState()
{
}
