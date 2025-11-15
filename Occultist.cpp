#include "Occultist.h"

bool Occultist::Save()
{
    if (Npc::Save())
    {
        ofstream saveSystem("save.bin", ios::binary);
        if (saveSystem.is_open())
        {
            saveSystem.write(reinterpret_cast<const char*>(&intellect), sizeof(intellect));
            for (int i = 0; i < 3; i++)
            {
                saveSystem.write(reinterpret_cast<const char*>(&curses[i]), sizeof(curses[i]));
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
};
Occultist::Occultist()
{
    cout << "конструктор Окультиста" << endl;
    name = "Окультисткаа";
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

void Occultist::CastCurses() 
{
    cout << name << " применяет " << curses[lvl - 1] << endl;
}

void Occultist::Create()
{
    cout << "Вы создали Окультистку!" << endl;
    cout << "Введите имя персонажа\t";
    cin >> name;
    GetInfo();
    CastCurses();
}
Occultist::~Occultist()
{
    cout << name << " сожгли на костре" << endl;
};