#include "UPlayerStrikeSkill.h"
#include "../Character/Character.h"
#include <string>


UPlayerStrikeSkill::UPlayerStrikeSkill(ACharacter* NewOwner)
	: USkill(NewOwner,10)
{

}

void UPlayerStrikeSkill::Play(ACharacter* Target)
{
	string AttackMessage = "이 강력한 공격을 준비합니다.";
	int Damage = 2 * Owner->GetAtk();
	int FinalDamage = Target->TakeDamage(Damage);

	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = false;
	result.Attacker = Owner;
	result.Target = Target;
	result.PrintMessage(AttackMessage);
}