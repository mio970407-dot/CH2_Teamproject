#pragma once
#include <iostream>
#include <string>

using namespace std;

struct FUnitStat
{
	int Hp;
	int Atk;
	int Def;
	int Critical;
};

struct FDamageResult
{
	int Damage;
	bool bCritical = false;

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
	virtual FDamageResult Attack(ACharacter* Target);
	int TakeDamage(int DamageAmount);
	string GetName() { return Name; }
	int GetHp() { return Stat.Hp; }
	bool IsDead() { return Stat.Hp <= 0; }
	
private:
	int GetRandomInt();
};
