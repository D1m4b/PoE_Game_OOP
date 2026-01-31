#pragma once
#include "Npc.h"
class Champion : virtual public Npc {
protected:
    unsigned short strenght{ 31 };
    string weapons[3]{ "êèíæàë","êîãîòü","äâóðó÷íîå îðóæèå" };
public:
    Champion();
    Champion(string name, unsigned int health, float damage); //êàñòîìíûé êîíñòðóêòîð

    void GetWeapons();
    void GetInfo() override;  //ïîëèìîðôèçì (ïåðåãðóçêà äëÿ ìåòîäà)
    void Create() override;
    //ïåðåãðóçêà îïåðàòîðà ñðàâíåíèÿ (==)
    bool operator == (const Champion& champion) const;
    void operator = (Npc npc);
    void LevelUp() override;
    void UseAbility() override;
};
