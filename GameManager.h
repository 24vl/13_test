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


class GameManager
{
private:
    bool end = false;
public:
    Monster* generateMonster(int level);
    void battle(Character* player);
    void displayInventory(Character* player);
    void menu(Character* player);
    void displayLog(Character* player);
    void ifnVoidName(Character* player, std::string name);
    void intro();
    void bossAppears();
    void ending();
};


#endif