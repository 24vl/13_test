#ifndef Shop_H_ 
#define Shop_H_

#include "GameManager.h"
#include "Character.h"
#include "Item.h"
#include <vector>

class Shop
{
private:

public:
	Shop();
	void displayItems();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);
	~Shop();
};


#endif

