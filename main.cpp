#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>

#include "windows.h"

#include "Npc.h"
#include "Champion.h"
#include "Occultist.h"
#include "Guardian.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

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
double defaultCharsPerSecond = 30;

void PrintSlowly(const string& text, bool needPause)
{
    if (defaultCharsPerSecond <= 0) {
        cout << text;
        if (needPause) Pause(false);
        return;
    }

    auto delay = chrono::duration<double>(1.0 / defaultCharsPerSecond);

    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(delay);
    }

    if (needPause) {
        Pause(false);
    }
}

int AttackEnemy(Player* player, Enemy* enemy)
{
    int damage = player->GetCharacter()->GetDamage();
    enemy->TakeDamage(damage);
    player->GetCharacter()->UseAbility();
    PrintSlowly("Вы нанесли противнику ", false);
    PrintSlowly(to_string(damage), false);
    PrintSlowly(" урона.\n", false);

    enemy->GetInfo();

    Pause(false);

    return damage;
}

int EnemyAttack(Player* player, Enemy* enemy)
{
    int damage = enemy->GetDamage();

    PrintSlowly("Враг атакует! Оставшееся здоровье: ", false);
    player->GetCharacter()->TakeDamage(damage);
    PrintSlowly(to_string(player->GetCharacter()->GetHealth()), false);

    Pause(false);

    return damage;
}

void Fight(Player* player, Enemy* enemy)
{
    enemy->GetInfo();
    while (true)
    {
        AttackEnemy(player, enemy);
        if (enemy->GetHealth() <= 0) {
            PrintSlowly("Вы одолели врага!", false);
            break;
        }
        EnemyAttack(player, enemy);
        if (player->GetCharacter()->GetHealth() <= 0) {
            PrintSlowly("ВЫ ПОГИБЛИ!", false);
            PrintSlowly("Вы проиграли... Попробуйте начать заново, для этого перезапустите программу",false);
            exit(0);
        }
    }
}


