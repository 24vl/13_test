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
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"으악! 과제 그만!\"" << endl;
		return false;
	}
}

void Student1::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 남은 체력 : " << getHealth() << endl;
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
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"으악! 과제 그만!\"" << endl;
		return false;
	}
}

void Student2::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 남은 체력 : " << getHealth() << endl;
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
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"으악! 과제 그만!\"" << endl;
		return false;
	}
}

void Student3::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 남은 체력 : " << getHealth() << endl;
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
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"으악! 과제 그만!\"" << endl;
		return false;
	}
}

void Student4::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 남은 체력 : " << getHealth() << endl;
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
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"으악! 과제 그만!\"" << endl;
		return false;
	}
}

void Student5::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 남은 체력 : " << getHealth() << endl;
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
		cout << name << "이 과제에 쌓여 쓰러졌습니다.\n" << endl;
		return true;
	}
	else
	{
		displayStatus();
		cout << "\"으악! 과제 그만!\"" << endl;
		return false;
	}
}

void Student6::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 남은 체력 : " << getHealth() << endl;
}
