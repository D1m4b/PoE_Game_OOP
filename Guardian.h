#pragma once
#include "Champion.h"
#include "Occultist.h"
class Guardian : public Champion, public Occultist
    //следующий родительственный класс добавл€етс€ через зап€тую
{
protected:
    string auras[3]{ "решимость","дисциплина","злорадство" };
public:
    Guardian();
    void GetInfo() override
    {
        Champion::GetInfo();
        cout << "»нтеллект - " << intellect << endl;
        cout << "ƒоступные ауры - ";
        for (int i = 0; i < lvl; i++)
        {
            cout << auras[i] << endl;
        }
    }
    void Create() override
    {
        cout << "¬ы создали защитника" << endl;
        cout << "¬ведите им€ персонажа\t";
        cin >> name;
        GetInfo();
        CastCurses();
        GetWeapons();
    }
    bool operator == (const Guardian& guardian) const
    {
        return ((guardian.damage == this->damage) && (guardian.health == this->health)
            && (guardian.intellect == this->intellect)) && (guardian.strenght == this->strenght);
    }
    void operator = (Npc npc)
    {
        this->name = npc.GetName();
        this->name = npc.GetHealth();
        this->name = npc.GetDamage();
        this->name = npc.GetLvl();
    }
    bool Save() override
    {


        if (Npc::Save())
        {
            ofstream saveSystem("save.bin", ios::binary);
            if (saveSystem.is_open())
            {

                saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
                for (int i = 0; i < 4; i++)
                {
                    saveSystem.write(reinterpret_cast<const char*>(&auras[i]), sizeof(auras[i]));
                }
                saveSystem.close();
                return true;
            }
            else
            {
                cout << "сохранение не удалось" << endl;
                return false;
            }
        }
    }
};