#include "Character.h"
#include <random>

ACharacter::ACharacter(string NewName, const FUnitStat& NewStat)
{
    Name = NewName;
    Stat = NewStat;

    cout << "[생성] " << Name << "이 전장에 나타났습니다! (HP : " << Stat.Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "[소멸] " << Name << "이 전장에서 물러납니다." << endl;
}

int GetRandomInt()
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 99);

    return dis(gen);
}

void ACharacter::Attack(ACharacter*Target)
{
    int RandomValue = GetRandomInt();
    if (RandomValue < Stat.Critical)
    {
        cout << Name << "의 공격이 급소에 맞았다! (공격력 : " << Stat.Atk * 1.5 << ")" << endl;
        Target->TakeDamage(Stat.Atk * 1.5);
    }
    else
    {
        cout << Name << "이 공격합니다! (공격력 : " << Stat.Atk << ")" << endl;
        Target->TakeDamage(Stat.Atk);
    }
}

void ACharacter::TakeDamage(int DamageAmount)
{
   DamageAmount = DamageAmount - Stat.Def;
    if (DamageAmount < 0)
    {
        DamageAmount = 0;
    }
    Stat.Hp -= DamageAmount;
    cout << Name << "이 " << DamageAmount << "의 피해를 입었습니다." << endl;
    cout << "   ->"<< Name<<"의 남은 체력 : " << Stat.Hp << endl;
}
