#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Item.h"

using namespace std;

int Randam()
{
    return rand() % 100;
}

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    srand(time(NULL)); // 랜덤 난수 생성
    
    Character Char;
    Item* item1 = new HealthPotion;
    Item* item2 = new AttackBoost;
    
    cout << "GAME START!" << endl;
    int num;
    while (true)
    {
        cout << "1. battle / 2. use item / 3. run" << endl;
        cin >> num;
        if (num == 1)
        {
            cout << "WIN --- item get!" << endl;
            if (Randam() % 100 < 25)
            {
                Char.getItem(item1);
            }
            else if (Randam() % 100 > 74)
            {
                Char.getItem(item2);
            }
            else
            {
                cout << "no item~" << endl;
            }
            system("pause");
            system("cls");
            Char.displayInventory();
        }
        else if (num == 2)
        {
            Char.useItem(0);
            system("pause");
            system("cls");
            Char.displayInventory();
        }
        else if (num == 3)
        {
            cout << "run" << endl;
            break;
        }
        else
        {
            continue;
        }
    }
    return 0;
}