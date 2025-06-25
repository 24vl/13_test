#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <memory>
#include <map>

#include "Item.h"

using namespace std;

class Item;

class Character
{
private:
    string name;
    int level = 1;
    int experience = 0;
    int attack = 300;
    int health = 200;
    int maxHealth = 200;
    int gold = 0;
    vector<Item*> Inventory;
    int killCount = 0;
    map<string, int> killLog;
    

public:
    Character(string name);

    string getName();
    int getLevel();
    int getExp();
    int getAttack();
    int getHealth();
    int getGold();
    vector<Item*> getInventory();
    int getKillCount();
    map<string, int> getKillLog();

    void setName(string n);
    void setExp(int num);
    void setAttack(int newAttack);
    void setHealth(int newHealth);
    void setGold(int num);
    void setKillCount(int newCount);

    void displayStatus();
    void levelUp();
    void insertKillLog(string killName);
    void resetStatus();

    void getItem(Item* item);
    void useItem(int index);
    void eraseItem(int index);
    
    bool takeDamage(int damage);
    void skillCharacter();

    ~Character();
};


#endif
