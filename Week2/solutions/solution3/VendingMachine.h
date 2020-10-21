#pragma once
#include <stack>
#include <vector>
#include "Item.h"

class VendingMachine
{
private:
	std::stack<Item*> slotCola;
	std::stack<Item*> slotWater;
	std::stack<Item*> slotCroissant;
	std::stack<Item*> slotBakeRolls;
public:
	bool hasEmpty() const;
	void addItem(const short slotNumber, const Item& item);
	Item* consume(const short slotNumber);
	~VendingMachine();
};
