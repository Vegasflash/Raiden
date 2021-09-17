using UnrealBuildTool;
 
public class RickDevHelperTools : ModuleRules
{
	public RickDevHelperTools(ReadOnlyTargetRules Target) : base(Target)
	{
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "UnrealEd"});
 
		PublicIncludePaths.AddRange(new string[] {"RickDevHelperTools/Public"});
		PrivateIncludePaths.AddRange(new string[] {"RickDevHelperTools/Private"});
	}
}