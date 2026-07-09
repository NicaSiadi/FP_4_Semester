// CrosshairTraceComponent.h
// Packe diese Component zusätzlich auf deinen (BP-)Character.
// Sie macht jeden Tick einen LineTrace von der Kamera aus, sucht am
// getroffenen Actor eine UInteractionCrosshairComponent und feuert
// ein Event mit dem passenden Icon (oder nullptr, wenn nichts getroffen wird).

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "CrosshairTraceComponent.generated.h"

class UInteractionCrosshairComponent;
class UCameraComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCrosshairIconChanged, UTexture2D*, NewIcon, FText, NewLabel);

UCLASS(ClassGroup = (Interaction), meta = (BlueprintSpawnableComponent))
class FP_4_SEMESTER_API UCrosshairTraceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UCrosshairTraceComponent();

	// Wie weit der Trace reicht.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshair Trace")
	float TraceRange = 500.f;

	// Auf welchem Collision-Channel getraced wird (z.B. Visibility oder ein eigener "Interaction"-Channel).
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshair Trace")
	TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;

	// Optional: Kamera manuell zuweisen. Wenn leer, wird automatisch die erste
	// UCameraComponent am Owner-Actor gesucht.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshair Trace")
	TObjectPtr<UCameraComponent> CameraOverride;

	// Debug-Linie im Viewport zeichnen.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crosshair Trace")
	bool bDrawDebugTrace = false;

	// Feuert, sobald sich das anzuzeigende Icon ändert (auch auf nullptr, wenn nichts mehr getroffen wird).
	UPROPERTY(BlueprintAssignable, Category = "Crosshair Trace")
	FOnCrosshairIconChanged OnCrosshairIconChanged;

	UFUNCTION(BlueprintPure, Category = "Crosshair Trace")
	UTexture2D* GetCurrentIcon() const { return CurrentIcon; }

	UFUNCTION(BlueprintPure, Category = "Crosshair Trace")
	FText GetCurrentLabel() const { return CurrentLabel; }

protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	TObjectPtr<UCameraComponent> ResolvedCamera;

	UPROPERTY()
	TObjectPtr<UInteractionCrosshairComponent> CurrentTarget;

	UPROPERTY()
	TObjectPtr<UTexture2D> CurrentIcon;

	UPROPERTY()
	FText CurrentLabel;

	void PerformTrace();
	void SetCurrentTarget(UInteractionCrosshairComponent* NewTarget);
};