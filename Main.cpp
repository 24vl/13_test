#include "GameManager.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL));

	GameManager m;
	string str;

	cout << "\n      _      ______      ____       ______      _____       ______      __     " << endl;
	cout << "    /' \\    /\\__  _\\    /\\  _`\\    /\\__  _\\    /\\  __`\\    /\\__  _\\   /'__`\\ " << endl;
	cout << "   /\\_, \\   \\/_/\\ \\/    \\ \\ \\/\\ \\  \\/_/\\ \\/    \\ \\ \\/\\ \\   \\/_/\\ \\/  /\\_\\L\\ \\ " << endl;
	cout << "   \\/_/\\ \\     \\ \\ \\     \\ \\ \\ \\ \\    \\ \\ \\     \\ \\ \\ \\ \\     \\ \\ \\  \\/_/_\\_<_" << endl;
	cout << "      \\ \\ \\     \\_\\ \\__   \\ \\ \\_\\ \\    \\_\\ \\__   \\ \\ \\_\\ \\     \\ \\ \\   /\\ \\L\\ \\ " << endl;
	cout << "       \\ \\_\\    /\\_____\\   \\ \\____/    /\\_____\\   \\ \\_____\\     \\ \\_\\  \\ \\____/" << endl;
	cout << "        \\/_/    \\/_____/    \\/___/     \\/_____/    \\/_____/      \\/_/   \\/___/" << endl;
	cout << "\n                                 - 새로운 과제의 여정 - \n" << endl;
	system("pause");
	system("cls");
	
	cout << "이름을 지어주세요." << endl;
	cin >> str;
	Character c(str);
	c.displayStatus();
	cout << endl;
	
	system("pause");
	system("cls");

	m.battle(&c);

	int num;
	while (true)
	{
		system("pause");
		m.menu(&c);
		cin >> num;
		if (num == 1)
		{
			system("cls");
			cin.ignore();
			m.battle(&c);
		}
		else if (num == 2)
		{
			system("cls");
			cout << "상점이 없습니다." << endl;
		}
		else if (num == 3)
		{
			system("cls");
			cout << "게임을 종료합니다." << endl;
			break;
		}
		else
		{
			system("cls");
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
	}

	return 0;
}

// read me 수정 [Git]
// 
// 메인 메뉴  switch || while (if, else) [GameManager]
// 
// - 배틀 루프 [GameManager]
// 루프 끝마다 사망 체크 break;
// 캐릭터 사망 체크 [Character] -> bool type
// 
// 캐릭터 takeDamage [Character]
// 캐릭터 레벨업 대사 추가
// 
// takeDamage -> if hp < 0 => hp = 0; [Monster]
// 사망 대사? 리뉴얼? // if == 0 [Monstser]
// 캐릭터가 죽으면 처음으로 리셋
// 
// setGold() []