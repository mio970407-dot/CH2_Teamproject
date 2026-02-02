#pragma once
#include <iostream>
#include <string>

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
class ACharacter;
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
    ~ACharacter();

protected:
	string Name;
	FUnitStat Stat;

public:
	void PrintMessage(ACharacter* Target);
	virtual FDamageResult Attack(ACharacter* Target);
	int TakeDamage(int DamageAmount);
	void PrintName() { cout << "[" << Name << "]"; }
	string GetName() { return Name; }
	int GetHp() { return Stat.Hp; }
	int GetMaxHp() const { return Stat.MaxHp; }
	bool IsDead() { return Stat.Hp <= 0; }
	virtual void UseSkill(ACharacter* Target) = 0;
private:
	int GetRandomInt();
};
