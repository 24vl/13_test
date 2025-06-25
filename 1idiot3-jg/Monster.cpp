#include "Monster.h"

//--- Student1 / 성준모 학생
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
bool Student1::takeDamage(int damage) // Character.getAttack();
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
	cout << "공격력 : " << getAttack() << "   / 체력 : " << getHealth() << endl;
}

void Student1::skillMonster()
{
	cout << "반항하기!" << endl;
	cout << attack << "데미지를 주었습니다.\n" << endl;

}


//--- Student2 / 김지원 학생
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
		cout << "\"흑흑 과제를 또 주시는건가요?\"" << endl;
		return false;
	}
}

void Student2::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 체력 : " << getHealth() << endl;
}

void Student2::skillMonster()
{
	cout << "반항하기!" << endl;
	cout << attack << "데미지를 주었습니다.\n" << endl;

}

//--- Student3 / 김성빈 학생
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
		cout << "\"하하.. 하하.. 과제다..\"" << endl;
		return false;
	}
}

void Student3::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 체력 : " << getHealth() << endl;
}

void Student3::skillMonster()
{
	cout << "반항하기!" << endl;
	cout << attack << "데미지를 주었습니다.\n" << endl;

}

//--- Student4 / 최선호 학생
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
		cout << "\"과제.. 해야죠.. 그럼요..\"" << endl;
		return false;
	}
}

void Student4::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 체력 : " << getHealth() << endl;
}

void Student4::skillMonster()
{
	cout << "반항하기!" << endl;
	cout << attack << "데미지를 주었습니다.\n" << endl;

}

//--- Student5 / 전형준 학생
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
		cout << "\"어.. 잘 모르겠지만 해보겠습니다..\"" << endl;
		return false;
	}
}

void Student5::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 체력 : " << getHealth() << endl;
}

void Student5::skillMonster()
{
	cout << "반항하기!" << endl;
	cout << attack << "데미지를 주었습니다.\n" << endl;

}

//--- Student6 / 장재근 학생
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
		cout << "\"다 했습니다! 과제 더 주실건가요?\"" << endl;
		return false;
	}
}

void Student6::displayStatus()
{
	cout << "- " << getName() << " -" << endl;
	cout << "공격력 : " << getAttack() << "   / 체력 : " << getHealth() << endl;
}

void Student6::skillMonster()
{
	cout << "반항하기!" << endl;

	cout << attack << "데미지를 받았습니다.\n" << endl;

}