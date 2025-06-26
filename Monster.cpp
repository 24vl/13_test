#include "Monster.h"

using namespace std;

//--- Monster / 부모 클래스
// getter
string Monster::getName() {	return name; }
int Monster::getAttack() { return attack; }
int Monster::getHealth() { return health; }
void Monster::displayStatus() // 능력치 출력
{
	// UI 수정 요망
	cout << "- " << getName() << " ------------------" << endl;
	cout << "공격력 : " << getAttack() << "   / 체력 : " << getHealth() << endl;
	cout << "\n";
}


//--- Student1 / 성준모 학생
bool Student1::takeDamage(int damage) // Character.getAttack();
{
	health -= damage;
	if (health < 0) 
	{
		health = 0;
		// 사망 대사
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		// 피격 대사
		cout << "\"으악! 과제 그만!\"" << endl;
		cout << "[" << name << "의 남은 체력 : " << health << "]" << endl;
		return false;
	}
}
void Student1::skillMonster()
{
	//공격 대사
	cout << "질문 공세!  \"튜터님 이건 어떻게 해야하나요 ㅜㅜ\"" << endl;
	cout << attack << "의 데미지를 받았습니다.\n" << endl;
}


//--- Student2 / 김지원 학생
bool Student2::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"흑흑 과제를 또 주시는건가요?\"" << endl;
		return false;
	}
}
void Student2::skillMonster()
{
	cout << "반항하기!" << endl;
	cout << attack << "의 데미지를 받았습니다.\n" << endl;
}


//--- Student3 / 김성빈 학생
bool Student3::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"하하.. 하하.. 과제다..\"" << endl;
		return false;
	}
}
void Student3::skillMonster()
{
	cout << "\"오아~!\"" << endl;
	cout << attack << "의 데미지를 받았습니다.\n" << endl;
}


//--- Student4 / 최선호 학생
bool Student4::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"과제.. 해야죠.. 그럼요..\"" << endl;
		return false;
	}
}
void Student4::skillMonster()
{
	cout << "반항하기!" << endl;
	cout << attack << "의 데미지를 받았습니다.\n" << endl;
}


//--- Student5 / 전형준 학생
bool Student5::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"어.. 잘 모르겠지만 해보겠습니다..\"" << endl;
		return false;
	}
}
void Student5::skillMonster()
{
	cout << "반항하기!" << endl;
	cout << attack << "의 데미지를 받았습니다.\n" << endl;
}


//--- Student6 / 장재근 학생
bool Student6::takeDamage(int damage)
{
	health -= damage;
	if (health < 0)
	{
		health = 0;
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"다 했습니다! 과제 더 주실건가요?\"" << endl;
		return false;
	}
}
void Student6::skillMonster()
{
	cout << "반항하기!" << endl;
	cout << attack << "의 데미지를 받았습니다.\n" << endl;
}