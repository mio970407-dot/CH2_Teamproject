#pragma once
#include <string>
#include "Character.h"

using namespace std;
class USkill;

class APlayer : public ACharacter
{
public:
	APlayer(const string& NewName, const FUnitStat& NewStat);
	~APlayer() override;
protected:
	int Level;
	int Exp;

public:
	FDamageResult Attack(ACharacter* Target) override;
	void UseSkill(ACharacter* Target) override;
	void UseItem();
	void LevelUp();
};

