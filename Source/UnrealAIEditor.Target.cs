using UnrealBuildTool;
using System.Collections.Generic;

public class UnrealAIEditorTarget : TargetRules
{
	public UnrealAIEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.Add("UnrealAI");
	}
}
