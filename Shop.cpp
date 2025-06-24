#include "Shop.h"
#include <vector>

Shop::Shop()
{
	cout << "상점에 어서오세요!" << endl;
}

void Shop::displayItems()
{
	cout << "1. Health Potion(체력 + 50) : 10 골드" << endl;
	cout << "2. Attack Boost(공격력 + 10) : 15 골드" << endl;
}

void Shop::buyItem(int index, Character* player)
{
	if (index == 1) // 체력 포션 10골드
	{
		if (player->getGold() >= 10)
		{
			HealthPotion* h = new HealthPotion;
			player->getItem(h);
			player->setGold(player->getGold() - 10);
			cout << "체력 포션 구매!" << endl;
			cout << "남은 골드 : " << player->getGold() << endl;
		}
		else
		{
			cout << "돈이 부족합니다." << endl;
		}
	}
	else if (index == 2) // 공격력 포션 15골드
	{
		if (player->getGold() >= 15)
		{
			AttackBoost* a = new AttackBoost;
			player->getItem(a);
			player->setGold(player->getGold() - 15);
			cout << "공격력 포션 구매!" << endl;
			cout << "남은 골드 : " << player->getGold() << endl;
		}
		else
		{
			cout << "돈이 부족합니다." << endl;
		}
	}
	else
	{
		cout << "그런 상품은 없습니다." << endl;
	}
}

void Shop::sellItem(int index, Character* player)
{
	if (index >= player->getInventory().size() || index < 0)
	{
		cout << "오류 발생" << endl;
		return;
	}

	if (player->getInventory()[index]->getName() == "HealthPotion")
	{
		player->eraseItem(index);
		player->setGold(player->getGold() + 10);
		cout << "포션 판매!" << endl;
		cout << "현재 골드 : " << player->getGold() << endl;
	}
	else if (player->getInventory()[index]->getName() == "AttackBoost")
	{
		player->eraseItem(index);
		player->setGold(player->getGold() + 15);
		cout << "포션 판매!" << endl;
		cout << "현재 골드 : " << player->getGold() << endl;
	}
}

Shop::~Shop()
{
	cout << "이용해 주셔서 감사합니다~" << endl;
}