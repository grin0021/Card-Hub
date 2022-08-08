// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CardHub.generated.h"

USTRUCT()
struct FCardInfo
{
	GENERATED_BODY()

	FCardInfo() : Value(0), Suit(TEXT("")), Color(TEXT("")) {}
	FCardInfo(int InValue, FString InSuit, FString InColor) : Value(InValue), Suit(InSuit), Color(InColor) {}

	int Value;
	FString Suit;
	FString Color;
};