#pragma once

#include "Character.h"

using namespace std;
class USkill;

class AMonster : public ACharacter
{
public:
	AMonster(const string& NewName, const FUnitStat& NewStat);
	~AMonster() override;
	FDamageResult Attack(ACharacter* Target) override;
	void UseSkill(ACharacter* Target) override;
};
