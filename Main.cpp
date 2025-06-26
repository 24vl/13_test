#include "GameManager.h"

using namespace std;


int main()
{
	// 메모리 누수 체크
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(time(NULL)); // 난수 테이블 리셋
	system("title 1IDIOT3"); // 콘솔 창 이름 바꾸기

	GameManager manager; // GameManager 객체 생성
	Character player; // Character 객체 생성
	string name; // 캐릭터 이름 변수

	manager.intro(); // 인트로 화면
	manager.ifnVoidName(&player, name); // 닉네임 생성
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
// 
// * 꾸미기(?) 아스키 아트 사용
// 
// *** 코드 정리
//
// ** 대사 수정

//필수 체크
//캐릭터 생성 테스트 V
//1. 게임 시작 시 캐릭터 이름 입력
//2. 해당 이름으로 캐릭터가 생성되는지 확인
//필수
// 
//캐릭터 이름 공백 입력 V
//1. 캐릭터 이름을 공백으로 입력
//2. 에러 메시지 출력 & 재입력 요구
//필수
// 
//초기 상태 확인 테스트 V
//1. 캐릭터 생성 후 초기(레벨1, 체력200, 공격력30) 점검
//필수
// 
//전투 시스템 테스트 V
//1. 랜덤 몬스터와 전투  2. 공격 / 피격 로직과 HP 감소를 확인
//필수
// 
//전투 승리 보상 테스트 V
//1. 전투 승리 후 50경험치 & 랜덤 골드(10~20) 획득
//필수
// 
//전투 패배 종료 테스트 V
//1. 플레이어 체력 0 → 게임 오버 메시지 출력 & 종료
//필수
// 
//레벨업 테스트 V
//1. 경험치 100 이상 획득 시 레벨 + 1
//2. 체력 / 공격력 증가 정상 반영
//필수
// 
//최대 레벨 V
//보스전 테스트
//1. 레벨 10 도달
//2. 보스 몬스터 자동 소환 → 승리 시 게임 클리어
//도전