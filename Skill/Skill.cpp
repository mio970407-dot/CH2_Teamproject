#include "Skill.h"
class ACharacter;


USkill::USkill(ACharacter* NewOwner, int NewMpCost)
{
	Owner = NewOwner;
	MpCost = NewMpCost;
}
