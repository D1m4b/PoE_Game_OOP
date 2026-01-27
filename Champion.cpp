#include "Champion.h"
Champion::Champion() //конструктор по умолчанию, когда нет аргументов
{
    name = "чемпион";
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
    cout << name << " взял в руки " << weapons[lvl - 1] << endl;
}
void Champion::GetInfo()   //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "\tСила - " << strenght << endl;
    cout << "Доступное оружие - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << " ";
    }
    cout << endl;
}
void Champion::Create()
{
    cout << "Вы создали Чемпиона - Великого и Могучего воина " << endl;
    cout << "Придумайте имя для персонажа\t";
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
    cout << "\nЧемпион достиг " << lvl << "-го уровня!\n";
    
}
void Champion::UseAbility() {
    cout << name << " наносит мощный удар , используя " << weapons[lvl - 1] << endl;;
}
//деструктор - метод, который вызывается автоматически при высвобождении памяти
//при окончании работы с экземпляром класса (нельзя вызвать вручную)
Champion::~Champion() //деструктор всегда без аргументов
{
}