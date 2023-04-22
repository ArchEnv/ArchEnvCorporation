// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_Material.h"
#include "ArchEnv/Utils/AE_Image.h"

FString UAE_Material::GetMaterialName() const
{
	return MaterialInfo.MaterialName.ToString();
}

void UAE_Material::SetMaterialName(const FString& NewName)
{
	this->MaterialInfo.MaterialName = FText::FromString(NewName);
}

FString UAE_Material::GetMaterialId() const
{
	return MaterialInfo.MaterialId;
}

void UAE_Material::SetMaterialId(const FString& NewId)
{
	this->MaterialInfo.MaterialId = NewId;
}

FString UAE_Material::GetImageId()
{
	return MaterialInfo.ImageId;
}

void UAE_Material::SetImageId(const FString& NewId)
{
	MaterialInfo.ImageId = NewId;
}

UAE_Image* UAE_Material::GetMaterialImage() const
{
	return MaterialImage;
}

void UAE_Material::SetMaterialImage(UAE_Image* NewMaterialImage)
{
	this->MaterialImage = NewMaterialImage;
}

UTexture2D* UAE_Material::GetTexture()
{
	return 	MaterialImage->GetTexture();
}

UAE_CommandHandler* UAE_Material::GetCommandHandler_Implementation()
{
	return CommandHandler;
}
