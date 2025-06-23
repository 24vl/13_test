#ifndef FUNCTION_H_
#define FUNCTION_H_

#include"GameManager.h"
#include <string>
#include<iostream>

using namespace std;

class Character
{


private:

	
	string cmd;
	int level = 1;
	int health = 200;
	int maxHealth = 200;
	int attack = 30;
	int experience = 0;
	int gold = 0;
	//vector<item*> inventory;
public:

	Character()
	{
		
	}


	~Character()
	{

	}
	
	void levelUp()//레벨업
	{
		if (level < 10 && experience >= 100)//AND 조건
		{
			level += experience / 100; //레벨 증가
			experience = experience % 100;//남은 경험치 

			cout << "레벨업 하셨습니다!" << endl;
			cout << "현재레벨:" << level << endl;
			cout << "====================================================================" << endl;
		}
			else if (experience > 101)
			{
			experience = 100;
				
			}

		if (level > 10) //레벨 제한
		{
			level = 10;
		}

		maxHealth = maxHealth + 20;	// 최대 체력 증가
		health = maxHealth;			// 체력 회복
		attack = attack + 5;		// 공격력 증가
	}

	void setMaxHealth(int newMaxHealth)
	{
		this->maxHealth = newMaxHealth;
	}

	void setHealth(int newHealth)
	{
		this->health = newHealth;
	}
	
	void setName(string name)
	{
		cmd = name;
	}
	void setGold(int g)
	{
		gold = g;
	}
	void setExperience(int e)
	{
		experience < 101;
		experience = e;
	}

	void setLevel(int l)
	{
		level < 11;
		level = l;
	}
	void damage(int hit)
	{
		health -= hit;
		cout << cmd << "님의 남은 Hp:" << health << endl;
	}

	void displayStatus()
	{
		cout << "이름:" << cmd << endl;
		cout << "직업:개발노예" << endl;
		cout << "레벨:" << level << endl;
		cout << "Exp:" << experience << "/100"<<endl;
		cout << "체력:" << health << '/' << maxHealth << endl;
		cout << "공격력" << attack << endl;
		cout << "골드:" << gold << endl;
	}
	int getmaxHealth()
	{
		return maxHealth;
	}

	int getHealth()
	{
		return health;
	}

	int getExperience()
	{
		experience < 101;
		return experience;
	}
	int getLevel()
	{
		level < 11;
		return level;
	}
	int getGold()
	{
		return gold;
	}
	string getName()
	{
		return cmd;
	}


		


	
};


#endif CHARACTER_H_

