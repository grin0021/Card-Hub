// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"
#include "CardHub.h"
#include "EngineUtils.h"
#include "PaperSpriteComponent.h"
#include "PaperSprite.h"
#include "SpriteContainer.h"

// Sets default values
ACard::ACard()
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

	ConstructorHelpers::FObjectFinder<UPaperSprite> backFace(TEXT("/Game/Sprites/Clean/CardBack.CardBack"));

	if (backFace.Succeeded())
	{
		backSprite = backFace.Object;
	}
	
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
}

void ACard::Initialize(int InValue, FString InSuit, bool InHidden, AActor* InOwner)
{
	m_value = InValue;
	m_suit = InSuit;
	m_bIsHidden = InHidden;
	CardOwner = InOwner;

	if (m_bIsHidden)
	{
		Sprite->SetSprite(backSprite);
		return;
	}

	for (TActorIterator<ASpriteContainer>ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		ASpriteContainer* spriteCont = Cast<ASpriteContainer>(*ActorItr);
	
		Sprite->SetSprite(spriteCont->GetSprite(m_suit, m_value));
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
	FCardInfo info = FCardInfo(m_value, m_suit);

	return info;
}