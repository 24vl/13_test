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
	
	void levelUp()//������
	{
		if (level < 10 && experience >= 100)//AND ����
		{
			level += experience / 100; //���� ����
			experience = experience % 100;//���� ����ġ 

			cout << "������ �ϼ̽��ϴ�!" << endl;
			cout << "���緹��:" << level << endl;
			cout << "====================================================================" << endl;
		}
			else if (experience > 101)
			{
			experience = 100;
				
			}

		if (level > 10) //���� ����
		{
			level = 10;
		}

		maxHealth = maxHealth + 20;	// �ִ� ü�� ����
		health = maxHealth;			// ü�� ȸ��
		attack = attack + 5;		// ���ݷ� ����
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
		cout << cmd << "���� ���� Hp:" << health << endl;
	}

	void displayStatus()
	{
		cout << "�̸�:" << cmd << endl;
		cout << "����:���߳뿹" << endl;
		cout << "����:" << level << endl;
		cout << "Exp:" << experience << "/100"<<endl;
		cout << "ü��:" << health << '/' << maxHealth << endl;
		cout << "���ݷ�" << attack << endl;
		cout << "���:" << gold << endl;
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

