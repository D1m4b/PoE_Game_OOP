#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Npc
{
protected:
    string name{ "персонаж" };
    unsigned short lvl{ 1 };
    unsigned int health{ 10 };
    unsigned int damage{ 5 };
public:    //публичный модификатор доступ (использовать метод можно в любом месте)
    string GetName();
    unsigned int GetHealth();
    float GetDamage();
    unsigned int GetLvl();
    virtual void GetInfo();
    virtual void Create() {};
};