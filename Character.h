class Character
{
protected:

	string name;
	int level;
	int health;
	int maxHealth;
	int attack;
	int experience;
	int gold;
	vector<item*>Inventory;

public:

	Character(string n = " ") : name(n) {};


	void displayStatus()
	{
	}

	void levelUp()
	{

	}

	void useitem(int index)
	{

	}

	int getlevel()
	{

		return level;
	}

	void setlevel(int newlevel)
	{

		level = newlevel;
	}


	int getmaxHealth()
	{
		return maxHealth;
	}

	void setmaxHealth(int newmaxHealth)
	{
		maxHealth = newmaxHealth;

	}

	int gethealth()
	{
		return health;
	}

	void sethealth(int newhealth)
	{
		health = newhealth;

	}

	int getattack()
	{
		return attack;
	}

	void setattack(int newattack)
	{
		attack = newattack;
	}

	int getexperience()
	{
		return experience;
	}

	void setexperience(int newexperience)
	{
		experience = newexperience;
	}

	int getgold()
	{
		return gold;
	}

	void setgold(int newgold)
	{
		gold = newgold;
	}





	~Character(){}
};