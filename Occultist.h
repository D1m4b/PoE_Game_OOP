#pragma once
#include "Npc.h"
class Occultist : virtual public Npc {
protected:
    unsigned short intellect = 27;
    string curses[4] = { "èñòîùåíèå","ãîðþ÷åñòü","ïóòû âðåìåíè","êðîâîòå÷åíèå", };
public:
    Occultist();
    Occultist(string name, unsigned int health, float damage);
    Occultist operator + (const Occultist& occultist) const
    {
        return Occultist(
            this->name,
            (this->health + occultist.health),
            (this->damage + occultist.damage)
        );
    }
    void GetInfo() override;
    void Create() override;
    void GetWeapons() override;
    void LevelUp() override;
    void UseAbility() override;

};
