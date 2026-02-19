#pragma once
#include "Character/Character.h"
#include "Character/Monster.h"
#include "Character/Player.h"
#include <iostream>
#include <string>

using namespace std;

class ABattleManager
{
public:
	ABattleManager();
	void WaitForPlayerInput();
	bool BattleTurn(ACharacter* Attacker, ACharacter* Defender);
	void RunBattle(ACharacter* Player, ACharacter* Monster);
	~ABattleManager();
};

