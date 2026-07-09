// CrosshairTraceComponent.cpp

#include "CrosshairTraceComponent.h"
#include "InteractionCrosshairComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Actor.h"
#include "DrawDebugHelpers.h"

UCrosshairTraceComponent::UCrosshairTraceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.TickGroup = TG_PostUpdateWork; // nach Movement/Camera-Update tracen
}

void UCrosshairTraceComponent::BeginPlay()
{
	Super::BeginPlay();

	if (CameraOverride)
	{
		ResolvedCamera = CameraOverride;
	}
	else if (AActor* Owner = GetOwner())
	{
		ResolvedCamera = Owner->FindComponentByClass<UCameraComponent>();
	}

	if (!ResolvedCamera)
	{
		UE_LOG(LogTemp, Warning, TEXT("CrosshairTraceComponent: Keine UCameraComponent am Owner '%s' gefunden."), *GetOwner()->GetName());
	}
}

void UCrosshairTraceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ResolvedCamera)
	{
		PerformTrace();
	}
}

void UCrosshairTraceComponent::PerformTrace()
{
	const FVector Start = ResolvedCamera->GetComponentLocation();
	const FVector End = Start + ResolvedCamera->GetForwardVector() * TraceRange;

	FCollisionQueryParams Params(SCENE_QUERY_STAT(CrosshairTrace), false);
	Params.AddIgnoredActor(GetOwner());

	FHitResult Hit;
	const bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, TraceChannel, Params);

	if (bDrawDebugTrace)
	{
		DrawDebugLine(GetWorld(), Start, End, bHit ? FColor::Green : FColor::Red, false, 0.f, 0, 1.f);
	}

	UInteractionCrosshairComponent* NewTarget = nullptr;
	if (bHit && Hit.GetActor())
	{
		NewTarget = Hit.GetActor()->FindComponentByClass<UInteractionCrosshairComponent>();
	}

	SetCurrentTarget(NewTarget);
}

void UCrosshairTraceComponent::SetCurrentTarget(UInteractionCrosshairComponent* NewTarget)
{
	if (NewTarget == CurrentTarget)
	{
		return;
	}

	// Alten Target Bescheid geben, dass er nicht mehr angeschaut wird.
	if (CurrentTarget)
	{
		CurrentTarget->NotifyLookAtEnd();
	}

	CurrentTarget = NewTarget;

	// Neuen Target Bescheid geben + Icon ermitteln.
	if (CurrentTarget)
	{
		CurrentTarget->NotifyLookAtStart();
		CurrentIcon = CurrentTarget->GetCrosshairIcon();
		CurrentLabel = CurrentTarget->InteractionLabel;
	}
	else
	{
		CurrentIcon = nullptr;
		CurrentLabel = FText::GetEmpty();
	}

	OnCrosshairIconChanged.Broadcast(CurrentIcon, CurrentLabel);
}