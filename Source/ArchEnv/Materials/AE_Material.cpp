// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_Material.h"
#include "ArchEnv/Utils/AE_Image.h"

FString UAE_Material::GetName() const
{
	return Name;
}

void UAE_Material::SetName(const FString& NewName)
{
	this->Name = NewName;
}

FString UAE_Material::GetId() const
{
	return Id;
}

void UAE_Material::SetId(const FString& NewId)
{
	this->Id = NewId;
}

UAE_Image* UAE_Material::GetThumbnail() const
{
	return Thumbnail;
}

void UAE_Material::SetThumbnail(UAE_Image* NewThumbnail)
{
	this->Thumbnail = NewThumbnail;
}

UTexture2D* UAE_Material::GetTexture_Implementation()
{
	return 	Thumbnail->GetTexture();
}

UAE_CommandHandler* UAE_Material::GetCommandHandler_Implementation()
{
	return CommandHandler;
}
