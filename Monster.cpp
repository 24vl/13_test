﻿#include "Monster.h"


//--- Student1
string Student1::getName()
{
	return name;
}
int Student1::getAttack()
{
	return attack;
}
int Student1::getHealth()
{
	return health;
}
void Student1::takeDamage(int damage)
{
	health -= damage;
	cout << "남은 체력 : " << health << endl;
	cout << "으악! 과제 그만!" << endl;
}
void Student1::checkDead()
{
	if (health <= 0)
	{
		cout << name << "님이 내배캠을 탈주하였습니다." << endl;
	}
}

//--- Student2
string Student2::getName()
{
	return name;
}
int Student2::getAttack()
{
	return attack;
}
int Student2::getHealth()
{
	return health;
}
void Student2::takeDamage(int damage)
{
	health -= damage;
	cout << "남은 체력 : " << health << endl;
	cout << "흑흑 과제 그만주세요..." << endl;
}
void Student2::checkDead()
{
	if (health <= 0)
	{
		cout << name << "님이 내배캠을 탈주하였습니다." << endl;
	}
}


//--- Student3
string Student3::getName()
{
	return name;
}
int Student3::getAttack()
{
	return attack;
}
int Student3::getHealth()
{
	return health;
}
void Student3::takeDamage(int damage)
{
	health -= damage;
	cout << "남은 체력 : " << health << endl;
	cout << "아.. 하하.. 하하.." << endl;
}
void Student3::checkDead()
{
	if (health <= 0)
	{
		cout << name << "님이 내배캠을 탈주하였습니다." << endl;
	}
}


//--- Student4::
string Student4::getName()
{
	return name;
}
int Student4::getAttack()
{
	return attack;
}
int Student4::getHealth()
{
	return health;
}
void Student4::takeDamage(int damage)
{
	health -= damage;
	cout << "남은 체력 : " << health << endl;
	cout << "어.. 해보겠습니다.." << endl;
}
void Student4::checkDead()
{
	if (health <= 0)
	{
		cout << name << "님이 내배캠을 탈주하였습니다." << endl;
	}
}


//--- Student5
string Student5::getName()
{
	return name;
}
int Student5::getAttack()
{
	return attack;
}
int Student5::getHealth()
{
	return health;
}
void Student5::takeDamage(int damage)
{
	health -= damage;
	cout << "남은 체력 : " << health << endl;
	cout << "네 주세요.." << endl;
}
void Student5::checkDead()
{
	if (health <= 0)
	{
		cout << name << "님이 내배캠을 탈주하였습니다." << endl;
	}
}


//--- Student6
string Student6::getName()
{
	return name;
}
int Student6::getAttack()
{
	return attack;
}
int Student6::getHealth()
{
	return health;
}
void Student6::takeDamage(int damage)
{
	health -= damage;
	cout << "남은 체력 : " << health << endl;
	cout << "과제 더 주세요! 성장하고 싶어요!" << endl;
}
void Student6::checkDead()
{
	if (health <= 0)
	{
		cout << name << "님이 내배캠을 탈주하였습니다." << endl;
	}
}
