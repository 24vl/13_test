#include "Monster.h"


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

	if (health < 0)
	{
		health = 0;
	}

	cout << "���� ü�� : " << health << endl;
	cout << "����! ���� �׸�!" << endl;
}
void Student1::checkDead()
{
	if (health <= 0)
	{
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
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

	if (health < 0)
	{
		health = 0;
	}

	cout << "���� ü�� : " << health << endl;
	cout << "���� ������ �� �ֽô°ǰ���?" << endl;
}
void Student2::checkDead()
{
	if (health <= 0)
	{
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
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

	if (health < 0)
	{
		health = 0;
	}

	cout << "���� ü�� : " << health << endl;
	cout << "����.. ����.. ������.." << endl;
}
void Student3::checkDead()
{
	if (health <= 0)
	{
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
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

	if (health < 0)
	{
		health = 0;
	}

	cout << "���� ü�� : " << health << endl;
	cout << "����.. �ؾ���.. �׷���.." << endl;
}
void Student4::checkDead()
{
	if (health <= 0)
	{
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
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

	if (health < 0)
	{
		health = 0;
	}

	cout << "���� ü�� : " << health << endl;
	cout << "��.. �� �𸣰����� �غ��ڽ��ϴ�.." << endl;
}
void Student5::checkDead()
{
	if (health <= 0)
	{
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
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

	if (health < 0)
	{
		health = 0;
	}

	cout << "���� ü�� : " << health << endl;
	cout << "�� �߽��ϴ�! ���� �� �ֽǰǰ���?" << endl;
}
void Student6::checkDead()
{
	if (health <= 0)
	{
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
	}
}