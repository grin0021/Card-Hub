// Fill out your copyright notice in the Description page of Project Settings.


#include "Deck.h"
#include "Card.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "CardHubPlayer.h"

// Sets default values
ADeck::ADeck()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	check(Root);
	SetRootComponent(Root);

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	check(Sprite);
	Sprite->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Sprite->AttachTo(Root);

	// TODO: Add sprite to content folder and provide valid path
	ConstructorHelpers::FObjectFinder<UPaperSprite> deckSprite(TEXT("/Game/Sprites/Clean/CardBack.CardBack"));

	if (deckSprite.Succeeded())
	{
		Sprite->SetSprite(deckSprite.Object);
	}
}

void ADeck::Shuffle()
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 1; j < m_cards.Num() / 2; ++j)
		{
			ACard* card1;
			ACard* card2;

			int32 randIndex1 = 0;
			int32 randIndex2 = 0;

			do
			{
				randIndex1 = FMath::RandRange(0, m_cards.Num() - 1);
				card1 = m_cards[randIndex1];
			} while (card1->bShuffled);

			do
			{
				randIndex2 = FMath::RandRange(0, m_cards.Num() - 1);
				card2 = m_cards[randIndex2];
			} while (card2->bShuffled || (card2 == card1));

			m_cards[randIndex1] = card2;
			m_cards[randIndex2] = card1;

			card1->bShuffled = true;
			card2->bShuffled = true;
		}

		for (auto card : m_cards)
		{
			card->bShuffled = false;
		}
	}
}

void ADeck::AddCard(ACard* card)
{
	m_cards.Add(card);
}

ACard* ADeck::DrawCard()
{
	if (m_cards.Num() == 0)
	{
		return nullptr;
	}
		
	ACard* drawnCard = m_cards[m_cards.Num() - 1];
	m_cards.Remove(drawnCard);

	return drawnCard;
		
}