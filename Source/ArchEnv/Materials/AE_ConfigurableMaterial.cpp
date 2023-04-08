// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_ConfigurableMaterial.h"
#include "ArchEnv/Utils/AE_Image.h"

FString UAE_ConfigurableMaterial::GetName() const
{
	return Name;
}

void UAE_ConfigurableMaterial::SetName(const FString& NewName)
{
	this->Name = NewName;
}

FString UAE_ConfigurableMaterial::GetId() const
{
	return Id;
}

void UAE_ConfigurableMaterial::SetId(const FString& NewId)
{
	this->Id = NewId;
}

UAE_Image* UAE_ConfigurableMaterial::GetThumbnail() const
{
	return Thumbnail;
}

void UAE_ConfigurableMaterial::SetThumbnail(UAE_Image* NewThumbnail)
{
	this->Thumbnail = NewThumbnail;
}

UTexture2D* UAE_ConfigurableMaterial::GetTexture_Implementation()
{
	return 	Thumbnail->GetTexture();
}
