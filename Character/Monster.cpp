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

FDamageResult AMonster::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "이 슬렁슬렁 공격합니다.";
	if (result.bCritical)
	{
		AttackMessage = "의 공격이 어쩌다 명중합니다.";
	}
	result.PrintMessage(AttackMessage);
	return result;
}
void AMonster::UseSkill(ACharacter* Target)
{

	Stat.Mp -= 10;
	string AttackMessage = "이 흡혈을 시도합니다.";
	int Damage = Stat.Atk;
	int FinalDamage = Target->TakeDamage(Damage);
	Stat.Hp = std::min(Stat.Hp + FinalDamage, Stat.MaxHp);

	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = false;
	result.Attacker = this;
	result.Target = Target;
	result.PrintMessage(AttackMessage);
	this->PrintName();
	cout << "회복한 HP: " << FinalDamage << endl;

}
