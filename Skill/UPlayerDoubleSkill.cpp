#include "UPlayerDoubleSkill.h"
#include "../Character/Character.h"
#include <string>

UPlayerDoubleSkill::UPlayerDoubleSkill(ACharacter* NewOwner)
	: USkill(NewOwner,10)
{

}

void UPlayerDoubleSkill::Play(ACharacter* Target)
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

	string AttackMessage = "의 연속공격, 첫 타!";
	if (result.bCritical)
	{
		AttackMessage = "의 연속공격, 첫 타! 급소에 맞았다.";
	}
	result.PrintMessage(AttackMessage);


	bool bCriticalTwo = Owner->GetRandomInt() < Owner->GetCritical();

	if (bCriticalTwo)
	{
		Damage = static_cast<int>(Damage * 1.5);
	}
	int FinalDamageTwo = Target->TakeDamage(Damage);
	FDamageResult resultTwo;
	resultTwo.Damage = FinalDamageTwo;
	resultTwo.bCritical = bCriticalTwo;
	resultTwo.Attacker = Owner;
	resultTwo.Target = Target;

	string AttackMessageTwo = "의 연속공격, 첫 타!";
	if (result.bCritical)
	{
		AttackMessageTwo = "의 연속공격, 첫 타! 급소에 맞았다.";
	}
	resultTwo.PrintMessage(AttackMessageTwo);
}