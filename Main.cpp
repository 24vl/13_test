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
	cout << "\n                                 - 사랑의 매 - \n" << endl;
	system("pause");
	system("cls");
	
	cout << "이름을 지어주세요." << endl;
	cin >> str;
	if (str == "")
	{
		cout << "닉네임은 공백으로 할 수 없습니다." << endl;
		return main();
	}
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

// *** read me 수정 [Git]
// 
// *** 메인 메뉴  switch || while (if, else) [GameManager]
// 
// *** 배틀 루프 [GameManager]
//
// ** 캐릭터 레벨업 대사 추가 [Character]
// ** 캐릭터 공격 대사 추가
// 
// ** 몬스터 공격 대사 추가 [Monstser]
//
// * 캐릭터가 죽으면 처음으로 리셋 [GameManager]
// 
// * 상점 만들기 [Shop]
// 
// * 꾸미기(?) 아스키 아트 사용
// 
// *** 캐릭터 생성 시 닉네임 공백 허용 X [Main] 생성자 if
//
// * 불필요한 get set 합쳐서 새로운 함수로
//
// *** 코드 정리
//
// ** 대사 수정

//캐릭터 생성 테스트 O
//1. 게임 시작 시 캐릭터 이름 입력
//2. 해당 이름으로 캐릭터가 생성되는지 확인
//Normal
//필수
// 
//캐릭터 이름 공백 입력 O
//1. 캐릭터 이름을 공백으로 입력
//2. 에러 메시지 출력 & 재입력 요구
//Abnormal
//필수
// 
//초기 상태 확인 테스트 O
//1. 캐릭터 생성 후 초기(레벨1, 체력200, 공격력30) 점검
//Normal
//필수
// 
//전투 시스템 테스트 O
//1. 랜덤 몬스터와 전투  2. 공격 / 피격 로직과 HP 감소를 확인
//Normal
//필수
// 
//전투 승리 보상 테스트 O
//1. 전투 승리 후 50경험치 & 랜덤 골드(10~20) 획득
//Normal
//필수
// 
//전투 패배 종료 테스트 O
//1. 플레이어 체력 0 → 게임 오버 메시지 출력 & 종료
//Normal
//필수
// 
//레벨업 테스트 O
//1. 경험치 100 이상 획득 시 레벨 + 1
//2. 체력 / 공격력 증가 정상 반영
//Normal
//필수