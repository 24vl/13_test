#include "GameManager.h"
#include "Item.h"
#include "Character.h"
#include "Monster.h"
#include "Shop.h"
#include <iostream>

class Monster;

Monster* GameManager::generateMonster(int level) // level = Character.getLevel()
{
    if (level <= 3)
    {
        if (rand() % 2 == 0)
        {
            Student1* s1 = new Student1;
            return s1;
        }
        else
        {
            Student2* s2 = new Student2();
            return s2;
        }

    }
    else if (level > 3 && level <= 6)
    {
        Student3* s3 = new Student3;
        return s3;
    }
    else if (level > 6 && level <= 9)
    {
        if (rand() % 2 == 0)
        {
            Student4* s4 = new Student4;
            return s4;
        }
        else
        {
            Student5* s5 = new Student5;
            return s5;
        }
    }
    else // 보스 전투
    {
        cout << " ____                               __      __      __     " << endl;
        cout << "/\\  _`\\                            /\\ \\    /\\ \\    /\\ \\    " << endl;
        cout << "\\ \\ \\L\\ \\    ___     ____    ____  \\ \\ \\   \\ \\ \\   \\ \\ \\   " << endl;
        cout << " \\ \\  _ <'  / __`\\  /',__\\  /',__\\  \\ \\ \\   \\ \\ \\   \\ \\ \\  " << endl;
        cout << "  \\ \\ \\L\\ \\/\\ \\L\\ \\/\\__, `\\/\\__, `\\  \\ \\_\\   \\ \\_\\   \\ \\_\\ " << endl;
        cout << "   \\ \\____/\\ \\____/\\/____/\\/____/   \\/\\_\\   \\/\\_\\   \\/\\_\\" << endl;
        cout << "    \\/___/  \\/___/  \\/___/  \\/___/     \\/_/    \\/_/    \\/_/" << endl;
        cout << "                                                           " << endl;
        cout << "                                                          " << endl;
        Student6* s6 = new Student6;
        return s6;
    }
}

void GameManager::battle(Character* player)
{
    Monster* monster;
    monster = generateMonster(player->getLevel());
    cout << "!!!!! 야생의 " << monster->getName();
    cout << "이 등장했다 !!!!!" << endl;
    monster->displayStatus();
    
    while (true)
    {
        system("pause");
        system("cls");

        cout << "과제 투척!\n\n";
        // 캐릭터 공격 대사 만들기
        if (monster->takeDamage(player->getAttack()))
        {
            int r = rand();
            if ((r % 100) < 30)
            {
                if (r % 2 == 0)
                {
                    HealthPotion* h = new HealthPotion;
                    player->getItem(h);
                    cout << "체력 포션 획득!" << endl;
                }
                else
                {
                    AttackBoost* a = new AttackBoost;
                    player->getItem(a);
                    cout << "공격력 포션 획득!" << endl;
                }
            }
            player->setExp(player->getExp() + 50);
            player->setGold(player->getGold() + 10 * (r % 2 + 1));
            player->levelUp();
            delete monster;
            break;
        }
        cout << "반항하기!\n\n";
        // 몬스터 공격 대사 만들기
        if (player->takeDamage(monster->getAttack()))
        {
            break;
        }
        player->useItem(0);

    }
}

void GameManager::displayInventory(Character* player)
{
    if (!player->getInventory().empty())
    {
        cout << "-- Inventory --" << endl;
        for (int i = 0; i < player->getInventory().size(); i++)
        {
            if (player->getInventory()[i] != nullptr)
            {
                cout << i << ". ";
                cout << player->getInventory()[i]->getName() << endl;
            }
        }
        cout << "---------------" << endl;
    }
    else
    {
        cout << "-- Inventory --" << endl;
        cout << "---------------" << endl;
    }
}

void GameManager::menu(Character* player)
{
    system("cls");
    cout << "1.전투     2.상점     3.종료\n\n";
    player->displayStatus();
    cout << "\n";
    displayInventory(player);
}
