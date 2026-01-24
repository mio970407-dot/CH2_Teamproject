#pragma once
#include <iostream>
#include <string> 

using namespace std;

class ACharacter
{
public:
    //추가 스탯은 어디에
    ACharacter(string NewName, int NewHp, int NewAtk);
    ~ACharacter();

protected:
    string Name;
    int Hp;
    int Atk;

public:
    //* 이후 띄어쓰기
    void Attack(ACharacter*Target);
    void TakeDamage(int DamageAmount);
    
    //간단한 게터는 헤더에 구현을 권장합니다. 
    int GetHp();
    bool IsDead();
};