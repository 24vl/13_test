// Copyright Epic Games, Inc. All Rights Reserved.

#include <iostream>
#ifndef "item.h"
#include <string>
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
    cout << character->use << "이럴 때 아이템!" << endl;
    }
}