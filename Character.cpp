#include "Character.h"
#include "Item.h"

Character::Character(string n = " ") : name(n)
{
    health = maxHealth;
}

string Character::getName()
{
    return name;
}

void Character::setName(string n)
{
    name = n;
}

void Character::displayStatus()
{
    cout << "Name: " << name << endl;
    cout << "HP: " << health << "/" << maxHealth;
    cout << "     AD: " << attack << endl;
    cout << "LV : " << level << endl;
    cout << "Exp : " << experience << endl;
    cout << "Gold: " << gold << endl;
}

void Character::levelUp()
{
    if (level < 10 && experience >= 100)
    {
        int Up = experience / 100;
        level += Up;
        experience %= 100;
        maxHealth += Up * 20;
        health = maxHealth;
        attack += Up * 5;
    }

    if (level > 10)
    {
        level = 10;
    }
}

int Character::getLevel()
{
    return level;
}

vector<Item*> Character::getInventory()
{
    return Inventory;
}

void Character::getItem(Item* item)
{
    Inventory.push_back(item);
}

void Character::useItem(int index)
{
    if (!Inventory.empty())
    {
        Item* temp = Inventory[index];
        temp->use(this);
        Inventory.erase(Inventory.begin() + index);
    }
}

int Character::getAttack()
{
    return attack;
}

void Character::setAttack(int newAttack)
{
    attack = newAttack;
}

int Character::getHealth()
{
    return health;
}

void Character::setHealth(int newHealth)
{
    health = newHealth;
    if (health > maxHealth)
    {
        health = maxHealth;
    }
}

Character::~Character()
{

}

