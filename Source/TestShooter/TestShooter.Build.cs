// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestShooter : ModuleRules
{
	public TestShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		//Default setup
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

		//AI modules
        PublicDependencyModuleNames.AddRange(new string[] { "AIModule", "NavigationSystem" });

    }
}
