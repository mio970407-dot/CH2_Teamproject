#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"
#include "BattleManager.h"
#include <Windows.h>
#include <iostream>



int main()
{
	ACharacter* Player = new APlayer("작은 다윗", { 120,20,60,10,10 });
	ACharacter* Monster =new AMonster("거대한 골리앗",{ 300,20,30,10,10 });

	ABattleManager* Manager = new ABattleManager();

	Manager->RunBattle(Player, Monster);

	delete Player;
	delete Monster;

	Manager->WaitForPlayerInput();
	delete Manager;
	return 0;
}
