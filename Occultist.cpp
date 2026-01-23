#include "Occultist.h"
Occultist::Occultist()
{
    name = "Окультистка";
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
    cout << "Интеллект - " << intellect << endl;
    cout << "Доступные проклятья - ";
    for (int i = 0; i < lvl; i++) {
        cout << curses[i] << " ";
    }
    cout << endl;
}

void Occultist:: GetWeapons() 
{
    cout << name << " берёт в руку книгу с проклятьем: " << curses[lvl - 1] << endl;
}

void Occultist::Create()
{
    cout << "Вы создали Окультистку! - её проклятья помогут победить любого врага " << endl;
    cout << "Придумайте имя для персонажа\t";
    cin >> name;
    GetInfo();
    GetWeapons();
}
void Occultist::LevelUp() {
    lvl++;
    health += 15;       
    damage += 45;   
    intellect += 20;
    cout << "\nОккультист достиг " << lvl << "-го уровня!\n";
}
void Occultist::UseAbility() {
    cout << name << " применяет " << curses[lvl - 1] << endl;
}
Occultist::~Occultist()
{
    cout << name << " сожгли на костре" << endl;
};