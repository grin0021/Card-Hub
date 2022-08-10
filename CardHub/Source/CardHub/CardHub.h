// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CardHub.generated.h"

USTRUCT()
struct FCardInfo
{
	GENERATED_BODY()

	FCardInfo() : Value(0), Suit(TEXT("")) {}
	FCardInfo(int InValue, FString InSuit) : Value(InValue), Suit(InSuit) {}

	int Value;
	FString Suit;
};