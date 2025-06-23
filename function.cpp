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
    cout << "이름을 입력하세요." << endl;
    cout << "====================================================================" << endl;
    cin >> cmd;
    cout << "당신의 이름은 " << name << "이군요" << endl;
    cout << "게임을 시작하겠습니다." << endl;
    cout << "====================================================================" << endl;
    c.setName(name);
}

void bossEvent()
{
    Character c;
    string cmd;
    if (c.getLevel() == 10)
    {
        cout << "하늘에서 거대한 기운이 느껴집니다." << endl;
        cout << "보스 몬스터 |흑룡|출현!" << endl;
        cout << "매우 강력한 적입니다. 준비가 되셨습니까?(예:Y 아니요:N)";
        cin >> cmd;
        if (cmd == "Y")
        {
            cout << "====================================================================" << endl;
            cout << "보스 몬스터 |흑룡|을 처치하였습니다" << endl;
            cout << "GAME CLEAR!" << endl;

            state = QUIT;

        }
    }
}
    void battle()
    {
        Character c;
        string cmd;
        cout << "몬스터가 등장했습니다. " << endl;
        cout << "맞서 싸우시겠습니까 ? (전투:Y 도주 N)" << endl;
        cout << "====================================================================" << endl;

        cin >> cmd;
        int MonsterDamage = 0;

        if (cmd == "Y")
        {
            c.damage(MonsterDamage);
            cout << "====================================================================" << endl;
            if (c.getHealth() < 0)
            {
                cout << "당신은 쓰러졌습니다.GAME OVER";
                cout << "====================================================================" << endl;
                state = QUIT;
                
            }


            else
            {
                cout << "몬스터를 해치웠습니다." << endl;

                c.setGold(c.getGold() + 20); c.setExperience(c.getExperience() + 50);
                cout << "50EXP를 얻었습니다!." << "현재 경험치:" << c.getExperience() << endl;
                cout << "20Gold를 얻었습니다!. " << "현재 골드:" << c.getGold() << endl;
                cout << "====================================================================" << endl;
                if (c.getExperience() == 100)
                {
                    c.levelUp();
                    cout << "====================================================================" << endl;

                }
                else if (c.getLevel() > 9)
                {
                    cout << "최대 레벨임으로 경험치를 얻을수 없습니다." << endl;

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

            cout << "무사히 도망쳤습니다.";
            state = END;
        }
    }