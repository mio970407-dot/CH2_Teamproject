#include "Character/Character.h"
#include <Windows.h>

int main()
{
    ACharacter* Player = new ACharacter("작은 다윗", {100, 60, 10, 10});
    ACharacter* Monster = new ACharacter("거대한 골리앗", {300, 10, 10, 10});

    cout << "===  데스매치 시작!  ===" << endl;
    Sleep(1000);

    while (!Player->IsDead() && !Monster->IsDead())
    {
        Player->Attack(Monster);

        if (Monster->IsDead())
        {
            cout << "적이 쓰러졌습니다! 승리!" << endl;
            break;
        }

        Sleep(500);

        Monster->Attack(Player);

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