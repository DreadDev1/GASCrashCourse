#include "GameplayTags/GCC_Tags.h"

namespace GCC_Tags
{
	namespace GCC_Abilities
	{
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(ActivateOnGiven, "GCC_Tags.Abilities.ActivateOnGiven", "Tag for Abilities that should activate immediately once given.")
		
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Primary, "GCC_Tags.Abilities.Primary", "Tag for the Primary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Secondary, "GCC_Tags.Abilities.Secondary", "Tag for the Secondary Ability")
		UE_DEFINE_GAMEPLAY_TAG_COMMENT(Tertiary, "GCC_Tags.Abilities.Tertiary", "Tag for the Tertiary Ability")
	}

	
	namespace Events
	{
		namespace Enemy
		{
			UE_DEFINE_GAMEPLAY_TAG_COMMENT(HitReact, "GCC_Tags.Events.Enemy.HitReact", "Tag for the Enemy HitReact Event")
		}
	}
}