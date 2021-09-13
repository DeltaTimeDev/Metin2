// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Metin2 : ModuleRules
{
	public Metin2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "GameplayAbilities", "GameplayTags", "GameplayTasks", "NavigationSystem", "AIModule" });
	}
}
