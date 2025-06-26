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

class Item; // 전방 선언 안하면 오류 남 이유는 몰?루

class Character
{
private:
    std::string name;
    int level = 1;
    int experience = 0;
    int attack = 30;
    int health = 200;
    int maxHealth = 200;
    int gold = 0;
    std::vector<Item*> Inventory;
    int killCount = 0;
    std::map<std::string, int> killLog;
    

public:
    Character(std::string n = "player") : name(n) {}

    std::string getName();
    int getLevel();
    int getExp();
    int getAttack();
    int getHealth();
    int getGold();
    std::vector<Item*> getInventory();
    int getKillCount();
    std::map<std::string, int> getKillLog();

    void setName(std::string n);
    void setExp(int num);
    void setAttack(int newAttack);
    void setHealth(int newHealth);
    void setGold(int num);
    void setKillCount(int newCount);

    void displayStatus();
    void levelUp();
    void insertKillLog(std::string killName);
    void resetStatus();

    void getItem(Item* item);
    void useItem(int index);
    void eraseItem(int index);
    
    bool takeDamage(int damage);
    void skillCharacter();

    ~Character();
};


#endif
