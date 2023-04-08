// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_MaterialController.h"

TArray<UAE_ConfigurableMaterial*> UAE_MaterialController::GetConfigurableMaterials() const
{
	return ConfigurableMaterials;
}

void UAE_MaterialController::SetConfigurableMaterials(const TArray<UAE_ConfigurableMaterial*>& NewConfigurableMaterials)
{
	this->ConfigurableMaterials = NewConfigurableMaterials;
}
