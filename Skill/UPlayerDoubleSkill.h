#pragma once
#include "Skill.h"
class UPlayerDoubleSkill : public USkill
{
public:
	UPlayerDoubleSkill(ACharacter* NewOwner);
	void Play(ACharacter* Target) override;

};

