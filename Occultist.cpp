#include "Occultist.h"
Occultist::Occultist()
{
    name = "Îêóëüòèñòêà";
    health = 23;
    damage = 15;
}

Occultist::Occultist(string name, unsigned int health, float damage)
{
    this->name = name;
    this->health = health;
    this->damage = damage;
}

void Occultist::GetInfo() 
{
    Npc::GetInfo();
    cout << "\tÈíòåëëåêò - " << intellect << endl;
    cout << "Äîñòóïíûå ïðîêëÿòüÿ - ";
    for (int i = 0; i < lvl; i++) {
        cout << curses[i] << " ";
    }
    cout << endl;
}

void Occultist:: GetWeapons() 
{
    cout << name << " áåð¸ò â ðóêó êíèãó ñ ïðîêëÿòüåì: " << curses[lvl - 1] << endl;
}

void Occultist::Create()
{
    cout << "Âû ñîçäàëè Îêóëüòèñòêó! - å¸ ïðîêëÿòüÿ ïîìîãóò ïîáåäèòü ëþáîãî âðàãà " << endl;
    cout << "Ïðèäóìàéòå èìÿ äëÿ ïåðñîíàæà\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
void Occultist::LevelUp() {
    lvl++;
    health += 15;       
    damage += 45;   
    intellect += 20;
    cout << "\nÎêêóëüòèñò äîñòèã " << lvl << "-ãî óðîâíÿ!\n";
}
void Occultist::UseAbility() {
    cout << name << " ïðèìåíÿåò " << curses[lvl - 1] << endl;
}
