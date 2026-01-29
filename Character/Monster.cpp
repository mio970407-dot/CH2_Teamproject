#include "Monster.h"

AMonster::AMonster(const string& NewName, const FUnitStat& NewStat)
	: ACharacter(NewName, NewStat)
{
}
void AMonster::Attack(ACharacter* Target)
{
    cout << Name << "이 상대를 얕잡아봅니다." << endl;

    ACharacter::Attack(Target);
}