#pragma once
#include <iostream>
using namespace std;

class ACharacter;
class USkill
{
protected:
	ACharacter* Owner;
	int MpCost;
	string Name;
public:
	USkill(ACharacter* NewOwner, int NewMpCost, string NewName);
	virtual void Play(ACharacter* Target) = 0;
	int GetMpCost() { return MpCost; }
	string GetName() { return Name; }

};