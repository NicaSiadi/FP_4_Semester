// Copyright N.A. Tools 2025. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Styling/SlateTypes.h"
#include "UObject/CoreNative.h"
#include "SlickNodesConfig.generated.h"

struct FPropertyChangedEvent; // forward declare

UCLASS(config=EditorPerProjectUserSettings, defaultconfig, meta=(DisplayName="Slick Nodes"))
class SLICKNODES_API USlickNodesConfig : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	USlickNodesConfig(const FObjectInitializer& ObjectInitializer);

	virtual FName GetContainerName() const override
	{
		return TEXT("Editor");
	}

	virtual FName GetCategoryName() const override
	{
		return TEXT("Plugins");
	}

	virtual FName GetSectionName() const override
	{
		return TEXT("SlickNodes");
	}

#if WITH_EDITOR
	// NUR Deklarationen, KEIN Rumpf hier!
	virtual FText GetSectionText() const override;
	virtual FText GetSectionDescription() const override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif


	//Tutorial
	
	//Customize/General
	UPROPERTY(config, EditAnywhere, Category = "Node Settings", DisplayName = "Overwrite Nodes", meta =(ConfigRestartRequired = true))
	bool bOverwriteNodes;
	
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|General", DisplayName = "Title Text Color", meta = (EditCondition = "bOverwriteNodes", sRGB = "true", AllowReset = "true"))
	FLinearColor NodeTitleColor = FColor::FromHex(TEXT("#FFFF"));
	
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|General", DisplayName = "Outline Color", meta = (EditCondition = "bOverwriteNodes", sRGB = "true", AllowReset = "true"))
	FLinearColor NodeOutlineColor = FColor::FromHex(TEXT("#FFFF"));
	
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|General", DisplayName = "Brightness", meta = (EditCondition = "bOverwriteNodes", sRGB = "true", ClampMin = "0", ClampMax = "1"))
	float NodeBrightness = 0.5f;
	

	//Customize/Node
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|RegularNode", DisplayName = "Header (64x32)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x32 texture to override the icon for the node header.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularNodeHeader;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|RegularNode", DisplayName = "Header Highlight (64x22)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x22 texture to override the icon for the node header highlight.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularNodeTitleHighlight;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|RegularNode", DisplayName = "Header Gloss (64x25)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x25 texture to override the icon for the node header gloss.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularNodeHeaderGloss;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|RegularNode", DisplayName = "Body (64x64)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x64 texture to override the icon for the node body.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularNodeBody;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|RegularNode", DisplayName = "Body Gloss (64x64)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x64 texture to override the icon for the node body gloss.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularNodeBodyGloss;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|RegularNode", DisplayName = "Shadow (64x64)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x64 texture to override the icon for the node shadow.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularNodeShadow;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|RegularNode", DisplayName = "Selected Border (64x64)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x64 texture to override the icon for the node selection border.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularNodeSelected;
	

	//Customize/VariableNode
		//Pins
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|VariableNode", DisplayName = "Header (132x28)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 132x28 texture to override the icon for the variable header.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableNodeHeader;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|VariableNode", DisplayName = "Body (64x28)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x28 texture to override the icon for the variable body.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableNodeBody;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|VariableNode", DisplayName = "Shadow (64x64)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x64 texture to override the icon for the variable shadow.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableNodeShadow;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|VariableNode", DisplayName = "Selected Border (64x64)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x64 texture to override the icon for the variable selection border.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableNodeSelected;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|VariableNode", DisplayName = "Gloss (64x28)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x28 texture to override the icon for the variable gloss.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableNodeGloss;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|VariableNode", DisplayName = "Collapsed Header (64x28)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x28 texture to override the icon for the variable gloss.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableNodeCollapsedHeader;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|VariableNode", DisplayName = "Collapsed Body (64x28)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 64x28 texture to override the icon for the variable gloss.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableNodeCollapsedBody;
	

	
	//Customize/Pins
	
		//Variable
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Variable Texture (11x11)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 16x16 texture to override the icon for variables.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableTexture;

		//Array
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Array Texture (16x16)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 16x16 texture to override the icon for arrays.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> ArrayTexture;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Array Connected(11x11)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 11x11 texture to override the icon for arrays when connected.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> ArrayTextureConnected;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Array Disconnected(11x11)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 11x11 texture to override the icon for arrays when disconnected.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> ArrayTextureDisconnected;

		//Map
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Map Connected(16x16)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 16x16 texture to override the icon for maps when connected.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> MapTextureConnected;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Map Disonnected(16x16)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 16x16 texture to override the icon for maps when disconnected.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> MapTextureDisconnected;

		//Exec Pins
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "ExecPin Connected (96x128)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 96x128 texture to override the icon for the node exec pin.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularExecPinConnected;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "ExecPin Disconnected (96x128)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 96x128 texture to override the icon for the node exec pin.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularExecPinDisconnected;

		//Delegate Pins
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Delegate Pin Connected (16x16)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 16x16 texture to override the icon for the node delegate pin.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularDelegatePinConnected;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Delegate Pin Disconnected (16x16)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 16x16 texture to override the icon for the node delegate pin.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularDelegatePinDisconnected;

		//Round pins
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Regular Round Pin Connected (15x11)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 15x11 texture to override the icon for the node round pin.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularRoundPinConnected;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Regular Round Pin Disconnected (15x11)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 15x11 texture to override the icon for the node round pin.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> RegularRoundPinDisconnected;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Variable Round Pin Connected (15x11)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 15x11 texture to override the icon for the variable round pin.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableRoundPinConnected;
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Variable Round Pin Disconnected (15x11)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 15x11 texture to override the icon for the variable round pin.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> VariableRoundPinDisconnected;

		//Hovered Over
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Pin hovered (32x8)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 32x8 texture to override the icon for the hovered over pin state.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> PinHovered;

		//Simulation Bubble
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Icons", DisplayName = "Simulation mode bubble (32x32)", meta = (EditCondition = "bOverwriteNodes", AllowedClasses = "/Script/Engine.Texture2D", Tooltip = "Set a 32x32 texture to override the icon for the bubbles in simulation mode.\nIMPORTANT: Set import settings to the following Texture Group = UI, Compression Settings = VectorDisplacementmap, sRGB = false", ConfigRestartRequired = true, sRGB = "false"))
	TSoftObjectPtr<UTexture2D> SimulationBubble;

	//Customize/Colors
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Overwrite Colors", meta =(ConfigRestartRequired = true))
	bool bOverwriteColors = true;
	
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Event Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor EventNodeColor = FColor::FromHex(TEXT("#fc2f2f"));
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Function Call Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor FunctionCallNodeColor = FColor::FromHex(TEXT("#0088FFFF"));
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Pure Function Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor PureFunctionNodeColor = FColor::FromHex(TEXT("#00C16BFF"));
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Parent Function Call Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor ParentFunctionNodeColor = FColor::FromHex(TEXT("#FF931BFF"));
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Function Terminator Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor FunctionTerminatorColor = FColor::FromHex(TEXT("#C93EFFFF"));
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Branch Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor BranchNodeColor = FColor::FromHex(TEXT("#656565FF"));
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Sequence Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor SequenceNodeColor = FColor::FromHex(TEXT("#656565FF"));
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Result Node Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor ResultNodeColor = FColor::FromHex(TEXT("#f8cfa8"));
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Default Comment Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor DefaultCommentNodeColor = FColor::FromHex(TEXT("#656565FF"));
	UPROPERTY(config, EditAnywhere, Category = "Node Settings|Customize|Colors|Nodes", DisplayName = "Preview Node", meta = (EditCondition = "bOverwriteColors"))
	FLinearColor PreviewNodeColor = FColor::FromHex(TEXT("#2770fc"));



	
	//Graph/BrightnessOfGraph
	UPROPERTY(config, EditAnywhere, Category = "Graph", DisplayName = "Brightness", meta = (ClampMin = "0", ClampMax = "1"))
	float GraphBrightness = 0.25f;

	//Graph/GridBackgroundColor
	UPROPERTY(config, EditAnywhere, Category = "Graph", DisplayName = "Grid BackgroundColor", meta = (sRGB = "true", AllowReset = "true"))
	FLinearColor GridBackgroundColor = FColor::FromHex(TEXT("#282828FF"));
	TMap<FString, FSlateBrush*> SlateBrushes;
	
};