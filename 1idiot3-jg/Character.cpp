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
    cout << "HP: " << health << "/" << maxHealth << endl;
    cout << "AD: " << attack << endl;
    cout << "LV : " << level << endl;
    cout << "Exp : " << experience <<"/100" << endl;
    cout << "Gold: " << gold << endl;
}

void Character::levelUp()
{ 
    if (level < 10 && experience >= 100)
    {
        int Up = experience / 100; // 150 -> 1  320 -> 3;
        level += Up;
        experience %= 100;
        maxHealth += Up * 20;
        health = maxHealth;
        attack += Up * 5;

        if (Up >= 1)
        {
            cout << "레벨 업! 현재 레벨:" << level <<endl;
        }
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
    if (!Inventory.empty()) // ! not // Inventory.size() != 0; 
    {
        Item* temp = Inventory[index]; // vector<Item*> vec = { &HealthPotion, &AttackBoost }
        temp->use(this);
        delete Inventory[index];
        Inventory.erase(Inventory.begin() + index); // 00004 00008 00012
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

    if (health <= 0) // 사망 시
    {
        health = 0;
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

void Character::resetStatus() // 캐릭터 스텟 리셋 함수
{
    level = 1;
    experience = 0;
    attack = 30;
    health = 200;
    maxHealth = 200;
    gold = 0;
    // delete 
    Inventory.clear(); // 벡터 원소 초기화
}

void Character::skillCharacter()
{
    cout << "과제 투척!" << endl;
    cout << << attack << "데미지를 주었습니다.\n" << endl;

}

Character::~Character()
{
    for (int i = 0; i < Inventory.size(); i++)
    {
        delete Inventory[i];
    }
}

