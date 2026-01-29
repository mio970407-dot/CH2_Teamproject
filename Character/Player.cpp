#include "Player.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;
}

FDamageResult APlayer::Attack(ACharacter* Target)
{
	FDamageResult result = ACharacter::Attack(Target);
	string AttackMessage = "이 침착하게 공격합니다.";
	if (result.bCritical)
	{
		AttackMessage = "의 돌팔매가 이마에 명중합니다!";
	}
	cout << Name << AttackMessage << endl << "데미지: " << result.Damage << endl;
	cout << Target->GetName() << "의 HP: " << Target->GetHp() << endl << endl;
	return result;
}

void APlayer::UseItem()
{
};

void APlayer::LevelUp()
{
};

