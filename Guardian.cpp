#pragma once
#include "Champion.h"
#include "Occultist.h"
#include "Guardian.h"

Guardian::Guardian()
{
    name = "çàùèòíèê ";
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
    cout << "\tÈíòåëëåêò - " << intellect << endl;
    cout << "Äîñòóïíûå àóðû - ";
    for (int i = 0; i < lvl; i++) {
        cout << auras[i] << " ";
    }
    cout << endl;
}
void Guardian::GetWeapons()
{
    cout << name << " èçó÷àåò òåõíèêó íîâîé àóðû - " << auras[lvl - 1] << endl;
}
void Guardian::Create() 
{
    cout << "Âû ñîçäàëè Çàùèòíèêà! - Óíèâåðñàëüíîãî âîèíà, êîòîðûé ïîìîæåò êàê â çàùèòå, òàê è â íàïàäåíèè " << endl;
    cout << "Ïðèäóìàéòå èìÿ äëÿ ïåðñîíàæà\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
void Guardian::LevelUp() {
    lvl++;
    health += 60;      
    damage += 25;    
    cout << "\nÇàùèòíèê äîñòèã " << lvl << "-ãî óðîâíÿ!\n";
}
void Guardian::UseAbility() {
    cout << name << " ïðèìåíÿåò " << auras[lvl - 1] << endl;
}

