#include "Item.h"


//---
string HealthPotion::getName()
{
	return name;
}

void HealthPotion::use(Character* character)
{
	character->setHealth(character->getHealth() + effect);
	cout << getName() << " 먹기! 체력 50 회복!" << endl;
	cout << "현재 체력 : " << character->getHealth() << endl;
}

HealthPotion::~HealthPotion() {}

//---
string AttackBoost::getName()
{
	return name;
}

void AttackBoost::use(Character* character)
{
	character->setAttack(character->getAttack() + effect);
	cout << getName() << " 마시기! 공격력 +10!" << endl;
	cout << "현재 공격력 : " << character->getAttack() << endl;
}

AttackBoost::~AttackBoost() {}