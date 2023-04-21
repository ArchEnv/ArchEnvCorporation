// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_Image.h"

UTexture2D* UAE_Image::GetTexture() const
{
	return ImageInfo.ImageTexture;
}

void UAE_Image::SetTexture(UTexture2D* Texture)
{
	this->ImageInfo.ImageTexture = Texture;
}

FString UAE_Image::GetImageId()
{
	return ImageInfo.ImageId;
}

void UAE_Image::SetImageId(FString NewId)
{
	ImageInfo.ImageId = NewId;
}
