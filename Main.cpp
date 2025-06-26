#include "GameManager.h"

using namespace std;


// 인트로 // 수정 요망
void Intro()
{
	system("color 09");
	cout << "\n      _      ______      ____       ______      _____       ______      __     " << endl;
	cout << "    /' \\    /\\__  _\\    /\\  _`\\    /\\__  _\\    /\\  __`\\    /\\__  _\\   /'__`\\ " << endl;
	cout << "   /\\_, \\   \\/_/\\ \\/    \\ \\ \\/\\ \\  \\/_/\\ \\/    \\ \\ \\/\\ \\   \\/_/\\ \\/  /\\_\\L\\ \\ " << endl;
	cout << "   \\/_/\\ \\     \\ \\ \\     \\ \\ \\ \\ \\    \\ \\ \\     \\ \\ \\ \\ \\     \\ \\ \\  \\/_/_\\_<_" << endl;
	cout << "      \\ \\ \\     \\_\\ \\__   \\ \\ \\_\\ \\    \\_\\ \\__   \\ \\ \\_\\ \\     \\ \\ \\   /\\ \\L\\ \\ " << endl;
	cout << "       \\ \\_\\    /\\_____\\   \\ \\____/    /\\_____\\   \\ \\_____\\     \\ \\_\\  \\ \\____/" << endl;
	cout << "        \\/_/    \\/_____/    \\/___/     \\/_____/    \\/_____/      \\/_/   \\/___/" << endl;
	cout << "\n                                 - 부제(?) - \n" << endl;
	system("pause");
	system("color 07");
	system("cls");
}

// 닉네임 생성 함수 // GameManager로 옮기기
void ifnVoidName(Character* player, string& name)
{
	cout << "이름을 정해주세요." << endl;
	getline(cin, name);
	player->setName(name);

	if (player->getName() == "")
	{
		cout << "이름은 공백이 될 수 없습니다." << endl;
		system("pause");
		system("cls");
		return ifnVoidName(player, name);
	}

	return;
}


int main()
{
	// 메모리 누수 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(time(NULL)); // 난수 테이블 리셋

	system("title 1IDIOT3"); // 콘솔 창 이름 바꾸기

	Intro(); // 인트로 화면

	GameManager manager; // GameManager 객체 생성
	Character player; // Character 객체 생성
	string name; // 캐릭터 이름 변수

	ifnVoidName(&player, name);

	system("cls"); // 로그 클리어
	player.displayStatus(); // 초기 능력치 출력
	cout << endl;
	
	system("pause"); // 아무 키 입력 시 계속
	system("cls"); // 로그 클리어
	manager.battle(&player); // 실행 최초 강제 전투

	manager.menu(&player); // 게임 루프

	return 0; // 프로그램 종료
}

// *** read me 수정 [Git]
// 
// V *** 메인 메뉴 while (if, else) [GameManager]
// 
// V *** 배틀 루프 [GameManager]
//
// V ** 캐릭터 레벨업 대사 추가 [Character]
// V ** 캐릭터 공격 대사 추가
// V ** 보스 출현 대사
// 
// V ** 몬스터 공격 대사 추가 [Monstser]
//
// V * 캐릭터가 죽으면 처음으로 리셋 //
// 
// V * 상점 만들기 [Shop]
// 
// * 꾸미기(?) 아스키 아트 사용
// 
// V *** 캐릭터 생성 시 닉네임 공백 허용 X [Main] 생성자 if
//
// * 불필요한 get set 합쳐서 새로운 함수로
//
// *** 코드 정리
//
// ** 대사 수정
// 
// V *** Log class 제작
// 전투 ? 아이템 사용 ? 골드 획득 ? ” 중요한 이벤트는 콘솔에 쭉 기록됩니다.
// 로그를 통해 오늘 어떤 몬스터를 몇 마리 눕혔는지~한 눈에 확인 가능!
//
// V *** 메뉴 선택 string 입력 오류
//
// ** 헤더 namespace 삭제, 수정


//필수 체크
//캐릭터 생성 테스트 V
//1. 게임 시작 시 캐릭터 이름 입력
//2. 해당 이름으로 캐릭터가 생성되는지 확인
//Normal
//필수
// 
//캐릭터 이름 공백 입력 V
//1. 캐릭터 이름을 공백으로 입력
//2. 에러 메시지 출력 & 재입력 요구
//Abnormal
//필수
// 
//초기 상태 확인 테스트 V
//1. 캐릭터 생성 후 초기(레벨1, 체력200, 공격력30) 점검
//Normal
//필수
// 
//전투 시스템 테스트 V
//1. 랜덤 몬스터와 전투  2. 공격 / 피격 로직과 HP 감소를 확인
//Normal
//필수
// 
//전투 승리 보상 테스트 V
//1. 전투 승리 후 50경험치 & 랜덤 골드(10~20) 획득
//Normal
//필수
// 
//전투 패배 종료 테스트 V
//1. 플레이어 체력 0 → 게임 오버 메시지 출력 & 종료
//Normal
//필수
// 
//레벨업 테스트 V
//1. 경험치 100 이상 획득 시 레벨 + 1
//2. 체력 / 공격력 증가 정상 반영
//Normal
//필수
// 
//최대 레벨 V
//보스전 테스트
//1. 레벨 10 도달
//2. 보스 몬스터 자동 소환 → 승리 시 게임 클리어
//도전