// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Card.generated.h"

UCLASS()
class CARDHUB_API ACard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACard();
	ACard(int InValue, FString InSuit, FString InColor, bool InHidden, AActor* InOwner);

	struct FCardInfo GetCardInfo();

	void OnDragStart();
	void OnDrag();
	void OnDragEnd();

	void SetIsHidden(bool hidden) { m_bIsHidden = hidden; }

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	class UPaperSprite* frontSprite;

	UPROPERTY()
	class UPaperSprite* backSprite;

	UPROPERTY()
	class UPaperSpriteComponent* Sprite;

	UPROPERTY()
	AActor* CardOwner;

private:
	int m_value;
	bool m_bIsHidden;
	FString m_suit;
	FString m_color;
};
