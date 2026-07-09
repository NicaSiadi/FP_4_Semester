// InteractionCrosshairComponent.h
// Packe diese Component auf jeden Actor, der beim Anvisieren (LineTrace)
// ein eigenes Crosshair-Icon anzeigen soll.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionCrosshairComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartLookAt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStopLookAt);

UCLASS(ClassGroup = (Interaction), meta = (BlueprintSpawnableComponent))
class FP_4_SEMESTER_API UInteractionCrosshairComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UInteractionCrosshairComponent();

	// Icon, das im Crosshair angezeigt wird, wenn dieser Actor per LineTrace getroffen wird.
	// Pro Actor-Instanz im Details-Panel einstellbar.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshair")
	TObjectPtr<UTexture2D> CrosshairIcon;

	// Optionaler Text, z.B. "Öffnen [E]" - falls du sowas später am Crosshair anzeigen willst.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshair")
	FText InteractionLabel;

	// Wird von deinem Player-Trace aufgerufen, sobald der Trace diesen Actor NEU trifft.
	UFUNCTION(BlueprintCallable, Category = "Crosshair")
	void NotifyLookAtStart();

	// Wird von deinem Player-Trace aufgerufen, sobald der Trace diesen Actor NICHT mehr trifft.
	UFUNCTION(BlueprintCallable, Category = "Crosshair")
	void NotifyLookAtEnd();

	UFUNCTION(BlueprintPure, Category = "Crosshair")
	UTexture2D* GetCrosshairIcon() const { return CrosshairIcon; }

	UFUNCTION(BlueprintPure, Category = "Crosshair")
	bool HasCustomCrosshairIcon() const { return CrosshairIcon != nullptr; }

	// Blueprint-Events, falls du z.B. zusätzlich ein Outline-Highlight triggern willst.
	UPROPERTY(BlueprintAssignable, Category = "Crosshair")
	FOnStartLookAt OnStartLookAt;

	UPROPERTY(BlueprintAssignable, Category = "Crosshair")
	FOnStopLookAt OnStopLookAt;

private:
	bool bIsCurrentlyLookedAt = false;
};