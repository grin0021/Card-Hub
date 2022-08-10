// Copyright Epic Games, Inc. All Rights Reserved.


#include "CardHubGameModeBase.h"
#include "EngineUtils.h"
#include "Card.h"
#include "Deck.h"

void ACardHubGameModeBase::BeginPlay()
{
	for (TActorIterator<ADeck>ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		m_deck = Cast<ADeck>(*ActorItr);
	}

	if (m_deck)
	{
		for (auto suit : m_suits)
		{
			for (int i = 1; i < 14; ++i)
			{
				ACard* card = GetWorld()->SpawnActor<ACard>(ACard::StaticClass());
				card->Initialize(i, suit, true, m_deck);
				m_deck->AddCard(card);
			}
		}
	}
}