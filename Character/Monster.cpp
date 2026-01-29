#include "Monster.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
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
	cout << Name << AttackMessage << endl << "데미지: " << result.Damage << endl;
	cout << Target->GetName() << "의 HP: " << Target->GetHp() << endl << endl;
	return result;
}