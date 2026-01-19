#pragma once
#include <iostream>
#include <string> 

using namespace std;

class ACharacter
{
public:
    ACharacter(string NewName, int NewHp, int NewAtk);
    ~ACharacter();

protected:
    string Name;
    int Hp;
    int Atk;

public:
    void Attack(ACharacter*Target);
    void TakeDamage(int DamageAmount);
    int GetHp();
    bool IsDead();
};