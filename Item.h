// Copyright Epic Games, Inc. All Rights Reserved.


#ifndef
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

