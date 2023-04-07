// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_HUD.h"

AAE_Entity* AAE_HUD::GetSelectedEntity() const
{
	return SelectedEntity;
}

void AAE_HUD::SetSelectedEntity(AAE_Entity* NewSelectedEntity)
{
	this->SelectedEntity = NewSelectedEntity;
}

AAE_HUD::AAE_HUD()
{
	
}
