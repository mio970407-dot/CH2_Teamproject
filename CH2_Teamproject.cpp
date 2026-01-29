#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"
#include <Windows.h>

// Monster는 상속받고, 멤버 변수나 함수 추가 없이 구현
// Player는 상속받고 나서,
// 멤버 변수: Level, Exp
// 멤버 함수: UseItem(), LevelUp() 함수 제작, 빈 함수... 구현없음. 

int main()
{
	ACharacter* Player = new APlayer("작은 다윗", { 100,60,10,10 });
	
	ACharacter* Monster =new AMonster("거대한 골리앗",{ 300,10,10,10 });

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
