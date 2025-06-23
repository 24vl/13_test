#include "Character.h"
#include "function.h"
#include <string>
#include<iostream>
using namespace std;

enum GAME_STATE
{
    START,
    PLAY,
    END,
    QUIT
   
};


GAME_STATE  state = START;

void nameset(string name)
{
    Character c;
    string cmd;
    cout << "�̸��� �Է��ϼ���." << endl;
    cout << "====================================================================" << endl;
    cin >> cmd;
    cout << "����� �̸��� " << name << "�̱���" << endl;
    cout << "������ �����ϰڽ��ϴ�." << endl;
    cout << "====================================================================" << endl;
    c.setName(name);
}

void bossEvent()
{
    Character c;
    string cmd;
    if (c.getLevel() == 10)
    {
        cout << "�ϴÿ��� �Ŵ��� ����� �������ϴ�." << endl;
        cout << "���� ���� |���|����!" << endl;
        cout << "�ſ� ������ ���Դϴ�. �غ� �Ǽ̽��ϱ�?(��:Y �ƴϿ�:N)";
        cin >> cmd;
        if (cmd == "Y")
        {
            cout << "====================================================================" << endl;
            cout << "���� ���� |���|�� óġ�Ͽ����ϴ�" << endl;
            cout << "GAME CLEAR!" << endl;

            state = QUIT;

        }
    }
}
    void battle()
    {
        Character c;
        string cmd;
        cout << "���Ͱ� �����߽��ϴ�. " << endl;
        cout << "�¼� �ο�ðڽ��ϱ� ? (����:Y ���� N)" << endl;
        cout << "====================================================================" << endl;

        cin >> cmd;
        int MonsterDamage = 0;

        if (cmd == "Y")
        {
            c.damage(MonsterDamage);
            cout << "====================================================================" << endl;
            if (c.getHealth() < 0)
            {
                cout << "����� ���������ϴ�.GAME OVER";
                cout << "====================================================================" << endl;
                state = QUIT;
                
            }


            else
            {
                cout << "���͸� ��ġ�����ϴ�." << endl;

                c.setGold(c.getGold() + 20); c.setExperience(c.getExperience() + 50);
                cout << "50EXP�� ������ϴ�!." << "���� ����ġ:" << c.getExperience() << endl;
                cout << "20Gold�� ������ϴ�!. " << "���� ���:" << c.getGold() << endl;
                cout << "====================================================================" << endl;
                if (c.getExperience() == 100)
                {
                    c.levelUp();
                    cout << "====================================================================" << endl;

                }
                else if (c.getLevel() > 9)
                {
                    cout << "�ִ� ���������� ����ġ�� ������ �����ϴ�." << endl;

                }
                state = PLAY;
            }
        }
    }

    void run()
    {
        
        string cmd;
        if (cmd == "N")
        {

            cout << "������ �����ƽ��ϴ�.";
            state = END;
        }
    }