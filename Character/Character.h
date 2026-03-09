#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../Skill/Skill.h"

using namespace std;

struct FUnitStat
{
	int MaxHp;
	int MaxMp;

	int Atk;
	int Def;
	int Critical;

	int Hp = 0;
	int Mp = 0;

	FUnitStat()
	{

	}

	FUnitStat(int MaxHp, int MaxMp, int Atk, int Def, int Critical)
	{
		this->MaxHp = MaxHp;
		this->MaxMp = MaxMp;
		
		this->Atk = Atk;
		this->Def = Def;
		this->Critical = Critical;
	}
};


struct FDamageResult
{
	int Damage;
	bool bCritical = false;

	ACharacter* Attacker;
	ACharacter* Target;

	void PrintMessage(const string& AttackMessage);

};


class ACharacter
{
public:
	ACharacter(const string& NewName, const FUnitStat& NewStat);
    virtual ~ACharacter();

protected:
	string Name;
	FUnitStat Stat;
	vector<unique_ptr<USkill>> Skills;

public:
	void PrintMessage(ACharacter* Target);
	int TakeDamage(int DamageAmount);
	void PrintName() { cout << "[" << Name << "]"; }
	string GetName() { return Name; }
	int GetHp() { return Stat.Hp; }
	int GetMaxHp() const { return Stat.MaxHp; }
	int GetMp() { return Stat.Mp; }
	int GetMaxMp() { return Stat.MaxMp; }
	int GetAtk() { return Stat.Atk; }
	int GetCritical() { return Stat.Critical; }
	bool IsDead() const { return Stat.Hp <= 0; }
	//bool HasEnoughMp(int Cost);
	//void ConsumeMp(int Cost);

	virtual void PlayTurn(ACharacter* Target);
	void ShowStat();
	int GetRandomInt(int Max = 100);
	void Heal(int HealAmount);
};
