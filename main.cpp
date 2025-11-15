#include <iostream>
#include "windows.h"
#include "BaseClasses.h"
#include "Champion.h"
#include "Occultist.h"
#include "Guardian.h"
using namespace std;

enum class ValueQuality
{
    trash, common, rare, mythic, legendary
};
enum class characterTyper
{
    champion, occultist, guardian
};
enum class mainMenu
{
    newGame, loadGame, settings, quit
};
enum class weaponsType
{
    dagger, magicWand, magicSword, morgenshtern, hammer
};
enum class spellsType
{
    quickSpell, hardSpell, areaSpell, shieldSpell, ultimateSpell
};

enum class CharacterType
{
    UNKNOWN = 0,
    CHAMPION,
    OCCULTIST,
    GUARDIAN
};

unsigned short TestChoise(unsigned short maxChoise, string text)
{
    unsigned short choise = 1;
    cin >> choise;
    while (choise > maxChoise || choise < 1)
    {
        cout << text << endl;
        cin >> choise;
    }
    return choise;
};

unique_ptr<Npc> CreateCharacter(CharacterType type)
{
    switch (type)
    {
    case CharacterType::UNKNOWN:
        return make_unique<Npc>();
        break;
    case CharacterType::CHAMPION:
        return make_unique<Champion>();
        break;
    case CharacterType::OCCULTIST:
        return make_unique<Occultist>();
        break;
    case CharacterType::GUARDIAN:
        return make_unique<Guardian>();
        break;
    default:
        throw
            invalid_argument("Неизвестный тип персонажа");
        break;
    }
}

struct Treasure
{
    Treasure() = default;
    string name{ "добыча" };
    ValueQuality quality = ValueQuality::trash;
    unsigned int price{ 0 };
    Treasure(ValueQuality quality)
    {
        switch (quality)
        {
        case ValueQuality::trash:
            cout << "Качество плохое\n";
            break;
        case ValueQuality::common:
            cout << "Качество средненькое\n";
            break;
        case ValueQuality::rare:
            cout << "Качество хорошее\n";
            break;
        case ValueQuality::mythic:
            cout << "Качество крутое\n";
            break;
        case ValueQuality::legendary:
            cout << "Качество идеальное\n";
            break;
        default:
            break;
        }
    }
};
struct Cloth : Treasure
{
    Cloth(ValueQuality quality) : Treasure(quality) {};
    string valueSite[5]{ "ботинки","поножи","нагрудник","шлем","пояс" };
    string site{ NULL };
    unsigned int armor{ 1 };
};
struct Weapon
{
    Weapon() = default;
    string name{ "Оружие" };
    weaponsType weapon = weaponsType::dagger;
    ValueQuality quality = ValueQuality::trash;
    unsigned short damage{ 1 };
};
struct Spell
{
    Spell() = default;
    string name{ "Заклинание" };
    spellsType weapon = spellsType::quickSpell;
    unsigned short damage{ 1 };
    unsigned short manaCost{ 1 };
};


int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Player* player = new Player();
    cout << "Привет путник\nПрисядь у костра и расскажи о себе\nТы впервые тут?\n\t1 - новый персонаж\n\t2 - загрузить";

    unsigned short mainChoice = TestChoise(2, "Наверное ты ошибся, повтори снова");
    if (mainChoice == 1)  // ЯВНО сравниваем с 1
    {
        cout << "Расскажи о своих навыках \n\t1 - Чемпион\n\t2 - Оккультист\n\t3 - Защитник";
        unique_ptr<Npc> character;

        unsigned short classChoice = TestChoise(3, "Такого еще не было в наших краях\nНе мог бы ты повторить"); // ФИКС: 3 вместо 4
        switch (classChoice)
        {
        case 1:
            character = CreateCharacter(CharacterType::CHAMPION);
            break;
        case 2:
            character = CreateCharacter(CharacterType::OCCULTIST);
            break;
        case 3:
            character = CreateCharacter(CharacterType::GUARDIAN);
            break;
        }

        if (character) {
            // ФИКС: используем .release() вместо move
            player->Create(character.release());
            cout << "Персонаж создан успешно!" << endl;
        }
    }

    delete player;
    return 0;
}