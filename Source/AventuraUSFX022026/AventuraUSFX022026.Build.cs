// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AventuraUSFX022026 : ModuleRules
{
	public AventuraUSFX022026(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
	}
}
