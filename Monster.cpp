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

bool Student1::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
		return true;
	}
	else
	{
		cout << "���� ü�� : " << health << endl;
		cout << "����! ���� �׸�!" << endl;
		return false;
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

bool Student2::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
		return true;
	}
	else
	{
		cout << "���� ü�� : " << health << endl;
		cout << "���� ������ �� �ֽô°ǰ���?" << endl;
		return false;
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
bool Student3::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
		return true;
	}
	else
	{
		cout << "���� ü�� : " << health << endl;
		cout << "����.. ����.. ������.." << endl;
		return false;
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
bool Student4::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
		return true;
	}
	else
	{
		cout << "���� ü�� : " << health << endl;
		cout << "����.. �ؾ���.. �׷���.." << endl;
		return false;
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
bool Student5::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
		return true;
	}
	else
	{
		cout << "���� ü�� : " << health << endl;
		cout << "��.. �� �𸣰����� �غ��ڽ��ϴ�.." << endl;
		return false;
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
bool Student6::takeDamage(int damage)
{
	health -= damage;

	if (health < 0)
	{
		health = 0;
		cout << name << "�� ������ �׿� ���������ϴ�." << endl;
		return true;
	}
	else
	{
		cout << "���� ü�� : " << health << endl;
		cout << "�� �߽��ϴ�! ���� �� �ֽǰǰ���?" << endl;
		return false;
	}
}