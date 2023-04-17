// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_BaseCommand.h"

void UAE_BaseCommand::Initialize(UObject* NewObject)
{
	Object = NewObject;
}

void UAE_BaseCommand::Execute_Implementation()
{
	IAE_Command::Execute_Implementation();
}

FString UAE_BaseCommand::GetCommandName_Implementation()
{
	return IAE_Command::GetCommandName_Implementation();
}
