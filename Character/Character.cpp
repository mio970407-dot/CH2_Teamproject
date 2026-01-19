#include "Character.h"

ACharacter::ACharacter(string NewName, int NewHp, int NewAtk)
{
    Name = NewName;
    Hp = NewHp;
    Atk = NewAtk;

    cout << "[생성] " << Name << "이 전장에 나타났습니다! (HP : " << Hp << ")" << endl;
}

ACharacter::~ACharacter()
{
    cout << "[소멸] " << Name << "이 전장에서 물러납니다." << endl;
}


void ACharacter::Attack()
{
    cout << Name << "이 공격합니다! (공격력 : " << Atk << ")" << endl;
}

void ACharacter::TakeDamage(int DamageAmount)
{
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