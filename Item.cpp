#include "Item.h"

using namespace std;

//--- 체력 회복 포션
// 생성자, 초기화
HealthPotion::HealthPotion() : name("초코바"), effect(50) {}
string HealthPotion::getName() { return name; } // getter
void HealthPotion::use(Character* character) // 아이템 사용
{
	character->setHealth(character->getHealth() + effect);
	cout << getName() << " 먹기! 체력 " << effect << " 회복!" << endl;
	cout << "현재 체력 : " << character->getHealth() << endl;
}
HealthPotion::~HealthPotion() {} // 소멸자

//--- 공격력 증가 포션
// 생성자, 초기화
AttackBoost::AttackBoost() : name("에너지드링크"), effect(5) {}
string AttackBoost::getName() { return name; } // getter
void AttackBoost::use(Character* character) // 아이템 사용
{
	character->setAttack(character->getAttack() + effect);
	cout << getName() << " 마시기! 공격력" << effect << " 증가!" << endl;
	cout << "현재 공격력 : " << character->getAttack() << endl;
}
AttackBoost::~AttackBoost() {} // 소멸자