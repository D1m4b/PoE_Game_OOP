#include "Npc.h"
string Npc::GetName()
{
    return name;
}
unsigned int Npc::GetHealth()
{
    return health;
}
float Npc::GetDamage()
{
    return damage;
}
unsigned int Npc::GetLvl()
{
    return lvl;
}
void Npc::GetInfo() //метод класса
{
    cout << "\tИмя - " << name << endl;
    cout << "\tЗдоровье - " << health << endl;
    cout << "\tУрон - " << damage << endl;
    cout << "\tУровень - " << lvl << endl;
}
