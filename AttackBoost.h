// Copyright Epic Games, Inc. All Rights Reserved.

#include <iostream>
#ifndef "Item.h"
#include <string>

using namespace std;

class AttackBoost : public Item
{
private:
    string name;
    int attackincrease;
public:
    AttackBoost() {}

    string getName()
    {
        return name;
    }
    void use(Character* character)
    {
        cout << character->use << "이럴 때 아이템!" << endl;
    }
}