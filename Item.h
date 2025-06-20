#ifndef GameManager_H_
#define GameManager_H_

#include <iostream>	// cin cout
#include <string>	// string
#include <vector>	// vector
#include <cstdlib>	// rand()
#include <ctime>	// time()

#include "Character.h" // 헤더 만들 때, 이름 꼭 똑같이 해주세요!
#include "Monster.h"
#include "Item.h"

#endif

using namespace std;

class Item
{
public:
    Item() {}
   
    virtual string getName() = 0;
    virtual void use(Character* character) = 0;
    
    virtual ~Item() {};
};

