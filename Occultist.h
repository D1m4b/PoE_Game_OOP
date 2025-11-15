#pragma once
#include "BaseClasses.h"
class Occultist : virtual public Npc {
protected:
    unsigned short intellect = 27;
    string curses[4] = { "истощение","горючесть","путы времени","кровотечение", };
public:
    bool Save() override;
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
    void GetInfo();
    void Create();
    void CastCurses();
    ~Occultist();
};