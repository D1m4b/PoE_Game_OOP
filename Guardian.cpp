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
    cout << "\tИнтеллект - " << intellect << endl;
    cout << "Доступные ауры - ";
    for (int i = 0; i < lvl; i++) {
        cout << auras[i] << " ";
    }
    cout << endl;
}
void Guardian::GetWeapons()
{
    cout << name << " изучает технику новой ауры - " << auras[lvl - 1] << endl;
}
void Guardian::Create() 
{
    cout << "Вы создали Защитника! - Универсального воина, который поможет как в защите, так и в нападении " << endl;
    cout << "Придумайте имя для персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
void Guardian::LevelUp() {
    lvl++;
    health += 60;      
    damage += 25;    
    cout << "\nЗащитник достиг " << lvl << "-го уровня!\n";
}
void Guardian::UseAbility() {
    cout << name << " применяет " << auras[lvl - 1] << endl;
}
Guardian::~Guardian()
{
};
