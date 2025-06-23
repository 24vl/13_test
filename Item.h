#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

class Character;

class Item
{
protected:

public:
	virtual string getName() = 0;
	virtual void use(Character* character) = 0;
	virtual ~Item() {}
};

class HealthPotion : public Item
{
private:
	string name;
	int effect;

public:
	HealthPotion() : name("HealthPotion"), effect(50) {}
	string getName();
	void use(Character* character);
	~HealthPotion();
};

class AttackBoost : public Item
{
private:
	string name;
	int effect;

public:
	AttackBoost() : name("AttackBoost"), effect(10) {}
	string getName();
	void use(Character* character);
	~AttackBoost();
};

#endif