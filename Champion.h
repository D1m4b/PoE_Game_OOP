#pragma once
#include "Npc.h"
class Champion : virtual public Npc {
protected:
    unsigned short strenght{ 31 };
    string weapons[3]{ "кинжал","рапира","двуручный меч" };
public:
    Champion();
    Champion(string name, unsigned int health, float damage); //кастомный конструктор

    void GetWeapons();
    void GetInfo() override;  //полиморфизм (перегрузка для метода)
    void Create() override;
    //перегрузка оператора сравнения (==)
    bool operator == (const Champion& champion) const;
    void operator = (Npc npc);

    ~Champion(); //деструктор всегда без аргументов
};