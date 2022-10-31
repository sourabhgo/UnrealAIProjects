using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealAITarget : TargetRules
{
	public UnrealAITarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		ExtraModuleNames.Add("UnrealAI");
	}
}
