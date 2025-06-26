#ifndef ITEM_H
#define ITEM_H

#include "Character.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>


class Character;

class Item
{
protected:

public:
	virtual std::string getName() = 0;
	virtual void use(Character* character) = 0;
	virtual ~Item() {}
};

class HealthPotion : public Item
{
private:
	std::string name;
	int effect;

public:
	HealthPotion();
	std::string getName();
	void use(Character* character);
	~HealthPotion();
};

class AttackBoost : public Item
{
private:
	std::string name;
	int effect;

public:
	AttackBoost();
	std::string getName();
	void use(Character* character);
	~AttackBoost();
};

#endif