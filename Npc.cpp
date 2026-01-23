#include "Npc.h"
string Npc::GetName()
{
    return name;
}
unsigned int Npc::GetHealth()
{
    return health;
}
int Npc::GetDamage()
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
void Npc::TakeDamage(int damage)
{
    health -= damage;
    if (health < 0)
    {
        health = 0;
    }
}
void Npc::GetWeapons() {

}
void Npc::LevelUp() {
    lvl++;
    health = health + lvl * 5;
    damage = damage + lvl * 3;
}
void Npc::UseAbility()
{

}
void Npc::AddDamage(int bonus) {
    damage += bonus;
}