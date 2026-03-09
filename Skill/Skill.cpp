#include "Skill.h"
class ACharacter;


USkill::USkill(ACharacter* NewOwner, int NewMpCost, string NewName)
{
	Owner = NewOwner;
	MpCost = NewMpCost;
	Name = NewName;
}
