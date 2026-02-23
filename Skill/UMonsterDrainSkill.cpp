#include "UMonsterDrainSkill.h"
#include "../Character/Character.h"
#include <string>

UMonsterDrainSkill::UMonsterDrainSkill(ACharacter* NewOwner)
	: USkill(NewOwner)
{

}

void UMonsterDrainSkill::Play(ACharacter* Target)
{
	string AttackMessage = "이 흡혈을 시도합니다.";
	int Damage = Owner->GetAtk();
	int FinalDamage = Target->TakeDamage(Damage);
	Owner->Heal(FinalDamage);

	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = false;
	result.Attacker = Owner;
	result.Target = Target;
	result.PrintMessage(AttackMessage);
	Owner->PrintName();
	cout << "회복한 HP: " << FinalDamage << endl;
}