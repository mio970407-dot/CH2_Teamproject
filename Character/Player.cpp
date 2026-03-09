#include "Player.h"
#include "../Skill/UPlayerAttackSkill.h"
#include "../Skill/UPlayerDoubleSkill.h"
#include "../Skill/UPlayerStrikeSkill.h"

APlayer::APlayer(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
	Level = 1;
	Exp = 0;

	Skills.push_back(make_unique<UPlayerAttackSkill>(this));
	Skills.push_back(make_unique<UPlayerDoubleSkill>(this));
	Skills.push_back(make_unique<UPlayerStrikeSkill>(this));
}

APlayer::~APlayer()
{ 

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

