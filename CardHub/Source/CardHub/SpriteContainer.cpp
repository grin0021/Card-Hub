// Fill out your copyright notice in the Description page of Project Settings.


#include "SpriteContainer.h"

// Sets default values
ASpriteContainer::ASpriteContainer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

UPaperSprite* ASpriteContainer::GetSprite(FString suit, int value)
{
	if (suit == "Clubs")
	{
		return clubCards[value - 1];
	}
	else if (suit == "Diamonds")
	{
		return diamondCards[value - 1];
	}
	else if (suit == "Hearts")
	{
		return heartCards[value - 1];
	}
	else if (suit == "Spades")
	{
		return spadeCards[value - 1];
	}

	return nullptr;
}