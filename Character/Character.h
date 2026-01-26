#pragma once
#include <iostream>
#include <string> 

using namespace std;

struct FUnitStat
{
    int Hp;
    int Atk;
    int Def;
    float Critical;
};

class ACharacter
{
public:
    ACharacter(string NewName, const FUnitStat& NewStat);
    ~ACharacter();

protected:
    string Name;
    FUnitStat Stat;

public:
    void Attack(ACharacter* Target);
    void TakeDamage(int DamageAmount);
    
    int GetHp()
    {
        return Stat.Hp;
    }
    int GetAtk()
    {
        return Stat.Atk;
    }
    bool IsDead()
    {
        return Stat.Hp <= 0;
    }
};