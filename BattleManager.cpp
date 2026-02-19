#include "BattleManager.h"
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"

ABattleManager::ABattleManager()
{
	cout << endl << "===  데스매치 시작!  ===" << endl;
	WaitForPlayerInput();
}

void ABattleManager::WaitForPlayerInput()
{
	system("pause");
	cout << endl;
}

bool ABattleManager::BattleTurn(ACharacter* Attacker, ACharacter* Defender)
{
	Attacker->PlayTurn(Defender);
	cout << endl;
	Attacker->ShowStat();
	Defender->ShowStat();
	WaitForPlayerInput();

	if (Defender->IsDead())
	{
		cout << Defender->GetName() << "이 쓰러졌다!" << endl << endl;
	}
	return Defender->IsDead();
}

void ABattleManager::RunBattle(ACharacter* Player, ACharacter* Monster)
{
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
}

ABattleManager::~ABattleManager()
{
	WaitForPlayerInput();
}