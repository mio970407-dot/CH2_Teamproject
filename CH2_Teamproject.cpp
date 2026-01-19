#include "Character/Character.h"
#include <Windows.h>

int main()
{
    ACharacter* Player = new ACharacter("작은 다윗", 200, 60);
    ACharacter* Monster = new ACharacter("거대한 골리앗", 300, 10);

    cout << "===  데스매치 시작!  ===" << endl;
    Sleep(1000);

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->Attack();
        Monster->TakeDamage(60);

        if (Monster->IsDead())
        {
            cout << "몬스터가 쓰러졌습니다! 승리!" << endl;
            break;
        }

        Sleep(500);

        Monster->Attack();
        Player->TakeDamage(10);

        if (Player->IsDead())
        {
            cout << "플레이어가 쓰러졌습니다... 패배..." << endl;
            break;
        }

        Sleep(1000);
    }

    delete Player;
    delete Monster;
    return 0;
}
//int main()
//{
//    ACharacter* MyChar = new ACharacter();
//
//    MyChar->Attack();
//
//    MyChar->TakeDamage(30);
//
//    delete MyChar;
//
//    return 0;
//}