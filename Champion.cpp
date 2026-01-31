#include "Champion.h"
Champion::Champion() //êîíñòðóêòîð ïî óìîë÷àíèþ, êîãäà íåò àðãóìåíòîâ
{
    name = "÷åìïèîí";
    health = 35;
    damage = 35;
}
Champion::Champion(string name, unsigned int health, float damage)
{
    this->name = name;
    this->health = health;
    this->damage = damage;
}
void Champion::GetWeapons()
{
    cout << name << " âçÿë â ðóêè " << weapons[lvl - 1] << endl;
}
void Champion::GetInfo()   //ïîëèìîðôèçì (ïåðåãðóçêà äëÿ ìåòîäà)
{
    Npc::GetInfo();
    cout << "\tÑèëà - " << strenght << endl;
    cout << "Äîñòóïíîå îðóæèå - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << " ";
    }
    cout << endl;
}
void Champion::Create()
{
    cout << "Âû ñîçäàëè ×åìïèîíà - Âåëèêîãî è Ìîãó÷åãî âîèíà " << endl;
    cout << "Ïðèäóìàéòå èìÿ äëÿ ïåðñîíàæà\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
bool Champion::operator == (const Champion& champion) const
{
    return ((champion.damage == this->damage) && (champion.health == this->health)
        && (champion.strenght == this->strenght));
}
void Champion::operator = (Npc npc)
{
    this->name = npc.GetName();
    this->name = npc.GetHealth();
    this->name = npc.GetDamage();
    this->name = npc.GetLvl();
}

void Champion::LevelUp() {
    lvl++;
    health += 25;      
    damage += 30;
    strenght += 10;
    cout << "\n×åìïèîí äîñòèã " << lvl << "-ãî óðîâíÿ!\n";
    
}
void Champion::UseAbility() {
    cout << name << " íàíîñèò ìîùíûé óäàð , èñïîëüçóÿ " << weapons[lvl - 1] << endl;;
}
//äåñòðóêòîð - ìåòîä, êîòîðûé âûçûâàåòñÿ àâòîìàòè÷åñêè ïðè âûñâîáîæäåíèè ïàìÿòè
//ïðè îêîí÷àíèè ðàáîòû ñ ýêçåìïëÿðîì êëàññà (íåëüçÿ âûçâàòü âðó÷íóþ)
