// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AI_CompanionState.h"
#include "AI_Companion.h"
#include "CoreMinimal.h"

class AAI_Companion;

/**
 * 
 */
class AIBEHAVIOR_API Companion_HealState : public ICompanionState
{

public:
	virtual void OnEnterState(AAI_Companion* companion) override;
	virtual void UpdateState(AAI_Companion* companion, float deltaTime) override;
	virtual void OnExitState(AAI_Companion* companion) override;

public:
	Companion_HealState();
	~Companion_HealState();
};
