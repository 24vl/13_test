#include "Shop.h"

using namespace std;

//--- 생성자
Shop::Shop()
{
	// 상점 입장 대사
	cout << "상점에 어서오세요!" << endl;
}

// 판매 목록 // 벡터 사용 X 하드 코딩했음
void Shop::displayItems()
{
	cout << "\n1. 초코바(회복 + 50) : 10 골드" << endl;
	cout << "2. 에너지드링크(공격력 + 5) : 15 골드\n" << endl;
}

// 아이템 구매
void Shop::buyItem(int index, Character* player)
{
	if (index == 1) // 체력 포션 10골드
	{
		if (player->getGold() >= 10)
		{
			Item* h = new HealthPotion;
			player->getItem(h);
			player->setGold(player->getGold() - 10);
			cout << h->getName() << " 구매!" << endl;
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
			Item* a = new AttackBoost;
			player->getItem(a);
			player->setGold(player->getGold() - 15);
			cout << a->getName() << " 구매!" << endl;
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

// 아이템 판매
void Shop::sellItem(int index, Character* player)
{
	// 벡터 인덱스 범위 오류 방지
	if (index >= player->getInventory().size() || index < 0)
	{
		cout << "오류 발생" << endl;
		return;
	}

	if (player->getInventory()[index]->getName() == "초코바")
	{
		player->eraseItem(index);
		player->setGold(player->getGold() + 10);
		cout << "포션 판매!" << endl;
		cout << "현재 골드 : " << player->getGold() << endl;
	}
	else if (player->getInventory()[index]->getName() == "에너지드링크")
	{
		player->eraseItem(index);
		player->setGold(player->getGold() + 15);
		cout << "판매 완료!" << endl;
		cout << "현재 골드 : " << player->getGold() << endl;
	}
}

//--- 소멸자
Shop::~Shop()
{
	// 상점 퇴장 대사
	cout << "이용해 주셔서 감사합니다~" << endl;
}