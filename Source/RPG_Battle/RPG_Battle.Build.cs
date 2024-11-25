// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RPG_Battle : ModuleRules
{
	public RPG_Battle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "TextureCompressor", "EnhancedInput", "GameplayAbilities", "GameplayTasks", "GameplayTags" });
	}
}
