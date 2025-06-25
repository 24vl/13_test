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
    else // ���� ����
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

        Student6* s6 = new Student6;
        return s6;
    }
}

void GameManager::battle(Character* player)
{
    system("color 0e");
    Monster* monster;
    monster = generateMonster(player->getLevel());
    cout << "!!!!! �߻��� " << monster->getName();
    cout << "�� �����ߴ� !!!!!\n" << endl;
    monster->displayStatus();



    while (true)
    {
        //Sleep(3000); // 3�ʸ��� �� ���� �ڵ� ����
        system("pause");
        system("color 07");
        system("cls");

        cout << "���� ��ô!\n\n";
        // ĳ���� ���� ��� �����
        if (monster->takeDamage(player->getAttack()))
        {
            int r = rand();
            if ((r % 100) < 30)
            {
                if (r % 2 == 0)
                {
                    HealthPotion* h = new HealthPotion;
                    player->getItem(h);
                    cout << "ü�� ���� ȹ��!" << endl;
                }
                else
                {
                    AttackBoost* a = new AttackBoost;
                    player->getItem(a);
                    cout << "���ݷ� ���� ȹ��!" << endl;
                }
            }
            player->setExp(player->getExp() + 50);
            player->setGold(player->getGold() + 10 * (r % 2 + 1));
            player->levelUp();

            if (dynamic_cast<Student6*>(monster) != nullptr)//���� ��� �¸� �� �������� �Ѿ� ��
            {
                delete monster;
                monster = nullptr;
                ending();
                exit(0); // ���α׷� ����
            }
            delete monster;
            monster = nullptr;
            break;
        }

        cout << "�����ϱ�!\n\n";
        // ���� ���� ��� �����

        if (player->takeDamage(monster->getAttack()))
        {
            player->resetStatus(); // ��� �� ����
            delete monster;
            monster = nullptr;
            break;
        }
        player->useItem(0);
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
        system("cls");
        cout << "1.����     2.����     3.����\n\n";
        player->displayStatus();
        cout << "\n";
        displayInventory(player);
        cout << "\n���� : ";
        cin >> number;
        if (number == 1) // ����
        {
            system("cls");
            battle(player);
        }
        else if (number == 2) // ����
        {
            system("cls");
            Shop shop;
            while (true)
            {
                system("pause");
                system("cls");
                cout << "���� ��� : " << player->getGold() << endl;
                displayInventory(player);
                shop.displayItems();
                cout << "1.���� 2.�Ǹ� 3.������" << endl;
                cin >> number;
                if (number == 1) // ����
                {
                    cout << "������ ������ : ";
                    cin >> number;
                    shop.buyItem(number, player);
                    continue;
                }
                else if (number == 2) // �Ǹ�
                {
                    cout << "�Ǹ��� ������ : ";
                    cin >> number;
                    shop.sellItem(number, player);
                    continue;
                }
                else if (number == 3) // ������
                {
                    break;
                }
                else
                {
                    cout << "�߸��� �Է��Դϴ�." << endl;
                    continue;
                }
            }
        }
        else if (number == 3)
        {
            system("cls");
            cout << "������ �����մϴ�." << endl;
            break;
        }
        else
        {
            system("cls");
            cout << "�߸��� �Է��Դϴ�." << endl;
            continue;
        }
    }
}

void GameManager::ending() //����
{
    system("cls");
    cout << "������ �÷��� �� �ּż� �����մϴ�!" << endl;
    system("pause");
}