#include "Character.h"
#include <random>

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, int NewCritical)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;
    Def = NewDef;
    Critical = NewCritical;

    cout << "[생성] " << Name << "이 전장에 나타났습니다! (HP : " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "[소멸] " << Name << "이 전장에서 물러납니다." << endl;
}

int GetRandomInt()
{
    // 시드값 생성기 (한 번만 초기화하기 위해 static 사용)
    static std::random_device rd;

    // 메르센 트위스터 엔진 (고품질 난수 생성기)
    static std::mt19937 gen(rd());

    // 0부터 100까지 균등하게 분포 (양 끝값 포함)
    std::uniform_int_distribution<int> dis(0, 99);

    return dis(gen);
}

void ACharacter::Attack(ACharacter*Target)
{
    int RandomValue = GetRandomInt();
    if (RandomValue < Critical)
    {
        cout << Name << "의 공격이 급소에 맞았다! (공격력 : " << Atk * 1.5 << ")" << endl;
        Target->TakeDamage(Atk * 1.5);
    }
    else
    {
        cout << Name << "이 공격합니다! (공격력 : " << Atk << ")" << endl;
        Target->TakeDamage(Atk);
    }
}

void ACharacter::TakeDamage(int DamageAmount)
{
   DamageAmount = DamageAmount - Def;
    if (DamageAmount < 0)
    {
        DamageAmount = 0;
    }
    Hp -= DamageAmount;
    cout << Name << "이 " << DamageAmount << "의 피해를 입었습니다." << endl;
    cout << "   -> 남은 체력: " << Hp << endl;
}

int ACharacter::GetHp()
{
    return Hp;
}

bool ACharacter::IsDead()
{
    if (Hp <= 0)
    {
        return true;
    }
    else {
        return false;
    }
}