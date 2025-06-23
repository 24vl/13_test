#include "Item.h"
#include "Character.h"


//---
string HealthPotion::getName()
{
	return name;
}

void HealthPotion::use(Character* character)
{
	character->setHealth(character->getHealth() + effect);
	cout << getName() << "! recover Health +50!" << endl;
	cout << "current health : " << character->getHealth() << endl;
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
	cout << getName() << "! damage +10!" << endl;
	cout << "current damage : " << character->getAttack() << endl;
}

AttackBoost::~AttackBoost() {}