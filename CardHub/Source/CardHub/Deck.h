// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Deck.generated.h"

UCLASS()
class CARDHUB_API ADeck : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADeck();

	void Shuffle();
	void AddCard(class ACard* card);
	class ACard* DrawCard();

protected:
	UPROPERTY()
	USceneComponent* Root;

	UPROPERTY()
	class UPaperSpriteComponent* Sprite;

private:
	TArray<class ACard*> m_cards;
};
