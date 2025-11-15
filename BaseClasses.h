#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Npc 
{
protected:
    string name{ "персонаж" };
    unsigned short lvl{ 3 };
    unsigned int health{ 10 };
    float damage{ 5 };
public:    //публичный модификатор доступ (использовать метод можно в любом месте)
    string GetName();
    unsigned int GetHealth();
    float GetDamage();
    unsigned int GetLvl();
    virtual void GetInfo();

    virtual void Create() {};
    virtual bool Save();

    Npc Load();
};
class Player
{
public:
    void Create(Npc* player);
    void Save(Npc* player);
    void Load(Npc* player);
    };