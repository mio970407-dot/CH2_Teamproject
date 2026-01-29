#pragma once
#include <string>
#include "Character.h"

using namespace std;

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);
	
protected:
	int Level;
	int Exp;

public:
	void Attack(ACharacter* Target) override;
	void UseItem();
	void LevelUp();
};

