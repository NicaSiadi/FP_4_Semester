// InteractionCrosshairComponent.cpp

#include "InteractionCrosshairComponent.h"

UInteractionCrosshairComponent::UInteractionCrosshairComponent()
{
	// Diese Component muss nicht ticken, sie ist reiner Datenhalter + Event-Broadcaster.
	PrimaryComponentTick.bCanEverTick = false;
}
	// wenn du drauf schaust
void UInteractionCrosshairComponent::NotifyLookAtStart()
{
	if (bIsCurrentlyLookedAt)
	{
		return;
	}

	bIsCurrentlyLookedAt = true;
	OnStartLookAt.Broadcast();
}

void UInteractionCrosshairComponent::NotifyLookAtEnd()
{
	if (!bIsCurrentlyLookedAt)
	{
		return;
	}

	bIsCurrentlyLookedAt = false;
	OnStopLookAt.Broadcast();
}