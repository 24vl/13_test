#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Character.h"
#include "Item.h"
#include "Monster.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Monster;

class GameManager
{

public:
    Monster* generateMonster(int level);
    void battle(Character* player);
    void displayInventory(Character* player);
    
};



#endif