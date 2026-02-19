#pragma once

class ACharacter;
class USkill
{
protected:
	ACharacter* Owner;
public:
	USkill(ACharacter* NewOwner);
	virtual void Play(ACharacter* Target) = 0;
};

