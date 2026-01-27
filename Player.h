#pragma once
#include <string>
#include "Character/Character.h"

using namespace std;

class Player : public ACharacter
{
protected:
	int Level;
	int Exp;

public:
	void UseItem();
	void LevelUp();
};

