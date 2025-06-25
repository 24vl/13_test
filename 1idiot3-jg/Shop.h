#ifndef Shop_H_ 
#define Shop_H_


#include "Character.h"
#include "Item.h"

class Shop
{
private:
	vector<Item*> availableItems;

public:
	Shop();
	void displayItems();
	void buyItem(int index, Character* player);
	void sellItem(int index, Character* player);
	~Shop();
};


#endif

