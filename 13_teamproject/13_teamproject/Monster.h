#pragma once

#include <iostream>
#include <string>

using namespace std;

class Monster 
{
protected:
	string name;
	int attack;
	int health;

public:
	Monster(string name) : name(name) {}
	virtual string getName() = 0;
	virtual int getAttack() = 0;
	virtual int getHealth() = 0;
	virtual void takeDamage(int damage) = 0;
};

class Student1 : public Monster
{
public:
	Student1() : Monster("성준모 학생") {}


	string getName()
	{
		name = "성준모 학생";
		return name;
	}
	int getAttack()
	{
		attack = 5;
		return attack;
	}
	int getHealth()
	{
		health = 20;
		return health;
	}
	void takeDamage(int damage)
	{
		health -= damage;
		cout << "남은 체력 : " << health << endl;
		cout << "으악! 과제 그만!" << endl;
	}
};

class Student2 : public Monster
{
public:
	Student2() : Monster("김지원 학생") {}


	string getName()
	{
		name = "김지원 학생";
		return name;
	}
	int getAttack()
	{
		attack = 5;
		return attack;
	}
	int getHealth()
	{
		health = 20;
		return health;
	}
	void takeDamage(int damage)
	{
		health -= damage;
		cout << "남은 체력 : " << health << endl;
		cout << "흑흑 과제 그만주세요..." << endl;
	}
};

class Student3 : public Monster
{
public:
	Student3() : Monster("김성빈 학생") {}


	string getName()
	{
		name = "김성빈 학생";
		return name;
	}
	int getAttack()
	{
		attack = 10;
		return attack;
	}
	int getHealth()
	{
		health = 40;
		return health;
	}
	void takeDamage(int damage)
	{
		health -= damage;
		cout << "남은 체력 : " << health << endl;
		cout << "아.. 하하.. 하하.." << endl;
	}
};

class Student4 : public Monster
{
public:
	Student4() : Monster("최선호 학생") {}


	string getName()
	{
		name = "최선호 학생";
		return name;
	}
	int getAttack()
	{
		attack = 15;
		return attack;
	}
	int getHealth()
	{
		health = 60;
		return health;
	}
	void takeDamage(int damage)
	{
		health -= damage;
		cout << "남은 체력 : " << health << endl;
		cout << "어.. 해보겠습니다.." << endl;
	}
};

class Student5 : public Monster
{
public:
	Student5() : Monster("전형준 학생") {}


	string getName()
	{
		name = "전형준 학생";
		return name;
	}
	int getAttack()
	{
		attack = 15;
		return attack;
	}
	int getHealth()
	{
		health = 60;
		return health;
	}
	void takeDamage(int damage)
	{
		health -= damage;
		cout << "남은 체력 : " << health << endl;
		cout << "네 주세요.." << endl;
	}
};

class Student6 : public Monster
{
public:
	Student6() : Monster("장재근 학생") {}


	string getName()
	{
		name = "장재근 학생";
		return name;
	}
	int getAttack()
	{
		attack = 20;
		return attack;
	}
	int getHealth()
	{
		health = 500;
		return health;
	}
	void takeDamage(int damage)
	{
		health -= damage;
		cout << "남은 체력 : " << health << endl;
		cout << "과제 더 주세요! 성장하고 싶어요!" << endl;
	}
};

int main()
{
	Student1 s1;
	s1.getHealth();
	s1.takeDamage(10);
	
	return 0;
}