#ifndef Item_H_
#define Item_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Item;
class Character;

class Item
{
public:
	virtual string getName() = 0;
	virtual void use(Character* character) = 0;
	virtual ~Item() {}
};

class Character
{
protected:
	string name;
	int attack = 30;
	int health = 200;
	int maxHealth = 200;
	vector<Item*> Inventory;

public:
	Character(string n = " ") : name(n)
	{
		health = maxHealth;
	}

	vector<Item*> getInventory()
	{
		return Inventory;
	}

	void getItem(Item* item)
	{
		Inventory.push_back(item);
	}

	void displayInventory()
	{
		if (!Inventory.empty())
		{
			cout << "-- Inventory --" << endl;
			for (Item* it : Inventory)
			{
				cout << it->getName() << endl; // 포인터 지옥
			}
		}
		else
		{
			cout << "Inventory is empty!" << endl;
		}
	}

	void useItem(int index)
	{
		if (!Inventory.empty())
		{
			Item* temp = Inventory[index];
			temp->use(this);
			Inventory.erase(Inventory.begin() + index);
		}
	}

	int getAttack()
	{
		return attack;
	}

	void setAttack(int newAttack)
	{
		attack = newAttack;
	}

	int getHealth()
	{
		return health;
	}

	void setHealth(int newHealth)
	{
		health = newHealth;
		if (health > maxHealth)
		{
			health = maxHealth;
		}
	}

	~Character()
	{
		if (!Inventory.empty())
		{
			for (Item* it : Inventory)
			{
				delete it;
			}
		}
	}
};

class HealthPotion : public Item
{
private:
	string name;
	int effect;

public:
	HealthPotion() : name("HealthPotion"), effect(50) {}
	
	string getName()
	{
		return name;
	}

	void use(Character* character)
	{
		character->setHealth(character->getHealth() + effect);
		cout << getName() << "! recover Health +50!" <<endl;
		cout << "current health : " << character->getHealth() << endl;
	}
};

class AttackBoost : public Item
{
private:
	string name;
	int effect;

public:
	AttackBoost() : name("AttackBoost"), effect(10) {}
	
	string getName()
	{
		return name;
	}
	
	void use(Character* character)
	{
		character->setAttack(character->getAttack() + effect);
		cout << getName() << "! damage +10!" <<endl;
		cout << "current damage : " << character->getAttack() << endl;
	}
	~AttackBoost() {}
};

#endif