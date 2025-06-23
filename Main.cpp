#include "GameManager.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(time(NULL)); // 

	GameManager m;
	string str;
	cin >> str;
	Character c(str);
	HealthPotion h;
	AttackBoost a;
	c.displayStatus();

	c.getItem(&h);
	c.getItem(&a);
	c.getItem(&a);
	c.getItem(&h);
	m.displayInventory(&c);
	c.useItem(0);
	c.useItem(0);
	m.displayInventory(&c);

	cout << endl;
	Monster* temp;
	temp = m.generateMonster(c.getLevel());
	cout << "내배캠의 " << temp->getName();
	cout << "이 등장했다!" << endl;

	temp->takeDamage(c.getAttack());
	temp->checkDead();


	return 0;
}