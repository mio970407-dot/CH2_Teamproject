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
	result.PrintMessage(AttackMessage);
	return result;
}

void APlayer::UseSkill(ACharacter* Target)
{
	if (Stat.Mp < 10)
	{
		cout << "MP가 모자라 스킬을 사용할 수 없습니다." << endl;
		return;
	}

	Stat.Mp -= 10;
	string AttackMessage = "이 강력한 공격을 준비합니다.";
	int Damage = 2 * Stat.Atk;
	int FinalDamage = Target->TakeDamage(Damage);

	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = false;
	result.Attacker = this;
	result.Target = Target;
	result.PrintMessage(AttackMessage);
}

void APlayer::UseItem()
{
};

void APlayer::LevelUp()
{
};

