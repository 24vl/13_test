#ifndef Moster_H_
#define Moster_H_

#include <iostream>
#include <string>

class Monster
{
protected:
	std::string name;
	int attack;
	int health;

public:
	Monster(std::string name, int attack, int health) : name(name), attack(attack), health(health) {}
	std::string getName();
	int getAttack();
	int getHealth();
	void displayStatus();
	virtual bool takeDamage(int damage) = 0;
	virtual void skillMonster() = 0;
};

class Student1 : public Monster
{
public:
	Student1() : Monster("성준모 학생", 20, 140) {}
	bool takeDamage(int damage);
	void skillMonster();
};

class Student2 : public Monster
{
public:
	Student2() : Monster("김지원 학생", 40, 100) {}
	bool takeDamage(int damage);
	void skillMonster();
};

class Student3 : public Monster
{
public:
	Student3() : Monster("김성빈 학생", 60, 140) {}
	bool takeDamage(int damage);
	void skillMonster();
};

class Student4 : public Monster
{
public:
	Student4() : Monster("최선호 학생", 40, 200) {}
	bool takeDamage(int damage);
	void skillMonster();
};

class Student5 : public Monster
{
public:
	Student5() : Monster("전형준 학생", 80, 300) {}
	bool takeDamage(int damage);
	void skillMonster();
};

class Student6 : public Monster
{
public:
	Student6() : Monster("장재근 학생", 60, 400) {}
	bool takeDamage(int damage);
	void skillMonster();
};

class Boss : public Monster
{
public:
	Boss() : Monster("실험체 '멍청멍청'", 100, 800) {}
	bool takeDamage(int damage);
	void skillMonster();
};

#endif