#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "windows.h"

#include "Npc.h"
#include "Champion.h"
#include "Occultist.h"
#include "Guardian.h"
#include "Evil.h"
#include "Player.h"
#include "Enemy.h"
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

void ClearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Pause(bool needText)
{
    if (needText)
        cout << "Enter чтобы продолжить...";
    cin.get();
    cout << endl;
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
    cout << "Здравствуй изгнанник! Добро пожаловать в мир Path of Exile! \n\t1 - создать нового персонажа \n\t2 - выйти из игры" << endl;
    unsigned short mainChoice = TestChoise(2, "Наверное ты ошибся, повтори снова");
    if (mainChoice == 2) {
        exit(0);
    }
    if (mainChoice == 1)  
    {
        cout << "Выберите класс, чтобы начать игру:   \n\t1 - Чемпион\n\t2 - Оккультист\n\t3 - Защитник" << endl;
        unique_ptr<Npc> character;

        unsigned short classChoice = TestChoise(3, "Такого еще не было в наших краях\nНе мог бы ты повторить"); 
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
            player->Create(move(character));
            cout << "Персонаж создан успешно!" << endl;
        }
    }

    Pause(false);
    Pause(true);
    ClearScreen();

    cout << "Последнее, что я видел — глаза Китавы, полные желанием меня растерзать. А потом — холод... песок в глазах.\n Я лежал на берегу, где океан плачет чёрными волнами, а небо — цвета запекшейся крови." << endl;
    cout << "Я решил,что нужно отомстить Китаве и готов был рискнуть всем, чтобы одолеть его." << endl;
    cout << "Не успел я прийти в себя - как на меня напали жители этого берега - мерзкие утопленники " << endl;
    Enemy* enemy = new Enemy("утопленник", 10, 3);

    return 0;
}