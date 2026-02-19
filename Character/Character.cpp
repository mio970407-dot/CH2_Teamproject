#include "Character.h"
#include <random>

ACharacter::ACharacter(const string& NewName, const FUnitStat& UnitStat)
{
	Name = NewName;
	Stat = UnitStat;

	Stat.Hp = Stat.MaxHp;
	Stat.Mp = Stat.MaxMp;

	cout << "[생성] " << Name << "이 전장에 나타났습니다! (HP : " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
	cout << "[소멸] " << Name << "이 전장에서 물러납니다." << endl;
}

int ACharacter::GetRandomInt()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 99);

	return dis(gen);
}

void FDamageResult::PrintMessage(const string& AttackMessage)
{
	Attacker->PrintName();
	cout << AttackMessage << '\n';

	Target->PrintName();
	cout << "받은 데미지: " << Damage << endl;

}

FDamageResult ACharacter::Attack(ACharacter* Target)
{
	int Damage = Stat.Atk;
	bool bCritical = GetRandomInt() < Stat.Critical;

	if (bCritical)
	{
		Damage = static_cast<int>(Damage * 1.5);
	}

	int FinalDamage = Target->TakeDamage(Damage);
	FDamageResult result;
	result.Damage = FinalDamage;
	result.bCritical = bCritical;
	result.Attacker = this;
	result.Target = Target;

	return result;
}

int ACharacter::TakeDamage(int DamageAmount)
{
	DamageAmount = DamageAmount - Stat.Def;
	DamageAmount = std::max(DamageAmount, 0);

	Stat.Hp -= DamageAmount;
	Stat.Hp = std::max(Stat.Hp, 0);
	return DamageAmount;
}

void ACharacter::PlayTurn(ACharacter* Target)
{
	if (GetRandomInt() < 50)
	{
		Attack(Target);
	}
	else
	{
		UseSkill(Target);
	}
}

void ACharacter::ShowStat()
{
	cout << "[" << GetName() << "] HP: " << GetHp() << " / " << GetMaxHp() << " | MP: " << GetMp() << " / " << GetMaxMp() << endl;
}