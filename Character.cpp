#include "Character.h"

//--- 생성자
Character::Character(string n = " ") : name(n)
{
    health = maxHealth;
}


//--- getter
string Character::getName() { return name; }
int Character::getLevel() { return level; }
int Character::getExp() { return experience; }
int Character::getAttack() { return attack; }
int Character::getHealth() { return health; }
int Character::getGold() { return gold; }
vector<Item*> Character::getInventory() { return Inventory; }
int Character::getKillCount() { return killCount; }
map<string, int> Character::getKillLog() { return killLog; }


//--- setter
void Character::setName(string n) { name = n; }
void Character::setExp(int newEXP) { experience = newEXP; }
void Character::setAttack(int newAttack) { attack = newAttack; }
void Character::setHealth(int newHealth) 
{
    health = newHealth;
    if (health > maxHealth) { health = maxHealth; }
}
void Character::setGold(int newGold) { gold = newGold; }
void Character::setKillCount(int newCount) { killCount = newCount; }

//--- 기타 기능
// 상태창 출력
void Character::displayStatus()
{
    cout << " - " << name << " - ";
    cout << " LV:" << level << " (" << experience << "%)" << endl;
    cout << "HP:" << health << "/" << maxHealth;
    cout << "  AD:" << attack << endl;
    cout << "Gold:" << gold << "  kill:" << killCount << endl;
}
// 레벨 업
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
            cout << "레벨 업! 현재 레벨:" << level << endl;
        }
    }

    if (level > 10)
    {
        level = 10;
    }
}
// 캐릭터 리셋
void Character::resetStatus()
{
    level = 1;
    experience = 0;
    attack = 30;
    health = 200;
    maxHealth = 200;
    gold = 0;
    killCount = 0;
    // delete 
    for (int i = 0; i < Inventory.size(); i++)
    {
        delete Inventory[i];
    }
    Inventory.clear(); // 벡터 원소 초기화
    killLog.clear();
}
// 몬스터별 킬 카운트
void Character::insertKillLog(string killName)
{
    if (killLog.find(killName) == killLog.end())
    {
        killLog[killName] = 1;
    }
    else
    {
        killLog[killName]++;
    }
}


//--- 아이템 관련
// 인벤토리 아이템 추가
void Character::getItem(Item* item)
{
    Inventory.push_back(item);
}
// 아이템 사용
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
// 인벤토리 아이템 제거
void Character::eraseItem(int index)
{
    if (!Inventory.empty())
    {
        delete Inventory[index];
        Inventory.erase(Inventory.begin() + index);
    }
}


//--- 전투 기능
// 몬스터 피격
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
// 몬스터 공격
void Character::skillCharacter()
{
    cout << "과제 투척!" << endl;
    cout << attack << "데미지를 주었습니다.\n" << endl;

}


//--- 소멸자 // 메모리 누수 방지
Character::~Character()
{
    for (int i = 0; i < Inventory.size(); i++)
    {
        delete Inventory[i];
    }
}