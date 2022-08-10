// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpriteContainer.generated.h"

UCLASS()
class CARDHUB_API ASpriteContainer : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpriteContainer();

	class UPaperSprite* GetSprite(FString suit, int value);

protected:
	UPROPERTY(EditAnywhere)
	TArray<UPaperSprite*> clubCards;

	UPROPERTY(EditAnywhere)
	TArray<UPaperSprite*> diamondCards;

	UPROPERTY(EditAnywhere)
	TArray<UPaperSprite*> heartCards;

	UPROPERTY(EditAnywhere)
	TArray<UPaperSprite*> spadeCards;
};
