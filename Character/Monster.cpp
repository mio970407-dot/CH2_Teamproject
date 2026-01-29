#include "Monster.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
}
void AMonster::Attack(ACharacter* Target)
{
    cout << Name << "이 여유롭게 공격합니다." << endl;
    Target->TakeDamage(Stat.Atk);
}