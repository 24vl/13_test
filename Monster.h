#ifndef Moster_H_
#define Moster_H_


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
	Monster(string name, int attack, int health) : name(name), attack(attack), health(health) {}
	virtual string getName() = 0;
	virtual int getAttack() = 0;
	virtual int getHealth() = 0;
	virtual void takeDamage(int damage) = 0;
	virtual void checkDead() = 0;
};

class Student1 : public Monster
{
public:
	Student1() : Monster("���ظ� �л�", 5, 20) {}
	string getName();
	int getAttack();
	int getHealth();
	void takeDamage(int damage);
	void checkDead();
};

class Student2 : public Monster
{
public:
	Student2() : Monster("������ �л�", 5, 20) {}
	string getName();
	int getAttack();
	int getHealth();
	void takeDamage(int damage);
	void checkDead();

};

class Student3 : public Monster
{
public:
	Student3() : Monster("�輺�� �л�", 10, 40) {}
	string getName();
	int getAttack();
	int getHealth();
	void takeDamage(int damage);
	void checkDead();

};

class Student4 : public Monster
{
public:
	Student4() : Monster("�ּ�ȣ �л�", 15, 60) {}
	string getName();
	int getAttack();
	int getHealth();
	void takeDamage(int damage);
	void checkDead();

};

class Student5 : public Monster
{
public:
	Student5() : Monster("������ �л�", 15, 60) {}
	string getName();
	int getAttack();
	int getHealth();
	void takeDamage(int damage);
	void checkDead();

};

class Student6 : public Monster
{
public:
	Student6() : Monster("����� �л�", 20, 500) {}
	string getName();
	int getAttack();
	int getHealth();
	void takeDamage(int damage);
	void checkDead();

};

#endif

//cmath   pow() ��� X ȿ���� ������