#include "Champion.h"
bool Champion::Save()
{
    if (Npc::Save())
    {
        ofstream saveSystem("save.bin", ios::binary);
        if (saveSystem.is_open())
        {
            saveSystem.write(reinterpret_cast<const char*>(&strenght), sizeof(strenght));
            for (int i = 0; i < 3; i++)
            {
                saveSystem.write(reinterpret_cast<const char*>(&weapons[i]), sizeof(weapons[i]));
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
Champion Champion::Load()
{
    ifstream loadSystem("save.bin", ios::binary);
    Champion champion; //временное хранилище для считывания данных из файла
    champion = Npc::Load();
    if (loadSystem.is_open())
    {
        loadSystem.read(reinterpret_cast<char*>(&strenght), sizeof(strenght));
        for (int i = 0; i < 4; i++)
        {
            loadSystem.read(reinterpret_cast<char*>(&weapons[i]), sizeof(weapons[i]));
        }
    }
    else
    {
        cout << "связь с базой нарушена\nПамять утерена" << endl;
        return champion;
    }
    loadSystem.close();
    return champion;
};
Champion::Champion() //конструктор по умолчанию, когда нет аргументов
{
    name = "чемпион";
    health = 35;
    damage = 10;
}
Champion::Champion(string name, unsigned int health, float damage)
{
    cout << "кастомный конструктор чемпиона" << endl;
    this->name = name;
    this->health = health;
    this->damage = damage;
}
void Champion::GetWeapons()
{
    cout << name << " взял в руки " << weapons[lvl - 1];
}
void Champion::GetInfo()   //полиморфизм (перегрузка для метода)
{
    Npc::GetInfo();
    cout << "Сила - " << strenght << endl;
    cout << "Доступное оружие - ";
    for (int i = 0; i < lvl; i++)
    {
        cout << weapons[i] << endl;
    }
}
void Champion::Create()
{
    cout << "Вы создали война" << endl;
    cout << "Введите имя персонажа\t";
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

//деструктор - метод, который вызывается автоматически при высвобождении памяти
//при окончании работы с экземпляром класса (нельзя вызвать вручную)
Champion::~Champion() //деструктор всегда без аргументов
{
    cout << name << " пал смертью храбрых" << endl;
}