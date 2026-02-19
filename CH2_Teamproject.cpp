#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"
#include "BattleManager.h"
#include <Windows.h>
#include <iostream>



int main()
{
	unique_ptr<ACharacter> Player = make_unique<APlayer>("작은 다윗", FUnitStat(120,20,60,10,10));
	unique_ptr<ACharacter> Monster = make_unique<AMonster>("거대한 골리앗", FUnitStat(300,20,30,10,10));
	auto Manager = make_unique<ABattleManager>();

	Manager->RunBattle(Player.get(), Monster.get());
	return 0;
}
