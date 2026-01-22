#pragma once
#include "Champion.h"
#include "Occultist.h"
#include "Guardian.h"

Guardian::Guardian()
{
    name = "защитник ";
    health = 23;
    damage = 15;
}
Guardian::Guardian(string name, unsigned int health, float damage)
{
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Guardian::GetInfo()
{
    Npc::GetInfo();
    cout << "Интеллект - " << intellect << endl;
    cout << "Доступные ауры - ";
    for (int i = 0; i < lvl; i++) {
        cout << auras[i] << " ";
    }
    cout << endl;
}
void Guardian::CastAuras()
{
    cout << name << " применяет " << auras[lvl - 1] << endl;
}
void Guardian::Create() 
{
    cout << "Вы создали Защитника! - Универсального воина, который поможет как в защите, так и в нападении " << endl;
    cout << "Придумайте имя для персонажа\t";
    cin >> name;
    GetInfo();
    CastAuras();
}
Guardian::~Guardian()
{
    cout << name << " подох " << endl;
};
