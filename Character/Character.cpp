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

void ACharacter::Attack(ACharacter* Target)
{
	int NewAttack = Stat.Atk;
	if (GetRandomInt() < Stat.Critical)
	{
		NewAttack = static_cast<int>(NewAttack * 1.5f);
		cout << Name << "의 공격이 급소에 맞았다! (공격력 : " << NewAttack << ")" << endl;
	}
	else
	{
		cout << Name << "이 공격합니다! (공격력 : " << NewAttack << ")" << endl;
	}

	Target->TakeDamage(NewAttack);
}

void ACharacter::TakeDamage(int DamageAmount)
{
	DamageAmount = DamageAmount - Stat.Def;
	//max() , 파라미터로 들어온 값중에 가장 큰 값을 반환.
	DamageAmount = std::max(DamageAmount, 0);
	
	Stat.Hp -= DamageAmount;
	cout << Name << "이 " << DamageAmount << "의 피해를 입었습니다." << endl;
	cout << "   ->" << Name << "의 남은 체력 : " << Stat.Hp << endl;
}
