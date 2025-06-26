#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Character.h"
#include "Item.h"
#include "Monster.h"
#include "Shop.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <windows.h>
#include <map>

using namespace std;

class GameManager
{
private:
    bool end = false;
public:
    Monster* generateMonster(int level); // 몬스터 동적 할당 함수
    void battle(Character* player); // 반복 자동 전투
    void displayInventory(Character* player); // 물약 가방 출력
    void menu(Character* player); // 무한 반복 메뉴 출력
    void displayLog(Character* player); // 처치 내용 출력
    void bossAppears();
    void ending();
};


#endif