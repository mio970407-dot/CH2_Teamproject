#pragma once
#include <iostream>
#include <string> 

using namespace std;

class ACharacter
{
public:
    ACharacter(string NewName, int NewHp, int NewAtk, int NewDef, int NewCritical);
    ~ACharacter();

protected:
    string Name;
    int Hp;
    int Atk;
    int Def;
    int Critical;

public:
    //* 이후 띄어쓰기
    void Attack(ACharacter*Target);
    void TakeDamage(int DamageAmount);
    
    //간단한 게터는 헤더에 구현을 권장합니다. 
    int GetHp();
    bool IsDead();
};