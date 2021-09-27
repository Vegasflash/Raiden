// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RaidenEditorTarget : TargetRules
{
	public RaidenEditorTarget( TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.AddRange( new string[] { "RickDevHelperTools" } );
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string[] { "Raiden" } );
		ExtraModuleNames.AddRange(new string[] { "RickDevHelperTools" });
	}
}
