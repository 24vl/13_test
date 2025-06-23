#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "Item.h"

using namespace std;

class Item;

class Character
{
protected:
    string name;
    int level = 1;
    int experience = 0;
    int attack = 30;
    int health = 200;
    int maxHealth = 200;
    int gold = 0;
    vector<Item*> Inventory;
    

public:
    Character(string name);

    string getName();
    void setName(string n);
    void displayStatus();
    void levelUp();
    int getLevel();
    vector<Item*> getInventory();
    void getItem(Item* item);
    void useItem(int index);
    int getAttack();
    void setAttack(int newAttack);
    int getHealth();
    void setHealth(int newHealth);
    ~Character();
};


#endif
