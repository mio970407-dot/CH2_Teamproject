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

bool BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
	//공격>생존확인>죽으면 브레이크, 살면 다음턴으로
	//공격
	Attacker->PlayTurn(Defender);
	cout << endl;
	Attacker->ShowStat();
	Defender->ShowStat();
	WaitForPlayerInput();

	//생존여부:죽었다면
	if (Defender->IsDead())
	{
		cout << Defender->GetName() << "이 쓰러졌다!" << endl;
	}
	return Defender->IsDead();
}

class BattleManager
{


};

int main()
{
	ACharacter* Player = new APlayer("작은 다윗", { 120,20,60,10,10 });
	ACharacter* Monster =new AMonster("거대한 골리앗",{ 300,20,30,10,10 });

	BattleManager* Manager = new BattleManager();

	Manager->RunBattle();
	//
	cout << "===  데스매치 시작!  ===" << endl;
	WaitForPlayerInput();

	while (true)
	{
		if (BattleTurn(Player, Monster) == true)
		{
			break;
		}

		if (BattleTurn(Monster, Player) == true)
		{
			break;
		}
	}
	WaitForPlayerInput();
	//
	delete Player;
	delete Monster;

	Manager->WaitForPlayerInput();
	delete Manager;
	return 0;
}
