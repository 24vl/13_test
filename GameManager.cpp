#include "GameManager.h"

class Monster;

Monster* GameManager::generateMonster(int level) // level = Character.getLevel()
{
    if (level <= 3)
    {
        if (rand() % 2 == 0)
        { 
            return new Student1;
        }
        else
        {
            return new Student2();
        }

    }
    else if (level > 3 && level <= 6)
    {
        return new Student3;
    }
    else if (level > 6 && level <= 9)
    {
        if (rand() % 2 == 0)
        {
            return new Student4;
        }
        else
        {
            return new Student5;
        }
    }
    else // 보스 전투
    {
        system("color 0c");
        cout << " ____                               __      __      __     " << endl;
        cout << "/\\  _`\\                            /\\ \\    /\\ \\    /\\ \\    " << endl;
        cout << "\\ \\ \\L\\ \\    ___     ____    ____  \\ \\ \\   \\ \\ \\   \\ \\ \\   " << endl;
        cout << " \\ \\  _ <'  / __`\\  /',__\\  /',__\\  \\ \\ \\   \\ \\ \\   \\ \\ \\  " << endl;
        cout << "  \\ \\ \\L\\ \\/\\ \\L\\ \\/\\__, `\\/\\__, `\\  \\ \\_\\   \\ \\_\\   \\ \\_\\ " << endl;
        cout << "   \\ \\____/\\ \\____/\\/____/\\/____/   \\/\\_\\   \\/\\_\\   \\/\\_\\" << endl;
        cout << "    \\/___/  \\/___/  \\/___/  \\/___/     \\/_/    \\/_/    \\/_/" << endl;
        cout << "                                                           " << endl;
        cout << "                                                          " << endl;
        Sleep(1500); // 1500ms

        return new Student6;
    }
}

void GameManager::battle(Character* player)
{
    system("color 0e");
    Monster* monster;
    monster = generateMonster(player->getLevel());
    cout << "!!!!! 튜터실에 " << monster->getName();
    cout << "이 나타났다 !!!!!\n" << endl;
    monster->displayStatus();

    while (true)
    {
        //Sleep(3000); // 3초마다 턴 종료 자동 전투
        system("pause");
        system("color 07");
        system("cls");

        player->skillCharacter();
        if (monster->takeDamage(player->getAttack()))
        {
            int r = rand();
            if ((r % 100) < 30)
            {
                if (r % 2 == 0)
                {
                    Item* h = new HealthPotion;
                    player->getItem(h);
                    cout << h->getName() << " 획득!" << endl;
                }
                else
                {
                    Item* a = new AttackBoost;
                    player->getItem(a);
                    cout << a->getName() << " 획득!" << endl;
                }
            }
            player->setExp(player->getExp() + 50);
            player->setGold(player->getGold() + 10 * (r % 2 + 1));
            player->setKillCount(player->getKillCount() + 1);
            player->insertKillLog(monster->getName());
            player->levelUp();

            if (monster->getName() == "장재근 학생") { end = true; }

            delete monster;
            monster = nullptr;
            break;
        }
        
        monster->skillMonster();
        if (player->takeDamage(monster->getAttack()))
        {
            player->resetStatus(); // 사망 시 리셋
            delete monster;
            monster = nullptr;
            break;
        }

        player->useItem(0); // 아이템 사용 로직 미구현
    }
}

void GameManager::displayInventory(Character* player)
{
    if (!player->getInventory().empty())
    {
        cout << " = Inventory = " << endl;
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
        cout << " = Inventory = " << endl;
        cout << "---------------" << endl;
    }
}

void GameManager::menu(Character* player)
{
    int number;

    while (true)
    {
        system("pause");
        if (end) 
        { 
            ending();
            break; 
        }
        system("cls");
        cout << "1.전투  2.상점  3.로그  4.종료\n\n";
        player->displayStatus();
        cout << "\n";
        displayInventory(player);
        cout << "\n선택 : ";
        cin >> number;
        if (number == 1) // 전투
        {
            system("cls");
            battle(player);
        }
        else if (number == 2) // 상점
        {
            system("cls");
            Shop shop;
            while (true)
            {
                system("pause");
                system("cls");
                cout << "소지 골드 : " << player->getGold() << endl;
                displayInventory(player);
                shop.displayItems();
                cout << "1.구매 2.판매 3.떠나기" << endl;
                cin >> number;
                if (number == 1) // 구매
                {
                    cout << "구매할 아이템 : ";
                    cin >> number;
                    shop.buyItem(number, player);
                    continue;
                }
                else if (number == 2) // 판매
                {
                    cout << "판매할 아이템 : ";
                    cin >> number;
                    shop.sellItem(number, player);
                    continue;
                }
                else if (number == 3) // 떠나기
                {
                    break;
                }
                else
                {
                    cin.clear();
                    string dummy;
                    getline(cin, dummy);
                    //while (cin.get() == '\n') continue;
                    cout << "잘못된 입력입니다." << endl;
                    continue;
                }
            }
        }
        else if (number == 3)
        {
            displayLog(player);
            continue;
        }
        else if (number == 4)
        {
            system("cls");
            cout << "게임을 종료합니다." << endl;
            break;
        }
        else
        {
            system("cls");
            cin.clear();
            string dummy;
            getline(cin, dummy);
            cout << "잘못된 입력입니다." << endl;
            continue;
        }
    }
}

void GameManager::displayLog(Character* player)
{
    cout << "\n    내준 과제\n";
    cout << "-----------------\n\n";
    for (auto it : player->getKillLog())
    {
        cout << it.first << " : " << it.second << "개\n";
    }
    cout << "\n-----------------\n" << endl;
}

void GameManager::ending() //엔딩
{
    system("cls");
    cout << "게임을 플레이 해 주셔서 감사합니다!" << endl;
}