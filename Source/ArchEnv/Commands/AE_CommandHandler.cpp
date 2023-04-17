// Fill out your copyright notice in the Description page of Project Settings.


#include "AE_CommandHandler.h"

TArray<UAE_BaseCommand*> UAE_CommandHandler::GetCommands()
{
	return Commands;
}

void UAE_CommandHandler::AddCommand(UAE_BaseCommand* NewCommand)
{
	Commands.Add(NewCommand);
}

void UAE_CommandHandler::RemoveCommand(UAE_BaseCommand* NewCommand)
{
	Commands.Remove(NewCommand);
}
