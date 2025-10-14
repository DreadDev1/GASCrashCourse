#include "GameplayTags/GCC_Tags.h"

namespace GCCTags
{
	namespace Abilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "GCCTags.Abilities.ActivateOnGiven", "Tag for Abilities that should activate immediately once given.")
		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "GCCTags.Abilities.Primary", "Tag for the Primary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "GCCTags.Abilities.Secondary", "Tag for the Secondary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "GCCTags.Abilities.Tertiary", "Tag for the Tertiary Ability")
	}

	namespace Events
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(KillScored, "GCCTags.Events.KillScored", "Tag for the KillScored Event")
		
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "GCCTags.Events.Enemy.HitReact", "Tag for the Enemy HitReact Event")
		}
	}
}