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

class AttackBoost : public Item
{
protected:
    string name;
    int attackincrease;
public:
    AttackBoost() 
	{
		name = "공격력 버프";
		attackincrease = 10;
	}

    string getName()
    {
        return name;
    }
    void use(Character* character)
    {
        character->useItem(0);
    }
virtual ~AttackBoost;
}