// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "CardHub.h"
#include "UObject/ConstructorHelpers.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"

// Sets default values
ACard::ACard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

ACard::ACard(int InValue, FString InSuit, FString InColor, bool InHidden, AActor* InOwner)
	: m_value(InValue), m_suit(InSuit), m_color(InColor), m_bIsHidden(InHidden), CardOwner(InOwner)
{
	PrimaryActorTick.bCanEverTick = false;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	Sprite->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	// TODO: Import assets and add valid asset paths for these object finders
	ConstructorHelpers::FObjectFinder<UPaperSprite> myFrontSprite(TEXT("SomePath"));
	ConstructorHelpers::FObjectFinder<UPaperSprite> myBackSprite(TEXT("SomePath"));

	if (myFrontSprite.Succeeded() && myBackSprite.Succeeded())
	{
		frontSprite = myFrontSprite.Object;
		backSprite = myBackSprite.Object;

		if (InHidden)
		{
			Sprite->SetSprite(backSprite);
		}
		else
		{
			Sprite->SetSprite(frontSprite);
		}
	}
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACard::OnDragStart()
{

}

void ACard::OnDrag()
{

}

void ACard::OnDragEnd()
{

}

FCardInfo ACard::GetCardInfo()
{
	FCardInfo info = FCardInfo(m_value, m_suit, m_color);

	return info;
}