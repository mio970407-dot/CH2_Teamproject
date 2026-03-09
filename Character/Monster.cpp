#include "Monster.h"
#include "../Skill/UMonsterAttackSkill.h"
#include "../Skill/UMonsterDrainSkill.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Skills.push_back(make_unique<UMonsterAttackSkill>(this));
	Skills.push_back(make_unique<UMonsterDrainSkill>(this));

}
AMonster::~AMonster()
{

}

void AMonster::PlayTurn(ACharacter* Target)
{
	int index = GetRandomInt(Skills.size());
	Skills[index]->Play(Target);

}

