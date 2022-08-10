// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CardHubGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CARDHUB_API ACardHubGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	TArray<FString> m_suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ADeck* m_deck;
};
