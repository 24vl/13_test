#include "GameManager.h"
#include "Item.h"
#include "Character.h"
#include "Monster.h"

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
        Student6* s6 = new Student6;
        return s6;
    }
}

void GameManager::battle(Character* player)
{

}

void GameManager::displayInventory(Character* player)
{
    if (!player->getInventory().empty())
    {
        cout << "-- Inventory --" << endl;
        for (Item* it : player->getInventory())
        {
            cout << it->getName() << endl;
        }
    }
    else
    {
        cout << "Inventory is empty!" << endl;
    }
}