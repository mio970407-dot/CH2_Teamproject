#include "Character.h"
#include <random>

ACharacter::ACharacter(const string& NewName, const FUnitStat& NewStat)
{
	Name = NewName;
	Stat = NewStat;

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
