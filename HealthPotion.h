#ifndef GameManager_H_
#define GameManager_H_

#include <iostream>
#include "Item.h"
#include "Character.h"
#include "Monster.h"
#include <string>

using namespace std;

class HealthPotion : public Item
{
private:
    string name;
    int healthRestore;
public:
    HealthPotion()

    string getName()
    {
    return name;
    }

    void use(Character* character)
    {
    cout << character.use << "이럴 때 아이템!" << endl;
    }
}