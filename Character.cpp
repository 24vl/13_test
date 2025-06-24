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
    cout << " - " << name << " - " << endl;
    cout << "HP: " << health << "/" << maxHealth;
    cout << "     AD: " << attack << endl;
    cout << "LV : " << level;
    cout << "     Exp : " << experience << endl;
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
        delete Inventory[index];
        Inventory.erase(Inventory.begin() + index);
    }
}

void Character::eraseItem(int index)
{
    if (!Inventory.empty())
    {
        delete Inventory[index];
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

int Character::getExp()
{
    return experience;
}

void Character::setExp(int newEXP)
{
    experience = newEXP;
}

int Character::getGold()
{
    return gold;
}

void Character::setGold(int newGold)
{
    gold = newGold;
}

bool Character::takeDamage(int damage)
{
    health -= damage;

    if (health <= 0)
    {
        cout << "다시 돌아오겠다.." << endl;
        cout << " - Game Over -" << endl;
        return true;
    }
    else
    {
        cout << "남은 체력 : " << health << endl;
        cout << "\"으윽! 과제를 더 내주겠다!\"" << endl;
        return false;
    }
}

Character::~Character()
{
    for (int i = 0; i < Inventory.size(); i++)
    {
        delete Inventory[i];
    }
}

