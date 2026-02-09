#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"
#include <Windows.h>
#include <iostream>

void WaitForPlayerInput()
{
	system("pause");
	cout << endl;
}

int main()
{
	ACharacter* Player = new APlayer("작은 다윗", { 120,20,60,10,10 });
	ACharacter* Monster =new AMonster("거대한 골리앗",{ 300,20,30,10,10 });

	cout << "===  데스매치 시작!  ===" << endl;
	WaitForPlayerInput();

	while (!Player->IsDead() && !Monster->IsDead())
	{
		Player->PlayTurn(Monster);

		if (Monster->IsDead())
		{
			cout << endl << "적이 쓰러졌습니다! 승리!" << endl;
			break;
		}
		WaitForPlayerInput();

		Monster->PlayTurn(Player);

		if (Player->IsDead())
		{
			cout << endl << "플레이어가 쓰러졌습니다... 패배..." << endl;
			break;
		}
		WaitForPlayerInput();
	}

	delete Player;
	delete Monster;

	WaitForPlayerInput();

	return 0;
}
