#pragma once
#include <iostream>
#include <string> 

using namespace std;

class ACharacter
{
public:
    ACharacter();
    ~ACharacter();

protected:
    string Name;
    int Hp;
    int Atk;

public:
    void Attack();
    void TakeDamage(int DamageAmount);

};