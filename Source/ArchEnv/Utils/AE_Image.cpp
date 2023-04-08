// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_Image.h"

UTexture2D* UAE_Image::GetTexture() const
{
	return ImageTexture;
}

void UAE_Image::SetTexture(UTexture2D* Texture)
{
	this->ImageTexture = Texture;
}
