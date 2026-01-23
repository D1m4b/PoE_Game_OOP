#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Npc
{
protected:
    string name{ "персонаж" };
    unsigned short lvl{ 1 };
    int health{ 10 };
    int damage{ 5 };
public:    //публичный модификатор доступ (использовать метод можно в любом месте)
    string GetName();
    unsigned int GetHealth();
    int GetDamage();
    unsigned int GetLvl();
    virtual void GetInfo();
    virtual void GetWeapons();
    virtual void Create() {};
    virtual void TakeDamage(int damage);
    virtual int CalculateDamage() { return 0; };
    virtual void LevelUp();
    virtual void UseAbility();
    void AddDamage(int bonus);
    virtual ~Npc() = default;
};