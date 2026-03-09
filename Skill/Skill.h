#pragma once

class ACharacter;
class USkill
{
protected:
	ACharacter* Owner;
	int MpCost;
public:
	USkill(ACharacter* NewOwner, int NewMpCost);
	virtual void Play(ACharacter* Target) = 0;
	int GetMpCost() { return MpCost; }

};