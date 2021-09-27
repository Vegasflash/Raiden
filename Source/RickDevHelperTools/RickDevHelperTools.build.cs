using UnrealBuildTool;
 
public class RickDevHelperTools : ModuleRules
{
	public RickDevHelperTools(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"Engine",
			"CoreUObject",
			"InputCore",
			"LevelEditor",
			"Slate",
			"EditorStyle",
			"AssetTools",
			"EditorWidgets",
			"UnrealEd",
			"BlueprintGraph",
			"AnimGraph",
			"ComponentVisualizers",
			"Raiden",
		});

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"AppFramework",
				"SlateCore",
				"AnimGraph",
				"UnrealEd",
				"KismetWidgets",
				"MainFrame",
				"PropertyEditor",
				"ComponentVisualizers",
				"Raiden",
		});

		PublicIncludePaths.AddRange(new string[] {
			"RickDevHelperTools/Public",
		});

		PrivateIncludePaths.AddRange(new string[] {"RickDevHelperTools/Private"});
	}
}