/*enum class ValueQuality
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
*/

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
    string name = player->GetCharacter()->GetName();
    Pause(false);
    Pause(true);
    ClearScreen();

    PrintSlowly("\tГлава 1",false);
    PrintSlowly("\nЯ лежал на берегу, где океан плачет чёрными волнами, а небо — цвета запекшейся крови.\n""Последнее что я помню - глаза Китавы передо мной.\nНе успел я прийти в себя - как на меня напали жители этого берега - мерзкие утопленники ",false);
    cout << endl;
    Enemy* enemy = new Enemy("утопленник", 20, 3);
    cout << "НАЖИМАЙТЕ ENTER ЧТОБЫ НАНЕСТИ УРОН";
    Fight(player, enemy);
    Pause(false);
    Pause(true);
    ClearScreen();

    PrintSlowly("Убивая каждого утопленника, я чувствовал как каждая их душа вселялась в меня и делала меня намного сильнее", false);
    player->GetCharacter()->LevelUp();
    player->GetCharacter()->GetInfo();
    player->GetCharacter()->GetWeapons();
    PrintSlowly("\n Вдалеке я увидел старый разрушенный город и огромные величественные ворота! за которыми... в стальных оковах ... жил защитник этого разрушенного города - Китава", false);
    PrintSlowly("\n подходя к городу я встретил на своем пути место, где жили огромные страшные птицы - Роа. Они расположились около небольшой пещеры. Едва ли я их заметил... Как эти огромные птицы - как таран побежали в мою сторону... ", false);
    Enemy* enemyBird = new Enemy("птица Роа", 50, 12);
    Fight(player, enemyBird);
    PrintSlowly("\n После того как я легко расправился с птицами... Я увидел как в пещере что-то очень ярко светится ... Передо мной встал выбор", false);
    PrintSlowly("\n\t 1 - посетить пещеру \n\t 2 - отправиться в разрушенный город", false);
    unsigned short choice = TestChoise(2, "Выберите что-то одно");

    if (choice == 1) {
        PrintSlowly("\n" + name +" обнаружил старинный верстак, на котором можно улучшить своё оружие", false);
        player->GetCharacter()->AddDamage(15);
        PrintSlowly("\n" + name + " наносит зачарование на своё оружие и теперь оно отнимает у врага 15 хп при каждой атаке", false);
    }
    else if (choice == 2) {
        PrintSlowly(name+" решил что это слишком опасно и продолжил свой путь в разрушенный город\n", false);
        
    }
    cout << endl;
    Pause(false);
    Pause(true);
    ClearScreen();

    PrintSlowly("\tГлава 2", false);
    PrintSlowly("\n По пути к Воротам в Ад, я убивал разных бесов и страшных созданий ... И вот наконец-то я добрался до них... \n Ворота - за которыми живёт огромный и страшный Китава - защитник разрушенного города",false);
    PrintSlowly("\n До ворот оставались считанные метры... Но раздался страшный рёв ... Прилетел ОГРОМНЫЙ КРЫЛАТЫЙ ДВУХГОЛОВЫЙ БЕС \n У него в руках была огромная булава , которую он нетерпеливо раскручивал, чтобы нанести по мне удар", false);
    cout << "\n\t 1 - нанести удар первым \n\t 2 - попробовать поговорить с бесом" << endl;
    unsigned short choiceBes = TestChoise(2, "Выберите 1 или 2.");
    if (choiceBes == 1) {
        PrintSlowly(name + "решает сразиться с врагом и нападает первым", false);
        Enemy* enemyBes = new Enemy("ДВУХГЛАВЫЙ БЕС", 125, 25);
        cout << "\n Бес кидает булаву в " + name + " но он уворачивается" << endl;
        Fight(player, enemyBes);
        cout << "\n Бес пал ... Ворота открыты ... Самое время разобраться с врагом, который заставил меня вернуться сюда обратно" << endl;
    }
    else if (choiceBes == 2) {
        PrintSlowly("[" + name + "] : Здравствуй Бес! Как мне попасть к Китаве? У меня есть к нему важный разговор", false);
        PrintSlowly("\n[БЕС] : Здравствуй, Изгнанник! Для тебя ворота закрыты навсегда! ... Ты попытался сразиться с САМИМ ЗАЩИТНИКОМ разрушенного города, обратной дороги для тебя не существует ... Ты навсегда останешься в аду ...", false);
        PrintSlowly("\n Бес начинает ехидно смеяться и впадает в ярость ... Я ЗАБЕРУ ТВОЮ ДУШУ!! ... ", false);
        Enemy* enemyRageBes = new Enemy("РАЗЪЯРЕННЫЙ ДВУХГЛАВЫЙ БЕС", 100, 39);
        Fight(player, enemyRageBes);
        PrintSlowly("Эта была битва не на жизнь, а на смерть! ... Бес ранил меня ... и отнял очень много сил у меня ...", false);
    }
    PrintSlowly("После гибели этого страшного демона, его сердце засияло ярким красным цветом, и начало покидать тело злого беса", false);
    PrintSlowly("\n Я решил подойти поближе, оно тянуло меня как магнит, у меня было дикое желание взять его в руки", false);
    PrintSlowly("\n\t 1 - " + name + " берет сердце в руки\n\t 2 - " + name + " заходит в ворота Китавы ", false);
    unsigned short choiceHeart = TestChoise(2, "Выберите 1 или 2.");
    if (choiceHeart == 1) {
        PrintSlowly("\n Я взял сердце в руки ... Оно присосалось к моим рукам... затем превратилось в жидкость и наполнило моё тело неимоверной силой и энергией", false);
        player->GetCharacter()->LevelUp();
        player->GetCharacter()->GetInfo();
        PrintSlowly("Из под черного плаща беса, лежала небольшая книжка и двуручная тяжеленная булава", false);
        player->GetCharacter()->GetWeapons();
        Pause(false);
        Pause(true);
        ClearScreen();

        PrintSlowly("\nЯ открыл тяжелые скрипучие ворота - ворота в ад\n Передо мной стоял в оковах, во много раз больше меня, Китава\nКитава начал яростно рычать, в его устах начало появляться яркое пламя ... Он повернул голову на меня...", false);
        PrintSlowly("\nЯ заметил что в его руках, привязанные к оковам , лежат два сердца , похожих на сердце беса\n В левой руке сердце пульсировало чёрным, а в правой красным", false);
        PrintSlowly("\n Пока я думал, что это значит, и какое сердце разрушить, Китава яростно сделал плевок ярким пламенем, которого мгновенно добиралось до моих ног ...", false);
        PrintSlowly("\n\t 1 - уклониться влево\n\t 2 - уклониться вправо", false);
        unsigned short choiceKitava = TestChoise(2, "Выберите 1 или 2.");
        if (choiceKitava == 1) {
            PrintSlowly("Я увернулся от ядовитого пламени, и забрался на руку Китавы\n Не раздумывая я разбил его ...  \n Из сердца начали доноситься рёв, пугающие звуки ... \n Из сердца стали вылетать Чёрные Демоны Смерти ... Их было настолько много, что весь мир начал превращаться в сплошную чёрную материю\n", false);
            PrintSlowly("Я проснулся ... Очень сильно болела голова ... Я оказался в том же самом месте, где после первого боя с Китавой... Я смирился ... Я не мог так больше жить и покончил жизнь самоубийством", false);
        }
        else if (choiceKitava == 2) {
            PrintSlowly("Я увернулся от ядовитого пламени, и забрался на руку Китавы\n Не раздумывая я разбил его ...  \n Сердце начало ещё сильнее пульсировать и прошёл взрыв... \n", false);
            PrintSlowly("Я проснулся ... Я оказался на том же самом месте ... Но вокруг меня стояли мои друзья - Туджин, Дэннинг, Гвеннен и Рог... Я был неимоверно рад что остался жив ... \n,", false);
            PrintSlowly("Мы покинули это забытое Богом место, по пути домой я рассказывал друзьям о своих приключениях ... Они сказали что мы обязательно сюда вернемся и изучим эту мистическую обитель", false);

        }
    }
    else if (choiceHeart == 2) {
         PrintSlowly("\n Я решил пройти мимо... Чёрт его знает что может стать со мной... Может я стану таким же бесом...", false);
         PrintSlowly("\n Я направился к главным воротам ... Как вдруг... Произошёл яркий красный взрыв... Я снова оказался на том же самом берегу ... Прав был Бес, что ворота для меня навсегда закрыты...", false);
         PrintSlowly("\n Я уже смирился что останусь один... навсегда... Но к берегу начали подплывать корабли с черными мачтами... Я сразу увидел на палубе - капитанов Дэннинга и Туджина, на другом корабле - Гвеннен и Рог", false);
         PrintSlowly("\n Морским путешественникам было дано задание найти своего друга экзайла и колонизировать этот мистический остров", false);
         PrintSlowly("\n Могучие воины, великие мореплаватели помогли своему товарищу и стояли всю жизнь плечом друг к другу, вместе изучали новые подземелья разрушенного города, строили новую цивилизацию на этом острове\n", false);
        }
    
    cout << "\n Поздравляю вы прошли текстовую игру по мотивам игры Path of Exile\n Оценить игру можно в профиле github : @dim4b" << endl;
    cout << "До новых встреч!";
        return 0;
    }
