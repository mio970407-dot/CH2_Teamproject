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

int ACharacter::GetRandomInt(int Max)
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, Max-1);

	return dis(gen);
}

void FDamageResult::PrintMessage(const string& AttackMessage)
{
	Attacker->PrintName();
	cout << AttackMessage << '\n';

	Target->PrintName();
	cout << "받은 데미지: " << Damage << endl;

}


int ACharacter::TakeDamage(int DamageAmount)
{
	DamageAmount = DamageAmount - Stat.Def;
	DamageAmount = std::max(DamageAmount, 0);

	Stat.Hp -= DamageAmount;
	Stat.Hp = std::max(Stat.Hp, 0);
	return DamageAmount;
}

//bool HasEnoughMP(int Cost)
//{
//
//}

//void ConSumeMp(int Cost)
//{
//
//}

void ACharacter::PlayTurn(ACharacter* Target)
{

}

void ACharacter::ShowStat()
{
	cout << "[" << GetName() << "] HP: " << GetHp() << " / " << GetMaxHp() << " | MP: " << GetMp() << " / " << GetMaxMp() << endl;
}

void ACharacter::Heal(int HealAmount)
{
	Stat.Hp = std::min(Stat.Hp + HealAmount, Stat.MaxHp);
}