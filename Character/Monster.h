#pragma once

#include "Character.h"

using namespace std;

class AMonster : public ACharacter
{
public:
	AMonster(const string& NewName, const FUnitStat& NewStat);
	FDamageResult Attack(ACharacter* Target) override;
};
