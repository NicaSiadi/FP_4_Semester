// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FP_4_Semester : ModuleRules
{
	public FP_4_Semester(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"FP_4_Semester",
			"FP_4_Semester/Variant_Horror",
			"FP_4_Semester/Variant_Horror/UI",
			"FP_4_Semester/Variant_Shooter",
			"FP_4_Semester/Variant_Shooter/AI",
			"FP_4_Semester/Variant_Shooter/UI",
			"FP_4_Semester/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
