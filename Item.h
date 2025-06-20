#ifndef GameManager_H_
#define GameManager_H_

#include <iostream>
#include "Item.h"
#include "Character.h"
#include "Monster.h"
#include <string>

using namespace std;

class Item
{
public:
    Item() {}
   
    virtual string getName() = 0;
    virtual void use(Character* character) = 0;
    
    virtual ~void Item() {};
};

