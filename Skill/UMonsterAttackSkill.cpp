#include "UMonsterAttackSkill.h"
#include "../Character/Character.h"
#include <string>

UMonsterAttackSkill::UMonsterAttackSkill(ACharacter* NewOwner)
	:USkill(NewOwner,0)
{

}

void UMonsterAttackSkill::Play(ACharacter* Target)
{
	int Damage = Owner->GetAtk();
	bool bCritical = Owner->GetRandomInt() < Owner->GetCritical();

	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5);
	}

	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = bCritical;
	result.Attacker = Owner;
	result.Target = Target;
	string AttackMessage = "이 슬렁슬렁 공격합니다.";
	if (result.bCritical)
	{
		AttackMessage = "의 공격이 어쩌다 명중합니다.";
	}
	result.PrintMessage(AttackMessage);
}