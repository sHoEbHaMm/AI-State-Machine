// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class AAI_Companion;

/**
 * 
 */
class ICompanionState
{
public:

	virtual void OnEnterState(AAI_Companion* companion) {}
	virtual void UpdateState(AAI_Companion* companion, float deltaTime) {}
	virtual void OnExitState(AAI_Companion* companion) {}
};

class AIBEHAVIOR_API AI_CompanionState
{
public:
	AI_CompanionState();
	~AI_CompanionState();
};
